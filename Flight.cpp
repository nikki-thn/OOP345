#include <cstring>
#include <iostream>

#include "Sandbox.h"

using namespace std;


class Flight {
	int m_flightNum;
	char* m_destination;
	int m_width = 10;

public:


	Flight(int flightNum = 0, const char* destination = nullptr) {

		if (flightNum > 0) m_flightNum = flightNum;
		else m_flightNum = 0;

		if (destination != nullptr) {
			m_destination = new char[strlen(destination) + 1];
			strcpy(m_destination, destination);
		}
		else m_destination = nullptr;

	}

	Flight& operator=(const Flight& rhs) {
		if (this != &rhs) {
			m_flightNum = rhs.m_flightNum;
			m_destination = new char[strlen(rhs.m_destination) + 1];
			strcpy(m_destination, rhs.m_destination);
		}
		return *this;
	}

	~Flight() {
		delete[] m_destination;
	}

	//-a query that returns the address of the first non - whitepsace character in the description of the Flight object;
	const char* description() const {

		if (m_destination != nullptr)
			return m_destination;
	}

	int number() const {
		if (m_flightNum != 0)
			return m_flightNum;
	}

	Flight& width(int width) {

		if (width > m_width && width > 0) {
			m_width = width;
		}
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& os, const Flight& rhs) {

		os.setf(std::ios::left);
		os.width(rhs.m_width);
		os << rhs.m_flightNum;
		os.fill(' ');
		os << rhs.m_destination << std::endl;

		return os;
	}

};


void display(Flight flight) {

	cout << flight.width(2) << endl;

}

int main() {

	Flight f, g(857, "Toronto");

	cout << g.width(9) << endl;
	f = g;
	display(f);
	cout << f.number() << endl;
	cout << f.description() << endl;
	return 0;
}
