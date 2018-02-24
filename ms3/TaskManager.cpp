#include <algorithm>
#include <vector>
#include "Task.h"
#include "TaskManager.h"
#include "ItemManager.h"

void TaskManager::validate(std::ostream& os) {

	bool isValid = false;
	for (auto& toValidateTask : *this) {
		for (auto& task : *this) {
			isValid = toValidateTask.validate(task);
		}

		if (!isValid) {
			std::cout << toValidateTask.getName() << "Task is not valid " << std::endl;
		}
	}
}

void TaskManager::validate(const ItemManager& itemManager, std::ostream& os)
{

	for (auto& item : itemManager) {

		auto pos = std::find_if(std::begin(*this), std::end(*this),
			[=](Task& task) { return task.getName() == item.getName(); });

		if (pos >= std::end(*this)) {
			os << item.getName() << "is not available" << std::endl;
		}
	}

	for (auto& item : itemManager) {

		auto pos = std::find_if(std::begin(*this), std::end(*this),
			[=](Task& task) { return item.getRemover() == task.getName(); });

		if (pos >= std::end(*this)) {
			os << item.getRemover() << "is not available" << std::endl;
		}
	}
}

void TaskManager::display(std::ostream& os) const
{
	for (auto& task : *this) {
		task.display(os);
	}
}