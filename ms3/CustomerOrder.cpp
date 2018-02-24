#include <iostream>
#include <string>
#include <vector>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Item.h"
#include "Utilities.h"

size_t CustomerOrder::field_width;

CustomerOrder::CustomerOrder(const std::string& record_) {

	order = nullptr;
	nOrders = 0;    // number of requests

	Utilities exactToken;
	std::string temp;
	size_t pos = 0;
	bool more = true;
	std::vector<std::string> tokens; //stores all available tokens

	int validRecs = 0;

	while (more) {
		temp = exactToken.nextToken(record_, pos, more);
		if (!temp.empty()) tokens.push_back(temp);

		if (field_width < temp.length()) field_width = temp.length();

		if (temp.length() > 1) validRecs++;
	}

	nOrders = validRecs - 2;

	if (tokens.size() > 2) {
		if (!tokens[0].empty()) name = tokens[0];
		else throw std::string(record_ + "<-- *** no token found before the delimiter ***");

		if (!tokens[1].empty()) product = tokens[1];
		else throw  std::string(record_ + "<-- *** no token found before the delimiter ***");

		order = new CustomerItem[nOrders];
		for (size_t i = 0; i < nOrders; i++) {
			order[i] = CustomerItem(tokens[i + 2]);
		}
	}
	else throw std::string(record_ + "<-- *** no token found before the delimiter ***");
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

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& order_) NOEXCEPT {

	if (this != &order_) {

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

CustomerOrder::~CustomerOrder()
{
	delete[] order;
}

const std::string& CustomerOrder::operator[](unsigned int index_) const
{
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

void CustomerOrder::remove(Item& item)
{
	for (size_t i = 0; i < nOrders; i++)
	{
		if (order[i].getName() == item.getName())
		{
			nOrders--;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {

	os.width(field_width);
	os.fill(' ');
	os.setf(std::ios::left);
	os << name << " :  " << product << std::endl;
	os.unsetf(std::ios::left);
	
	for (unsigned int i = 0; i < nOrders; i++)
		order[i].display(os);
}
