#include "Product.h"

const double HST_RATES = 0.13;
const double GST_RATES = 0.08;
 
namespace w7 {

	/*! function will display product and price to ostream*/
	void Product::display(std::ostream& os) const {
		os.precision(4);
		os.width(10);
		os << m_productNum; 
		os.width(10); 
		os << m_price << std::endl;
	}

	/*! Function will calculate the total price with tax for an item*/
	double TaxableProduct::getCharge() const {

		double total;

		if (m_taxRate == 'H') {
			total = m_price * (1 + HST_RATES);
		}
		else if (m_taxRate == 'P') {
			total = m_price * (1 + GST_RATES);
		}
		return total;
	}

	/*! function will display taxable product and price to ostream*/
	void TaxableProduct::display(std::ostream& os) const {

		os.width(10);
		os << m_productNum;
		os.width(10);
		os.precision(4);
		os << m_price;

		if (m_taxRate == 'H') os << " HST \n";
		else if (m_taxRate == 'P') os << " PST \n";
	
	}

	/*! Function will passed a file stream to be read into class members*/
	iProduct* readProduct(std::ifstream& ifs) {

		iProduct* ptrProducts = nullptr;
		int id;
		double price;
		char tax = 'z';
		char temp[100];

		std::string aString;

		ifs.getline(temp, 100, '\n');
		aString = temp;

		//get the last character for tax code
		tax = aString.back();
	
		//if regular product
		if (tax != 'H' && tax != 'P') {
			std::stringstream aStream(aString);
			aStream >> id >> price;
			ptrProducts = new Product(id, price);
		}
		//if taxable product
		else if (tax == 'H' || tax == 'P') {
			std::stringstream aStream(aString);
			aStream >> id >> price >> tax;
			ptrProducts = new TaxableProduct(id, price, tax);

			//throw exception if tax code is invalid
			if (tax != 'H' && tax != 'P') throw "Record is invalid";
		}

		return ptrProducts;
	}

	/*! operator<< overload */
	std::ostream& operator<<(std::ostream& os, const iProduct& i) {
		i.display(os);
		return os;
	}
}
