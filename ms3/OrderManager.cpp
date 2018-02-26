#include <algorithm>
#include <iostream>
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "OrderManager.h"


CustomerOrder&& OrderManager::extract() {

	for (auto& custOrder : *this) {
		return std::move(custOrder);
	}
}

void OrderManager::validate(const ItemManager& itemManager, std::ostream& os) {

	for (auto &custOrder : *this) {

		for (unsigned int i = 0; i < custOrder.noOrders(); i++) {

			auto pos = std::find_if(std::begin(itemManager), std::end(itemManager),
				[&, this](Item item) { return custOrder[i] == item.getName(); });

			if (pos >= std::end(itemManager)) {
				os << custOrder[i] << " is unavailable" << std::endl;
			}
		}
	}
}

void OrderManager::display(std::ostream& os) const {
	for (auto& custOrder : *this) {
		custOrder.display(os);
	}
}