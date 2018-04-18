#ifndef w7_PRODUCT_H
#define w7_PRODUCT_H

#include "iProduct.h"

namespace w7 {

	class Product : public iProduct {

	protected:
		int m_productNum;
		double m_price;

	public:
		Product() : m_productNum(0), m_price(0) { }
		Product(int productNum, double price) : m_productNum(productNum), m_price(price) { }

		double getCharge() const { return m_price; }
		void display(std::ostream& os) const;
	};

	class TaxableProduct : public Product {
		
		std::array <double, 2> m_taxStatus { 0.13, 0.08 };
		char m_taxRate;

	public:

		TaxableProduct(int id, double price, const char tax) : Product(id, price), m_taxRate(tax) {}
		
		double getCharge() const;
		void display(std::ostream& os) const;

	};
}

#endif
