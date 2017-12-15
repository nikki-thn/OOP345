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

	//constructor
	Item(const std::string& = std::string());

	//print item os os
	void display(std::ostream&, bool full = false) const;

	//increment code by one
	int operator++(int) { return code++; }

	//return true if object is empty
	bool empty() const { return name.empty(); }

	//return code
	unsigned int getCode() const { return code; }

	//return component name
	const std::string& getName() const { return name; }
	
	//return filler
	const std::string& getFiller() const { return filler; }
	
	//return remover
	const std::string& getRemover() const { return remover; }
	

};