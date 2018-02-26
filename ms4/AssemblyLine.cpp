#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "AssemblyLine.h"
#include "ItemManager.h"
#include "OrderManager.h"
#include "Item.h"
#include "Processor.h"
#include "Task.h"

void AssemblyLine::push_back(Processor&& p) {

	//???emplace+bacl vs push_back
	emplace_back(std::move(p));
}

void AssemblyLine::validate(std::ostream& os) {

	//iterrate though processor which is based on Task
	for (auto& process : *this) {
		bool validated = false;

		for (auto& toValidateProcess : *this) {
			if (process.getName() != toValidateProcess.getName()) {
				validated = process.validate(toValidateProcess);
			}
		}
		if (!validated) {
			os << "The task " << process.getName() << " is not validated." << std::endl;
		}
	}
}

void AssemblyLine::display(std::ostream& os) const {
	for (auto processor : *this) {
		processor.display(os);
	}
}

/*
void AssemblyLine::validate
checks that the tasks (that is, processors) assigned to each item managed by
itemManager are tasks (that is, processors) in the base class container.
If a task is not in the container, then this function inserts a message into
os that that task is not available.
*/

void AssemblyLine::validate(ItemManager& itemManager, std::ostream& os) {

	//iterate through itemManager

	for (auto& processor : *this) {

		auto pos = std::find_if(std::begin(itemManager), std::end(itemManager),
			[&, this](Item& item) { return processor.getName() == item.getName(); });

		if (pos >= std::end(itemManager)) {
			os << processor.getName() << " is  not available" << std::endl;
		}
	}
}


void AssemblyLine::loadItem(ItemManager& itemManager) {

	//Iterate through each task, and load each task
	//with the pointer to the item it processes
	for (auto& processor : *this) {
		bool isFilled = false;

		for (auto& item : itemManager) {
			if (processor.getName() == item.getFiller()) {
				item.getFiller() == processor.getName();
				isFilled = true;
			}
	
			processor.load(item);
		}
	}
}

/*
moves the customer orders managed by orderManager to the assembly line's entryProcessor.  */
void AssemblyLine::loadOrders(OrderManager& orderManager, const std::string& entryProcessor, std::ostream& os) {

	//auto isFound = std::find_if(std::begin(*this), std::end(*this), 
	//	[&](Processor p) { 
	//	
	//	if (isFound >= std::end(*this)) {
	//		push_back(entryProcessor);
	//	}

	//	return p.getName() == entryProcessor;
	//
	//});

	//Iterate through the Processors, to find the starting point.
	auto starting_point_found = std::find_if(begin(), end(),
		[&](Processor p) {return p.getName() == entryProcessor; });
	if (starting_point_found != end()) {
		while (!orderManager.empty()) {
			std::unique_ptr<CustomerOrder> order(new CustomerOrder(std::move(orderManager.extract())));
			starting_point_found->accept(std::move(*order));
			orderManager.pop_back();
		}
	}
}


bool AssemblyLine::process(OrderManager& om, unsigned int pause) {
	bool not_done = false;
	for (unsigned int step = 0; step < pause; step++) {
		//Advance each processor by one step
		for (auto& p : *this) {
			p.advance();
		}
		//Check if each processor is ready to ship or ready to pass

		for (auto& p : *this) {
			if (p.readyToShip()) {
				p.ship(om);
			}
			else if (p.readyToPass()) {
				srand(time(NULL));
				int inspection_score = rand() % 101;
				p.pass(inspection_score);
			}
		}
		size_t active_processors = size();
		//Check if all processors are empty, decreasing each active processor count by one if an empty processor is found
		//if there are 0 active processors left, then set done to true, and the simulation is done.

		for (auto& p : *this) {
			if (p.empty()) { --active_processors; }
		}
		if (active_processors == 0) { return true; }
		// std::cout << std::setw(50) << std::setfill('=') << '=' << std::setfill('\0') << std::setw(0) << std::endl;
	}
	return not_done;
}