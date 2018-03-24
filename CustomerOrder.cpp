#include <iostream>
#include <string>
#include <vector>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Item.h"
#include "Utilities.h"

size_t CustomerOrder::field_width;

/*! One parameter Constructor
* \param string: record to be break down
*/
CustomerOrder::CustomerOrder(const std::string& record_) {

	std::string record = record_;

	//intializing
	order = nullptr;
	nOrders = 0;    

	//if record is not empty, read in
	if (!record_.empty()) {

		Utilities exactToken;
		std::string temp;
		size_t pos = 0;
		bool more = true;
		std::vector<std::string> tokens; //stores all available tokens

		int validRecs = 0;

		//extract using Utilities
		while (more) {
			temp = exactToken.nextToken(record_, pos, more);
			if (!temp.empty()) tokens.push_back(temp);
			if (temp.length() > 1) validRecs++;
		}

		nOrders = validRecs - 2;

		if (tokens.size() > 2) {
			if (!tokens[0].empty()) {
				name = tokens[0];
				if (field_width < tokens[0].length()) field_width = tokens[0].length();
			}
			//throw exception if first component is missing
			//else throw record + std::string("<-- *** no token found before the delimiter ***");

			if (!tokens[1].empty()) product = tokens[1];
			//throw exception if second component is missing
			else throw record_ + "<-- *** no token found before the delimiter ***";

			order = new CustomerItem[nOrders];
			for (size_t i = 0; i < nOrders; i++) {
				order[i] = CustomerItem(tokens[i + 2]);
				//order[i].setCode()
			}
		}
		//throw exception if record is less then 3 components (invalid rec)
		//else throw record_ + std::string("<-- *** no token found before the delimiter ***");
	}
}

/*! Move Constructor */
CustomerOrder::CustomerOrder(CustomerOrder&& order_) NOEXCEPT {

	if (this != &order_) {

		//shallow copy
		name = order_.name;
		product = order_.product;
		nOrders = order_.nOrders;
		order = order_.order;

		//clean up old object
		order_.name.clear();
		order_.product.clear();
		order_.order = nullptr;
		order_.nOrders = 0;
	}
}

/*! Move Assignment */
CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& order_) NOEXCEPT {

	if (this != &order_) {

		//shallow copy
		name = order_.name;
		product = order_.product;
		nOrders = order_.nOrders;
		order = order_.order;

		//clean up old object
		order_.name.clear();
		order_.product.clear();
		order_.order = nullptr;
		order_.nOrders = 0;
	}
	return std::move(*this);
}

/*! Destructor */
CustomerOrder::~CustomerOrder()
{
	//clean up memory
	delete[] order;
}

/*! Overload operator [] 
* \return name of the order at index passed by parameter
*/
const std::string& CustomerOrder::operator[](unsigned int index_) const
{
	int index = 0;
	if (index_ <= nOrders) {
		index = index_;
	}
	//throw exception
	else throw "Index is out of bound";

	return order[index].getName();
}

/*! function check an item from the customer if it is filled*/
void CustomerOrder::fill(Item& item_) {

	for (size_t i = 0; i < nOrders; i++) {
		if (order[i].asksFor(item_)){
			if (!order[i].isFilled()) {
				order[i].fill(item_.getCode());
				item_++;
			}
		}
	}
}

/*! remove an item from a customer order*/
void CustomerOrder::remove(Item& item)
{
	for (size_t i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			nOrders--;
		}
	}
}

/*! function display a customer order to ostream */
void CustomerOrder::display(std::ostream& os) const {

	os.width(field_width);
	os.fill(' ');
	os.setf(std::ios::left);
	os << name << " :  " << product << std::endl;
	os.unsetf(std::ios::left);

	for (unsigned int i = 0; i < nOrders; i++)
		order[i].display(os);
}
