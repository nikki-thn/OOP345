#include <string>
#include <iostream>
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
		exactToken.setFieldWidth(tokens.size());
	
	}

	if (field_width < exactToken.getFieldWidth()) {
		field_width = exactToken.getFieldWidth();
	}

	for (auto& i : tokens) {
		size_t first = i.find_first_not_of(' ');
		i.erase(0, first);
		size_t last = i.find_last_not_of(' ');
		i.erase(last + 1);
	}


	if (tokens[0] != "") { name = tokens[0]; }
	else throw std::string(record_) + std::string("*** no token found before the delimiter ***");

	if (tokens[1] != "") slots = tokens[1];
	if (tokens[2] != "") nextTask[passed] = tokens[2];
	if (tokens[3] != "") nextTask[redirect] = tokens[3];
}

bool Task::validate(const Task& task) {

	bool isValid = false;

	if (nextTask[passed] == task.getName()) {
		pNextTask[passed] = &task;
	}
	else if (nextTask[redirect] == task.getName()) {
		pNextTask[redirect] = &task;
	}
	else {
		pNextTask[passed] = nullptr;
		pNextTask[redirect] = nullptr;
		isValid = true;
	}

	return isValid;
}

const Task* Task::getNextTask(Quality quantity) const {
	int index = -1;

	if (quantity == passed) {
		if (pNextTask[passed] != nullptr && pNextTask[redirect] == nullptr) {
			index = 0;
		}
		else if (pNextTask[passed] != nullptr && pNextTask[redirect] != nullptr) {
			throw std::string("*** Validate [") + nextTask[passed] +
				std::string("] @ [") + nextTask[redirect] +
				std::string("] ***");
		}
	}
	else if (quantity == redirect) {
		index = 1;
	}
	return pNextTask[index];
}

void Task::display(std::ostream& os) const {

	if (name != "") {
		os << "Task Name: [" << name << "]       " << "[" << slots << "]" << std::endl;

		if (nextTask[passed] != "") {
			os << " Continue to: [" << nextTask[passed] << "]" << std::endl;
		}
		if (nextTask[redirect] != "") {
			os << " Redirect to: [" << nextTask[redirect] << "]" << std::endl;
		}
	}

}

//https://stackoverflow.com/questions/25829143/trim-whitespace-from-a-string