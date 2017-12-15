#pragma once
// CustomerOrder Milestone - CustomerOrder Interface
// CustomerOrder.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>
#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class Item;
class CustomerItem;

class CustomerOrder {

	std::string name;          // name of the customer
	std::string product;       // name of the product
	CustomerItem* order;       // address of the customer requests 
	unsigned int nOrders;      // number of requests
	static size_t field_width; // current maximum field width

public:

	CustomerOrder(const std::string&);
	CustomerOrder(const CustomerOrder&) = delete; //restrict copy

	CustomerOrder& operator=(const CustomerOrder&) = delete; //restrict copy
	CustomerOrder(CustomerOrder&&) NOEXCEPT;
	CustomerOrder&& operator=(CustomerOrder&&) NOEXCEPT;
	~CustomerOrder();

	//return the order at index parameter
	const std::string& operator[](unsigned int) const;
	
	//set fill status for order determined by parameter
	//increase item's code for each item filled
	void fill(Item&);

	//remove paramter item from items array 
	void remove(Item&);

	//display to os stream
	void display(std::ostream&) const;

	//return size of order array (num of items)
	unsigned int noOrders() const { return nOrders; }

	//returns true if object is empty
	bool empty() const { return name.empty(); }
};