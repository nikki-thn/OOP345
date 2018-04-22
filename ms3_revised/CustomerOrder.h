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

	//One argument Constructor
	CustomerOrder(const std::string&);

	/*! Restrict Copy Constructor */
	CustomerOrder(const CustomerOrder&) = delete;

	/*! Restrict Copy Assignment */
	CustomerOrder& operator=(const CustomerOrder&) = delete;

	// Move constructor
	CustomerOrder(CustomerOrder&&) NOEXCEPT;

	// Move Assignment
	CustomerOrder&& operator=(CustomerOrder&&) NOEXCEPT;

	// Destructor
	~CustomerOrder();

	// Overload operator []
	const std::string& operator[](unsigned int) const;

	// Function will fill an item in the customer order
	void fill(Item&);

	// Function will remove an item from a customer order
	void remove(Item&);

	//Function will display a customer order to ostream
	void display(std::ostream&) const;

	/*! \return nOrders */
	unsigned int noOrders() const { return nOrders; }

	/*! \return true if name is empty */
	bool empty() const { return name.empty(); }
};
