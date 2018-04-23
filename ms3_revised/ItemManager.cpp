#include "ItemManager.h"

/*! Display each element of the vector to ostream
* @param ostream
* @param bool true to display item description 
*/
void ItemManager::display(std::ostream& os, bool insertDescription) const {

	for (auto i = 0; i < std::vector<Item>::size(); i++){
		std::vector<Item>::at(i).display(os, insertDescription);
	}
}