#include "Product.h"
 
namespace w7 {

	void Product::display(std::ostream& os) const {
		os.precision(4);
		os.width(10);
		os << m_productNum; 
		os.width(10); 
		os << m_price << std::endl;
	}

	double TaxableProduct::getCharge() const {
		double total;

		if (m_taxRate == 'H') {
			total = m_price * 1.13;
		}
		else if (m_taxRate == 'P') {
			total = m_price * 1.08;
		}
		return total;
	}

	void TaxableProduct::display(std::ostream& os) const {	
		os.width(10);
		os << m_productNum;
		os.width(10);
		os.precision(4);
		os << m_price << " " << m_taxRate << std::endl;
	}

	iProduct* readProduct(std::ifstream& ifs) {

		iProduct* ptrProducts = nullptr;
		int id;
		double price;
		char tax = 'z';
		char temp[100];

		std::string aString;

		ifs.getline(temp, 100, '\n');
		aString = temp;

		tax = aString.back();
	
		if (tax != 'H' && tax != 'P') {
			std::stringstream aStream(aString);
			aStream >> id >> price;
			ptrProducts = new Product(id, price);
		}
		
		else if (tax == 'H' || tax == 'P') {
			std::stringstream aStream(aString);
			aStream >> id >> price >> tax;
			ptrProducts = new TaxableProduct(id, price, tax);

			if (tax != 'H' && tax != 'P') throw "Record is invalid";
		}

		return ptrProducts;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& i) {
		i.display(os);
		return os;
	}
}