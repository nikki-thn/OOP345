#pragma once
// CustomerOrder Milestone - Item Interface
// Item.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

const unsigned int CODE_WIDTH = 5;

class Item {

	std::string name;          // name of the component
	std::string filler;        // name of the filler task
	std::string remover;       // name of the remover task 
	std::string description;   // detailed description
	unsigned int code;         // next shipping label
	static size_t field_width; // current maximum field width

public:

	// One argument constructor
	Item(const std::string& = std::string());

	// Display an item to ostream
	void display(std::ostream&, bool = false) const;

	// Increment and item code by one
	Item& operator++(int);
	
	/*! \return true if name is empty */
	bool empty() const { return name.empty(); }
	
	/*! \return code member */
	unsigned int getCode() const { return code; }
	
	/*! \return name member */
	const std::string& getName() const { return name; }
	
	/*! \return filler member */
	const std::string& getFiller() const { return filler; }
	
	/*! \retturn remover member */ 
	const std::string& getRemover() const { return remover; }
	
};
