#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
#include <memory>

#include "Processor.h"
#include "CustomerItem.h"
#include "CustomerOrder.h"
#include "OrderManager.h"
#include "Task.h"
#include "Item.h"


Processor::Processor(const std::string& record, std::function<Task::Quality(int)> lambda) :Task(record) {

	item_ = nullptr; //the item_ pointer to nullptr
	inspector = lambda; //the inspector pointer to the function received
	num_end_slots = getSlots(); //the num_end_slots to the number of slots in the processor
	is_a_filler = true; //the is_a_filler flag to true
}


void Processor::load(Item& item) {

	item_ = &item;
	is_a_filler = item.getName() == item.getFiller();
}


bool Processor::empty()const {

	return waiting.empty() && process.empty() && complete.empty();
}


void Processor::accept(CustomerOrder&& order) {

	waiting.push_back(std::move(order));
}

/*
void advance() - advances all customer orders attached to the processor
by a single slot.
This function decrements the number of end slots if 
the process queue is not empty and the number of end slots is not 0.

For every customer order in the process queue this function either fills
one customer item request with the item requested if the processor is a 
filler task or retreive the item if the process is remover task (not a filler). 

If there are no empty end slots, this function moves the order in the last slot
from the front of the process queue to the complete queue and adjusts the number
of end slots to either 1 or the number of slots in the processor if the process 
queue is empty. 

Finally, this function moves an order, if any, from the front
of the waiting queue to the back of the process queue 
*/

void Processor::advance() {

	if (!this->empty() && num_end_slots == 0) {
		num_end_slots--;
	}

	for (auto& custOrder : process) {

		if (is_a_filler) {
			custOrder.fill(*item_);
		}
		else {
			custOrder.remove(*item_);
		}
	}

	if (num_end_slots == 0) {
		complete.push_back(std::move(process.front()));

		if (process.empty()) {
			num_end_slots = getSlots();
		}
		else {
			num_end_slots = 1;
		}
	}

	process.push_back(std::move(waiting.front()));
}


bool Processor::readyToShip() const {
	return (!complete.empty() && (!getNextTask(Quality::passed) && !getNextTask(Quality::redirect)));
}


bool Processor::readyToPass() const {
	return (!complete.empty() && (getNextTask(Quality::passed) || getNextTask(Quality::redirect)));
}


//????????????????????????????
void Processor::pass(int score) {
	Task *t = nullptr;
	if (is_a_filler) {
		if (!getNextTask(Quality::redirect)) {
			t = const_cast<Task*>(getNextTask(Quality::passed));
		}
		else {
			Quality inspection_score = inspector(score);
			t = const_cast<Task*>(getNextTask(inspection_score));
		}
	}
	else {
		t = const_cast<Task*>(getNextTask(Quality::passed));
	}
	Processor *p = static_cast<Processor*>(t);
	std::unique_ptr<CustomerOrder> completed_order(new CustomerOrder(std::move(complete.front())));
	//complete.erase(complete.begin());
	p->accept(std::move(*completed_order));
}

void Processor::ship(OrderManager& finished) {

	if (!complete.empty()) {
		finished.push_back(std::move(complete.front()));
	}
}


void Processor::display(std::ostream& os) const {
	
	Task::display(os);

	std::cout << std::setw(Task::getFieldWidth() - 2) << "Item to add ";

	if (item_ && is_a_filler) {
		item_->display(os, false);
	}
	else {
		os << ":  ---" << std::endl;
	}
}

