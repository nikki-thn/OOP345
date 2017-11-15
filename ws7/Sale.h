#ifndef w7_SALE_H
#define W7_SALE_H
#include <iostream>
#include <vector>
#include "iProduct.h"

namespace w7 {

	class Sale {
		
		char* m_fileName;
		std::vector <iProduct*> m_products;
		int m_numRecs;
	
	public:

		Sale(const char* fileName);
		~Sale();

		void display(std::ostream& os) const;



	};
}

#endif
