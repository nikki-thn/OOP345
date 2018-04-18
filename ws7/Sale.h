/*! *********************************************************
* OOP345 Workshop 6: STL Containers
* File: Sale.h
* Version: 1.0
* \date April 12, 2018
* \author Nikki Truong - 112 314 174
***********************************************************/

#ifndef w7_SALE_H
#define w7_SALE_H

#include <iostream>
#include <vector>
#include "iProduct.h"

namespace w7 {

	class Sale {
		
		char* m_fileName; //file name
		std::vector <iProduct*> m_products; //STL vector to store product*
		int m_numRecs; //number of records
	
	public:

		Sale(const char* fileName);
		~Sale();

		void display(std::ostream& os) const;

	};
}

#endif
