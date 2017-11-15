#include<iostream>
#include<fstream>
#include <string>
#include "Sale.h"

namespace w7 {

	Sale::Sale(const char* fileName) {

		if (fileName != nullptr) {
			m_fileName = new char[strlen(fileName) + 1];
			strcpy(m_fileName, fileName);

			std::ifstream file;
			file.open(m_fileName, std::ios::in);

			if (!file.fail() && file.is_open()) {
				char temp[100];
				m_numRecs = 0;
				while (!file.eof()) {
					file.getline(temp, 100, '\n');
					m_numRecs++;
				}

				file.seekg(0);
				for (int i = 0; i < m_numRecs; i++) {
					m_products.push_back(readProduct(file));
				}

				file.close();
			}
		}

		else throw "File fails to open";
	}

	Sale::~Sale() {
		delete[] m_fileName;
	}

	void Sale::display(std::ostream& os) const {

		std::cout << "Product No     Cost Taxable" << std::endl;

		for (auto i: m_products) {
			i->display(os);
		}
	}


}