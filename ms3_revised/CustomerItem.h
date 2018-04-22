#pragma once
// CustomerOrder Milestone - CustomerItem Interface
// CustomerItem.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include "Item.h"
#include <string>

class Item;

class CustomerItem {

	std::string name;  // name of the requested component 
	bool filled;       // status of the request
	unsigned int code; // unique shipping label

public:

	//One argument constructor
	CustomerItem(const std::string& = std::string());
	
	//fill item with the parameter
	void fill(const unsigned int);
	
	//clear item code
	void clear();
	
	//display to ostream
	void display(std::ostream&) const;
	
	//return boolean if an item is in the customer order
	bool asksFor(const Item& i) const;

	// return filled status
	bool isFilled() const;

	// return name 
	const std::string& getName() const;


};

