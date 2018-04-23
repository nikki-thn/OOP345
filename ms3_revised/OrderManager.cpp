/**********************************************************
* OOP345 Milestone 3: Managers
* File: OrderManager.cpp
* \date March 15, 2018
* \author Nikki Truong - 112 314 174
***********************************************************/

#include <algorithm>
#include <iostream>
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "OrderManager.h"


/*! Move semantic that move customer order */
CustomerOrder&& OrderManager::extract() {

	for (auto& custOrder : *this) {
		return std::move(custOrder);
	}
}

/*! checks that the items requested in the customer orders are available, 
* inserting a message into os for any item that is not available  
* @param ItemManager to be validate 
* @param ostream print massage to os if item is not available
*/
void OrderManager::validate(const ItemManager& itemManager, std::ostream& os) {

	for (size_t i = 0; i < std::vector<CustomerOrder>::size(); i++) { //for every customerOrder in the vector

		for (unsigned int j = 0; j < std::vector<CustomerOrder>::at(i).noOrders(); j++) {

			//for every item in each customerOrder, return true if item is same as 
			// an item on the customerOrder
			auto pos = std::find_if(std::begin(itemManager), std::end(itemManager),
				[&, this](Item item) { return std::vector<CustomerOrder>::at(i)[j] == item.getName(); });


			// if item is not found, print message
			if (pos >= std::end(itemManager)) {
				os << std::vector<CustomerOrder>::at(i)[j] << " is  unavailable" << std::endl;
			}
		}
	}
}

/*! function will display all customerOrder in the vector */
void OrderManager::display(std::ostream& os) const {

	for (size_t i = 0; i < std::vector<CustomerOrder>::size(); i++) {
	//for (auto& custOrder : *this) {
		std::vector<CustomerOrder>::at(i).display(os);
	}
}