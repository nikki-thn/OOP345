/*! *********************************************************
* OOP345 Milestone 1: Tasks
* File: Tasks.cpp
* \date March 15, 2018
* \author Nikki Truong - 112 314 174
***********************************************************/

#include<iostream>
#include <iomanip>
#include <vector>
#include "Task.h"

size_t Task::field_width = 0;
const int MAX_TOKEN = 4;

/*! One parameter Constructor: The constructor takes in a single record with
components to be processed
*/
Task::Task(const std::string& record_) {

	//Initializing data members to safety state
	name = "";
	slots = "1";
	nextTask[passed] = "";
	nextTask[redirect] = "";
	pNextTask[passed] = nullptr;
	pNextTask[redirect] = nullptr;

	//Use Utilities class to seperate the components
	Utilities exactToken;
	
	//Placeholder and flag variables to be used during extraction
	std::string temp;
	size_t pos = 0;
	bool more = true;
	std::vector<std::string> tokens(MAX_TOKEN); //stores all available tokens

	//assign tokens to temp vector for validation
	for (size_t i = 0; i < 4 && more; i++) {
		temp = exactToken.nextToken(record_, pos, more);
		if (temp != "") tokens[i] = temp;	
	}

	//Trim white space from each components
	for (auto& i : tokens) {
		size_t first = i.find_first_not_of(' ');
		i.erase(0, first);
		size_t last = i.find_last_not_of(' ');
		i.erase(last + 1);
	}

	if (tokens[0] != "") {
		name = tokens[0]; 
		//update the current object's field_width if its current
		// value is less than the size of the token extracted.
		if (field_width < exactToken.getFieldWidth()) {
			field_width = exactToken.getFieldWidth();
		}
	}
	//throw exception if fields missing
	else throw std::string(record_) + std::string("*** no token found before the delimiter ***");

	//assign each component to data member
	if (tokens[1] != "") slots = tokens[1];
	if (tokens[2] != "") nextTask[passed] = tokens[2];
	if (tokens[3] != "") nextTask[redirect] = tokens[3];
}

/*! Validate a Task and returns true if it is valid*/
bool Task::validate(const Task& task) {

	bool isValid = false;

	if (nextTask[passed] == task.getName()) {
		pNextTask[passed] = &task;
	}
	else if (nextTask[redirect] == task.getName()) {
		pNextTask[redirect] = &task;
	}
	if ((nextTask[passed].empty() || pNextTask[passed] != nullptr)
		&& (nextTask[redirect].empty() || pNextTask[redirect] != nullptr)) {
		isValid = true;
	}
	
	//\return true is a Task is valid
	return isValid;
}

/*! Functions return the pointer to the next task based on the parameter */
const Task* Task::getNextTask(Quality quantity) const {
	int index = -1;

	if (quantity == passed) index = passed;
	else if (quantity == redirect) index = redirect;

	if (pNextTask[passed] == nullptr) {

		throw std::string("*** Validate [" + nextTask[passed] +
			"] @ [" + name + "] ***");
	}

	return pNextTask[index];
}

/*! Function display each task in a specified format */
void Task::display(std::ostream& os) const {
	os.setf(std::ios::left);

	if (pNextTask[passed] != nullptr) {

		os << "Task Name      :  " << std::setw(field_width + 3) << "[" + name + "]" << "[" << slots + "]" << std::endl;
		os << "  Continue to  :  " << std::setw(field_width + 3) << "[" + nextTask[passed] + "]" << std::endl;
		if (nextTask[redirect] != "") {
			os << "  Redirect to  :  " << std::setw(field_width + 3) << "[" + nextTask[redirect] + "]" << std::endl;
		}
	}
	else {

		if (nextTask[passed] == "") {
			os << "Task Name      :  " << std::setw(field_width + 3) << "[" + name + "]" << "[" << slots << "]" << std::endl;
		}
		else {
			os << "Task Name      :  " << std::setw(field_width + 3) << "[" + name + "]" << "[" << slots + "]" << std::endl;
			os << "  Continue to  :  " << std::setw(field_width + 3) << "[" + nextTask[passed] + "]" << "*** to be validated ***" << std::endl;

			if (nextTask[redirect] != "") {
				os << "  Redirect to  :  " << std::setw(field_width + 3) << "[" + nextTask[redirect] + "]" << "*** to be validated ***" << std::endl;
			}
		}

		os.setf(std::ios::left);
	}


}




//https://stackoverflow.com/questions/25829143/trim-whitespace-from-a-string
