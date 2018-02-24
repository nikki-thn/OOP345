#include "ItemManager.h"


void ItemManager::display(std::ostream& os, bool insertDescription) const {

	for (auto& item : *this) {
		item.display(os, insertDescription);
	}
}