#include <vector>
#include <iomanip>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"

size_t CustomerOrder::field_width = 0;
const int max_order = 6;

CustomerOrder::CustomerOrder(const std::string& record_) {
	order = nullptr;
	nOrders = 0;    // number of requests

	Utilities exactToken;
	std::string temp;
	size_t pos = 0;
	bool more = true;
	std::vector<std::string> tokens(max_order); //stores all available tokens

	for (size_t i = 0; i < max_order && more; i++) {
		temp = exactToken.nextToken(record_, pos, more);
		if (!temp.empty()) tokens[i] = temp;
	}

	int validRecs = 0;
	for (auto& i : tokens) {
		if (!i.empty()) {
			size_t first = i.find_first_not_of(' ');
			i.erase(0, first);
			size_t last = i.find_last_not_of(' ');
			i.erase(last + 1);
		}

	}

	for (auto& i : tokens) {
		if (!i.empty()) {
			if (field_width < i.length()) {
				field_width = i.length();
			}
			validRecs++;
		}
	}

	nOrders = validRecs - 2;

	if (!tokens[0].empty()) {
		name = tokens[0];
		//update the current object's field_width if its current
		// value is less than the size of the token extracted.

	}
	else throw std::string(record_) + std::string("*** record is missing customer name field ***");
	if (tokens[1] != "") product = tokens[1];
	else throw "Product name is missing";


	order = new CustomerItem[nOrders];
	for (size_t i = 0; i < nOrders; i++) {
		order[i] = CustomerItem(tokens[i + 2]);
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder& v) {
	//throw "Copy restricted"; 
}


CustomerOrder::CustomerOrder(CustomerOrder&& order_) NOEXCEPT {

	name = order_.name;
	product = order_.product;
	nOrders = order_.nOrders;
	order = new CustomerItem[nOrders];
	
	for (size_t i = 0; i < nOrders; i++) {
		order[i] = order_.order[i];
	}

	//clean up old object
	order_.name.clear();
	order_.product.clear();
	order_.order = nullptr;
	order_.nOrders = 0;

}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& order_ ) NOEXCEPT {
	
	if (this != &order_){

		name = order_.name;
		product = order_.product;
		nOrders = order_.nOrders;
		order = new CustomerItem[nOrders];

		for (size_t i = 0; i < nOrders; i++) {
			order[i] = order_.order[i];
		}

		//clean up old object
		order_.name.clear();
		order_.product.clear();
		order_.order = nullptr;
		order_.nOrders = 0;
	}

	return std::move(*this);
}


//CustomerOrder& CustomerOrder::operator=(const CustomerOrder& v) {
//	throw "Copy assignment is restricted";
//}
//
//CustomerOrder::CustomerOrder(const CustomerOrder& v) {
//	throw "Copy operator is restricted";
//}

CustomerOrder::~CustomerOrder() {
	//delete [] order; 
}

const std::string& CustomerOrder::operator[](unsigned int index_) const {
	int index = 0;
	if (index_ <= nOrders) {
		index = index_;
	}
	else throw "Index is out of bound";

	return order[index].getName();
}
void CustomerOrder::fill(Item& item_) {

	for (size_t i = 0; i < nOrders; i++)
	{
		if (order[i].asksFor(item_))
		{
			order[i].fill(item_.getCode());
			item_++;
		}
	}
}

void CustomerOrder::remove(Item& item_) {

	for (size_t i = 0; i < nOrders - 2; i++)
	{
		if (order[i].getName() == item_.getName())
		{
			nOrders--;
		}
	}
}
void CustomerOrder::display(std::ostream& os) const {
	os << std::setw(field_width) << os.fill(' ') << std::left << name << " :  " << product << std::endl;

	for (size_t i = 0; i < nOrders - 2; i++)
		order[i].display(os);
}
