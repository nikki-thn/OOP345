/*! *********************************************************
* OOP345 Workshop 4: Containers
* File: Notifications.h
* Version: 1.0
* \date Feb 18, 2018
* \author Nikki Truong - 112 314 174
***********************************************************/

#ifndef GRADES_H
#define GRADES_H
#include <fstream>
#include <string>
#include <functional>

class Grades {

	double* m_grades; //Array double to store students' grades
	int* m_studentID; //Array int to store studentID
	char* m_fileName; //cstring to store filename
	int m_numRecs; //number of records in the file

public:

	/*! One parameter constructor */
	Grades(const char* fileName) {

		//Set data members to safe empty state
		m_grades = nullptr;
		m_studentID = nullptr;
		m_fileName = nullptr;
		m_numRecs = 0;

		//If fileName is not empty
		if (fileName != nullptr) {
			m_fileName = new char[strlen(fileName) + 1];
			strcpy(m_fileName, fileName);

			std::fstream file;
			file.open(m_fileName, std::ios::in);

			//If file is ready to be read
			if (file.is_open() && !file.fail()) {

				//Get number of records for memory allocation
				while (!file.eof()) {
					std::string temp;
					getline(file, temp, '\n');
					m_numRecs++;
				}

				//allocate memory for arrays
				m_grades = new double[m_numRecs];
				m_studentID = new int[m_numRecs];

				//rewind to the beginning and read in data
				file.seekg(0);

				//read in data
				for (int i = 0; i < m_numRecs; i++) {
					file >> m_studentID[i] >> m_grades[i];
					file.ignore();
				}

				//close file
				file.close();
			}
		}
		else throw "File fails to open";
	}

	/*! Default destructor*/
	Grades::~Grades() {
		delete[] m_fileName;
		delete[] m_studentID;
		delete[] m_grades;
	}

	/*! Copy Constructor is prohitbited */
	Grades(const Grades&) = delete;

	/*! Copy Assignment is prohitbited */
	Grades& operator= (const Grades&) = delete;

	/*! Move Constructor is prohitbited */
	Grades(const Grades&&) = delete;

	/*! Move Assignment is prohitbited */
	Grades& operator=(const Grades&&) = delete;

	/*! Copy Assignment is prohitbited */
	void displayGrades(std::ostream& os, std::function<void(double)> letter) const {

		//display student information and grade
		for (int i = 0; i < m_numRecs; i++) {
			os << m_studentID[i] << " " << m_grades[i] << " ";

			//use lambda to get the letter grade equivalent to marks
			letter(m_grades[i]);
		}
	}

};


#endif
