#include<iostream>
#include<fstream>
#include"Stations.h"

using namespace std;

namespace w2 {

	Stations::Stations(const char* filename) {

		m_fileName = new char[strlen(filename) + 1];
		strcpy(m_fileName, filename);

		fstream file;
		file.open(m_fileName, ios::in);

		char stationName[50];
		int numPassStudent;
		int numPassAdult;

		if (!file.fail()) {

			file >> m_numStations;
			file.ignore(2);
			cout << m_numStations << endl;

			m_stations = new Station[m_numStations];

			for (int i = 0; i < m_numStations && !file.eof(); i++) {

				file.getline(stationName, 50, ';');
				file >> numPassStudent >> numPassAdult;
				file.ignore();
				cout << stationName << numPassStudent << numPassAdult << endl;

				m_stations[i].set(stationName, numPassAdult, numPassStudent);
			}
		}
	}

		Stations::~Stations() {

			fstream file2;
			file2.open(m_fileName, ios::trunc | ios::out);
			
			if (!file2.fail()) {
				file2 << m_numStations << ";\n";
			
				for (int i = 0; i < (m_numStations - 1); i++) {
					file2 << m_stations[i].getName() << ";"
						<< m_stations[i].studentPass() << " " 
						<< m_stations[i].adultPass() << "\n";
				}

				file2 << m_stations[m_numStations - 1].getName() << ";"
					<< m_stations[m_numStations - 1].studentPass() << " "
					<< m_stations[m_numStations - 1].adultPass();

					file2.close();
			}

			delete[] m_fileName;
			delete[] m_stations;
		}

		void Stations::update() const { //accepts num of passes sold and update data for each station

			cout << "Pass Sold :" << endl << "-------------" << endl;

			for (int i = 0; i < m_numStations; i++) {

				int numPassStudent;
				int numPassAdult;

				cout << m_stations[i].getName() << endl;
				cout << "Student Passes sold: ";
				cin >> numPassStudent;
				m_stations[i].update(Station::Student, (-1) * numPassStudent);
				cout << "Adult Passes sold: ";
				cin >> numPassAdult;
				m_stations[i].update(Station::Adult, (-1)* numPassAdult);
				cout << endl << endl;
			}

		}

		void Stations::restock() const { //accepts num of passes added and ....
			
			cout << "Pass Added :" << endl << "-------------" << endl;

			for (int i = 0; i < m_numStations; i++) {

				int numPassStudent;
				int numPassAdult;

				cout << m_stations[i].getName() << endl;
				cout << "Student Passes sold: ";
				cin >> numPassStudent;
				m_stations[i].update(Station::Student, numPassStudent);
				cout << "Adult Passes sold: ";
				cin >> numPassAdult;
				m_stations[i].update(Station::Adult, numPassAdult);
				cout << endl << endl;
			}

	
		}

		void Stations::report() const {// reports current number of passes avail at each station
			
			cout << "Passes in Stock : Student Adult" << endl;
			cout << "-------------------------------" << endl;
			for (int i = 0; i < m_numStations; i++) {
				m_stations[i].display();
			}
		
		}

	}

