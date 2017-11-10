#include <iostream>
#include <string>
#include"Station.h"

using namespace std;

namespace w2 {

	Station::Station() : m_stationName (" "), m_numAdultPass(0), m_numStudentPass(0) {
		cout << "Constructor\n";
	}
	
	Station::~Station() {
		cout << "Destructor\n";
	}

	void Station::set(const std::string& stationName, unsigned numAdultPass, unsigned numStudentPass) {
	
		if (!stationName.empty()) {

			m_stationName = stationName;
			m_numAdultPass = numAdultPass;
			m_numStudentPass = numStudentPass;
		}
	}

	void Station::update(PassType pass, int numPass) {

		if (pass == Student) {

	
				m_numStudentPass += numPass;
		

		}
		else if (pass == Adult){

		/*	if (numPass >= 0) {*/
				m_numAdultPass += numPass;
			
		/*	else {
				m_numAdultPass -= (-1)*numPass;
			}*/
		}
	}

	unsigned Station::inStock(PassType pass) const {

		unsigned numPass = 0;

		if (pass == Student) {
			numPass = m_numStudentPass;
		}
		else if (pass == Adult) {
			numPass = m_numAdultPass;
		}
		return numPass;
	}

	const std::string& Station::getName() const {

		return m_stationName;
	}

	void Station::display() const {

		
		cout.setf(ios::left);

		cout.width(17);
		cout << m_stationName;
		cout.unsetf(ios::left);
		cout.width(8);
		cout << m_numAdultPass;
		cout.width(6);
		cout << m_numStudentPass << endl;
	}
}