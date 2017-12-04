#include<iostream>
#include <iomanip>
#include <vector>
#include "Task.h"

size_t Task::field_width = 0;

//contain a single record
Task::Task(const std::string& record_) {

	name = "";
	slots = "1";
	nextTask[passed] = "";
	nextTask[redirect] = "";
	pNextTask[passed] = nullptr;
	pNextTask[redirect] = nullptr;

	Utilities exactToken;
	std::string temp;
	size_t pos = 0;
	bool more = true;
	std::vector<std::string> tokens(4); //stores all available tokens

	for (size_t i = 0; i < 4 && more; i++) {
		temp = exactToken.nextToken(record_, pos, more);
		if (temp != "") tokens[i] = temp;	
	}

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
	else throw std::string(record_) + std::string("*** no token found before the delimiter ***");

	if (tokens[1] != "") slots = tokens[1];
	if (tokens[2] != "") nextTask[passed] = tokens[2];
	if (tokens[3] != "") nextTask[redirect] = tokens[3];
}

bool Task::validate(const Task& task) {

	bool isValid = false;

	if (task.getName() == nextTask[passed]) {
		pNextTask[passed] = &task;
	}
	else if (task.getName() == nextTask[redirect]) {
		pNextTask[redirect] = &task;
	}
	if ((nextTask[passed].empty() || pNextTask[passed] != nullptr)
		&& (nextTask[redirect].empty() || pNextTask[redirect])) {
		isValid = true;
	}
	
	return isValid;
}

const Task* Task::getNextTask(Quality quantity) const {
	int index = -1;

	if (quantity == passed) index = passed;
	else if (quantity == redirect) index = 1;

	if (pNextTask[passed] == nullptr) {

		throw std::string("*** Validate [" + nextTask[passed] +
			"] @ [" + name + "] ***");
	}
	return pNextTask[index];
}

void Task::display(std::ostream& os) const {
	//os.setf(std::ios::left);


	//	os << "Task Name   : [" << name << "] " << " [" << slots << "]" << std::endl;

	//	if (nextTask[passed] != "") {
	//		os << " Continue to: ["  << nextTask[passed] << "]";
	//		if (pNextTask[passed] == nullptr) os <<"*** to be validated ***" << std::endl;
	//		else os << std::endl;
	//	}
	//	if (nextTask[redirect] != "") {
	//		os << " Redirect to: " << "[" << nextTask[redirect] << "]" ;
	//		if (pNextTask[passed] == nullptr) os << "*** to be validated ***" << std::endl;
	//		else os << std::endl;
	//	}
	//
	
	if (pNextTask[passed] != nullptr) {
		os << "Task Name      :  " << std::setw(field_width + 3) << "[" + name + "]" << "[" + slots + "]" << std::endl;
		os << "  Continue to  :  " << std::setw(field_width + 3) << "[" + nextTask[passed] + "]" << std::endl;
		if (!nextTask[redirect] == "") {
			std::cout << "  Redirect to  :  " << std::setw(field_width + 3) << "[" + nextTask[redirect] + "]" << std::endl;
		}
	}
	else {
		if (nextTask[passed] == "") {
			os << "Task Name      :  " << std::left << std::setw(field_width + 3) << "[" + name + "]" << "[1]" << std::endl;
		}
		else {
			os << "Task Name      :  " << std::left << std::setw(field_width + 3) << "[" + name + "]" << "[" + slots + "]"<< std::endl;
			os << "  Continue to  :  " << std::left << std::setw(field_width + 6) << "[" + nextTask[passed] + "]" << "*** to be validated ***" << std::endl;

			if (nextTask[redirect] != "") {
				os << "  Redirect to  :  " << std::left << std::setw(field_width + 6) << "[" + nextTask[redirect] + "]" << "*** to be validated ***" << std::endl;

			}
		}
	}

}





//https://stackoverflow.com/questions/25829143/trim-whitespace-from-a-string
