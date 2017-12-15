#pragma once
// CustomerOrder Milestone - CustomerItem Interface
// CustomerItem.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

class Item;

class CustomerItem {

	std::string name;  // name of the requested component 
	bool filled;       // status of the request
	unsigned int code; // unique shipping label

public:

	CustomerItem(const std::string& = std::string());

	//set the item code for the current object to parameter
	void fill(const unsigned int);

	//set item code to o and clear filled status
	void clear();

	//display to ostream
	void display(std::ostream&) const;

	//return true if the current object asks for item
	bool asksFor(const Item&) const { return !name.empty(); }

	//return true if the current object's request has been filled
	bool isFilled() const { return filled; }

	//return name of the request component
	const std::string& getName() const { return name; }


};

