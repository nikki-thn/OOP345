#pragma once
// Task Milestone - Task Interface
// Task.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <iostream>
#include "Utilities.h"
#include "stdlib.h"

class Task {

	std::string name;          // name of the task
	std::string slots;         // number of slots
	std::string nextTask[2];   // names of the next tasks
	const Task* pNextTask[2];  // addresses of the next tasks
	static size_t field_width; // current maximum field width 

public:

	enum Quality { passed, redirect };

	//constructor
	Task(const std::string&);

	//return number of slots by cast down to int
	unsigned int getSlots() const {	return atoi(slots.c_str()); }

	//returns the field width currently stored for all objects in this class
	static size_t getFieldWidth() { return field_width; }

	//return name of current object
	const std::string& getName() const { return name; }

	bool validate(const Task&);
	const Task* getNextTask(Quality) const;
	void display(std::ostream&) const;
};

//retruns true if task a and b has same name
static bool operator==(const Task& a, const Task& b) { return a.getName().compare(b.getName()) == 0; }
