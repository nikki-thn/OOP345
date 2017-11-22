#include <string>
#include "Task.h"

//contain a single record
Task::Task(const std::string& record_) {

	slots = 1;
	pNextTask[2] = nullptr;
	size_t pos = 0;
	bool more = false;

	std::string temp;
	Utilities exactToken;
	name = exactToken.nextToken(temp, pos, more);

	pos = name.length() + 1;
	slots = exactToken.nextToken(temp, pos, more);

		for (size_t i = 0; i < getSlots() - 2; i++) {
			nextTask[i] = exactToken.nextToken(temp, pos, more);
		}
	
}

bool Task::validate(const Task& task) {

	bool isValid = false;

	for (size_t i = 0; i < 2; i++) {

		if (nextTask[i] == task.getName()) {
			pNextTask[i] = &task;
		}
	}

	return isValid;
}

const Task* Task::getNextTask(Quality quantity) const {
	int index = -1;
	//for (int i = 0; i < 2; i++) {
	//	if (quantity == passed) {
	//		
	//	}
	//	else if (quantity == redirect) {

	//	}
	//}
	return pNextTask[index];
}

void Task::display(std::ostream& os) const {

	if (name != "") {
		os << "Task Name: [" << name << "]       " << "[" << getSlots() << "]\n";

		if (pNextTask[0] != nullptr) {
			os << " Continue to: [" << nextTask[0] << "]\n";
		}
		if (pNextTask[0] != nullptr) {
			os << " Redirect to: [" << nextTask[0] << "]\n";
		}
	}
}