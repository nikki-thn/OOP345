#ifndef W6_GRADES_H
#define W6_GRADES_H
#include <fstream>
#include <functional>

class Grades {

	double* m_grades;
	int* m_studentID;
	char* m_fileName;
	int m_numRecs;
	
public:

	Grades(const char* fileName) {

		m_grades = nullptr;
		m_studentID = nullptr;
		m_fileName = nullptr;
		m_numRecs = 0;

		if (fileName != nullptr);
		m_fileName = new char[strlen(fileName) + 1];
		strcpy(m_fileName, fileName);

		std::fstream file;
		file.open(m_fileName, std::ios::in);

		if (file.is_open() && !file.fail()) {
			while (!file.eof()) {
				char temp[200];
				file.getline(temp, 100, '\n');
				m_numRecs++;
			}

			m_grades = new double[m_numRecs];
			m_studentID = new int[m_numRecs];

			file.seekg(0);
			for (int i = 0; i < m_numRecs && !file.eof(); i++) {
				file >> m_studentID[i] >> m_grades[i];
				file.ignore();
			}
			file.close();
		}
		else throw "File fails to open";
	}

	Grades::~Grades() {
		delete[] m_fileName;
		delete[] m_studentID;
		delete[] m_grades;
	}

	Grades(const Grades&) = delete;
	Grades& operator= (const Grades&) = delete;

	Grades(const Grades&&) = delete;
	Grades& operator=(const Grades&&) = delete;

	void displayGrades(std::ostream& os, std::function<void(double)> letter) const {
		for (int i = 0; i < m_numRecs; i++) {
			os << m_studentID[i] << " " << m_grades[i] << " ";
			letter(m_grades[i]);
		}
	}

};


#endif
