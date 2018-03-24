#ifndef w7_I_PRODUCT_H_
#define w7_I_PRODUCT_H_

// Workshop 7 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

#define HST 0.13
#define GST 0.08

namespace w7 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	iProduct* readProduct(std::ifstream& ifs);
	std::ostream& operator<<(std::ostream& os, const iProduct& i);
}

#endif