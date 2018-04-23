/**********************************************************
* OOP345 Milestone 3: Managers
* File: TaskManager.cpp
* \date April 15, 2018
* \author Nikki Truong - 112 314 174
***********************************************************/

#include <algorithm>
#include <vector>
#include "Task.h"
#include "TaskManager.h"
#include "ItemManager.h"


/*! validates each task against all of the other tasks in the base class container.
This function inserts a message into os if not all tasks have been validated.*/
void TaskManager::validate(std::ostream& os) {

	bool isValid = false;

	//for each Task in the vector
	for (auto i = 0; i < std::vector<Task>::size(); i++) {

		//for each task in the vector
		for (auto j = 0; j < std::vector<Task>::size(); j++) {
			isValid = std::vector<Task>::at(i).validate(std::vector<Task>::at(j));
		}

		if (!isValid) {
			//display message if task is not valid
			os << std::vector<Task>::at(i).getName() << "Task is not valid " << std::endl;
		}
	}
}


/*! checks that the tasks assigned to handle each item managed by itemManager
are tasks in the base class container.  If a task is not in the container,
then this function inserts a message into os that that task is not available. */
void TaskManager::validate(const ItemManager& itemManager, std::ostream& os) {

	// for each item in item Manager
	for (auto& item : itemManager) {

		// find Task that has same name with an item's name
		auto pos = std::find_if(std::begin(*this), std::end(*this),
			[=](Task& task) { return task.getName() == item.getName(); });

		// if Task is not found, display message
		if (pos >= std::end(*this)) {
			os << item.getName() << "is not available" << std::endl;
		}
	}

	// for each item in item Manager
	for (auto& item : itemManager) {

		// find Task that has same name with an item's remover ???
		auto pos = std::find_if(std::begin(*this), std::end(*this),
			[=](Task& task) { return item.getRemover() == task.getName(); });

		// if Task is not found, display message
		if (pos >= std::end(*this)) {
			os << item.getRemover() << "is not available" << std::endl;
		}
	}
}


/*! display each task in the vector to ostream */
void TaskManager::display(std::ostream& os) const 
{
	for (auto i = 0; i < std::vector<Task>::size(); i++) {
		std::vector<Task>::at(i).display(os);
	}
}