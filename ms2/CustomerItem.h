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
	void fill(const unsigned int);
	void clear();
	void display(std::ostream&) const;

	bool asksFor(const Item&) const { return !name.empty(); }
	bool isFilled() const { return filled; }
	const std::string& getName() const { return name; }


};

