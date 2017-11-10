#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class Example {
	vector <string> m_strings;
	char* filename;
public:

	Example(const char* filename) {

		fstream file;
		file.open(filename);

		if (!file.is_open()) throw "fail to open file";

		while (!file.eof()) {
			string temp;
			getline(file, temp, '\n');
			m_strings.push_back(temp);
		}

	}
	void strings(const string& a) { 
		
		m_strings.push_back(a);
	
	}

	void display() {

		for (auto ele : m_strings) {
			cout << ele << endl;
		}
	}
};
