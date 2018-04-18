#include<iostream>
#include<fstream>
#include <string>
#include <cstring>
#include "Sale.h"

namespace w7 {

	/*! One-parameter Constructor */
	Sale::Sale(const char* fileName) {

		if (fileName != nullptr) {

			//allocate memory for fileName
			m_fileName = new char[strlen(fileName) + 1];
			std::strcpy(m_fileName, fileName);


			std::ifstream file;
			file.open(m_fileName, std::ios::in);

			//file is good for reading
			if (!file.fail() && file.is_open()) {
				char temp[100];
				m_numRecs = 0;
				
				//count number of records for memory allocation
				while (!file.eof()) {
					file.getline(temp, 100, '\n');
					m_numRecs++;
				}

				//rewind
				file.seekg(0);

				//read in
				for (int i = 0; i < m_numRecs; i++) {
					m_products.push_back(readProduct(file));
				}

				//close file
				file.close();
			}
		}
		//throw exception if fileName is invalid
		else throw "File fails to open";
	}

	/*! Destructor*/
	Sale::~Sale() {

		//deallocate memory
		delete[] m_fileName;
	}

	/*! function display product to ostream */
	void Sale::display(std::ostream& os) const {

		double total = 0;

		std::cout << "Product No     Cost Taxable" << std::endl;

		for (auto i: m_products) {
			i->display(os);
			total += i->getCharge();
		}

		std::cout.precision(5);
		std::cout << "     Total    " << total << std::endl;
	}


}