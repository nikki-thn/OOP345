#include <algorithm>
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "OrderManager.h"

CustomerOrder&& OrderManager::extract() {

	for (auto& custOrder : *this) {
		return std::move(custOrder);
	}
}

void OrderManager::validate(const ItemManager& itemManager, std::ostream& os)
{

	for (size_t i = 0; i < std::vector<CustomerOrder>::size(); i++)
	{
		for (size_t g = 0; g < std::vector<CustomerOrder>::at(i).noOrders(); g++)
		{
			for (size_t n = 0; n < itemManager.size(); n++)
			{
				if (std::vector<CustomerOrder>::at(i)[g] == itemManager.at(n).getName())
				{
					break;
				}
				if (n == itemManager.size() - 1)
				{
					std::cout << std::vector<CustomerOrder>::at(i)[g] << " is unavailable." << std::endl;
				}
			}
		}
	}
}

void OrderManager::display(std::ostream& os) const
{
	for (size_t i = 0; i < std::vector<CustomerOrder>::size(); i++)
	{
		std::vector<CustomerOrder>::at(i).display(os);
	}
}