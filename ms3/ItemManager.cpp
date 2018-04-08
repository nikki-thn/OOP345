#include "ItemManager.h"

/*! Display each element of the vector to ostream
* @param ostream
* @param bool true to display item description 
*/
void ItemManager::display(std::ostream& os, bool insertDescription) const {

	for (auto& item : *this) {
		item.display(os, insertDescription);
	}
}