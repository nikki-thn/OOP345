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

	//Constructor
	CustomerItem(const std::string& = std::string());

	// function set code to paramater value and filled status to true 
	void fill(const unsigned int);

	// function set code to 0 and filled status to false 
	void clear();

	// function display an item to ostream
	void display(std::ostream&) const;

	// return boolean if an item is in the customer order
	bool asksFor(const Item& i) const;

	// return filled status
	bool isFilled() const;

	// return name 
	const std::string& getName() const;


};

