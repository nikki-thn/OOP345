#include <vector>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"

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
		if (temp != "") tokens[i] = temp;
	}

	for (auto& i : tokens) {
		if (!i.empty()) {
			size_t first = i.find_first_not_of(' ');
			i.erase(0, first);
			size_t last = i.find_last_not_of(' ');
			i.erase(last + 1);
			nOrders++;
		}
	}

	if (tokens[0] != "") {
		name = tokens[0];
		//update the current object's field_width if its current
		// value is less than the size of the token extracted.
		if (field_width < exactToken.getFieldWidth()) {
			field_width = exactToken.getFieldWidth();
		}
	}
	else throw std::string(record_) + std::string("*** record is missing customer name field ***");

	order = new CustomerItem[nOrders - 2];


	if (tokens[1] != "") slots = tokens[1];
	else throw "Product name is missing";

	if (tokens[2] != "") nextTask[passed] = tokens[2];
	else

	if (tokens[3] != "") nextTask[redirect] = tokens[3];
	else 

	if (tokens[4] != "") nextTask[redirect] = tokens[3];
	if (tokens[5] != "") nextTask[redirect] = tokens[3];
}
CustomerOrder::CustomerOrder(const CustomerOrder&) {

}

CustomerOrder& CustomerOrder::operator=(const CustomerOrder&) {
	throw "Copy restricted";
}

const std::string& CustomerOrder::operator[](unsigned int) const {

}
void CustomerOrder::fill(Item&) {

}
void CustomerOrder::remove(Item&) {

}
void CustomerOrder::display(std::ostream&) const {

}
