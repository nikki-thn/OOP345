

#include <iostream>
#include <fstream>
#include"Text.h"

using namespace std;

namespace w3 {

	Text::Text() : m_fileName(nullptr), m_size(0), m_strings(nullptr) { }


	Text::Text(const char* filename) { // one parameter constructor

		m_fileName = new char[strlen(filename) + 1];
		strcpy(m_fileName, filename);

		fstream file;
		file.open(m_fileName, ios::in);

		if (file.is_open() && !file.fail()) {

			char temp[200];
			int size = 0;

			while (!file.eof()) {
				file.getline(temp, 100, '\n');
				size++;
			}

			m_size = size;

			m_strings = new string[m_size];
			file.seekg(0);

			for (int i = 0; i < m_size; i++) {
				file.getline(temp, 100, '\n');
				m_strings[i] = temp;
			}
			file.close();
		}
		else {
			*this = Text();
		}
	}


	Text::~Text() { //destructor'
		delete[] m_fileName;
		delete[] m_strings;
	}

	Text::Text(const Text& rhs) { //copy constructor
		m_strings = nullptr;
		m_fileName = nullptr;
		*this = rhs;
	}

	Text::Text(Text&& rhs) { //move constructor

		m_fileName = new char[strlen(rhs.m_fileName) + 1];
		strcpy(m_fileName, rhs.m_fileName);
		m_size = rhs.m_size;
		m_strings = new string[m_size];
			for (int i = 0; i < m_size; i++) {
				m_strings[i] = rhs.m_strings[i];
			}

		rhs.m_fileName = nullptr;
		rhs.m_size = 0;
		rhs.m_strings = nullptr;
	}

	Text& Text::operator= (const Text& rhs) { //copy operator

		if (this != &rhs) {
			m_size = rhs.m_size;
			if (rhs.m_strings != nullptr && rhs.m_fileName != nullptr) {

				delete[] m_fileName;
				m_fileName = new char[strlen(rhs.m_fileName) + 1];
				strcpy(m_fileName, rhs.m_fileName);

				delete[] m_strings;
				m_strings = new string[m_size];
				for (int i = 0; i < m_size; i++) {
					m_strings[i] = rhs.m_strings[i];
				}
			}
		}
		else {
			m_strings = nullptr;
		}
		return *this;
	}

	Text&& Text::operator= (Text&& rhs) { //move operator
		if (&rhs != this) {
			strcpy(m_fileName, rhs.m_fileName);
			m_size = rhs.m_size;
			for (int i = 0; i < m_size; i++) {
				m_strings[i] = rhs.m_strings[i];
			}
			rhs.m_fileName = nullptr;
			rhs.m_size = 0;
			rhs.m_strings = nullptr;
		}
		return std::move(*this);
	}

	void Text::display() const {
		for (int i = 0; i < m_size; i++) { cout << m_strings[i] << endl; }
	}
}
