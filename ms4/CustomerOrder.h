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
	CustomerOrder(const CustomerOrder&) = default;

	CustomerOrder& operator=(const CustomerOrder&) = default;
	CustomerOrder(CustomerOrder&&) NOEXCEPT;
	CustomerOrder&& operator=(CustomerOrder&&) NOEXCEPT;
	~CustomerOrder();

	const std::string& operator[](unsigned int) const;
	void fill(Item&);
	void remove(Item&);
	void display(std::ostream&) const;

	unsigned int noOrders() const { return nOrders; }
	bool empty() const { return name.empty(); }
};