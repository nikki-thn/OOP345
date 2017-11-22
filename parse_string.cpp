
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <numeric>
#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>


using namespace std;


int main() {

	fstream file;
	file.open("text.txt", ios::in);
	vector<string> vect;
	while (!file.eof()) {
		std::string temp;
		getline(file, temp, '\n');
		vect.push_back(temp);
	}
	file.close();

	for (size_t i = 0; i < vect.size(); i++) {
		std::istringstream iss(vect[i]);
		char temp[100];
		std::string token, token1, token2, token3;

	
		iss >> std::ws;
		iss.getline(temp, 100, '|');
		token = temp;

		iss >> std::ws;
		iss.getline(temp, 100, '|');
		token1 = temp;
		if (token1 == "") token1 = "1";

		iss >> std::ws;
		iss.getline(temp, 100, '|');
		token2 = temp;

		iss >> std::ws;
		iss.getline(temp, 100, '|');
		token3 = temp;
		iss.ignore(50);


		//http://www.cplusplus.com/reference/string/basic_string/find_last_not_of/

		std::string::size_type last;
		last = token.find_last_not_of(' ');
		token.erase(last + 1);
		last = token1.find_last_not_of(' ');
		token1.erase(last + 1);
		last = token2.find_last_not_of(' ');
		token2.erase(last + 1);
		last = token3.find_last_not_of(' ');
		token3.erase(last + 1);

		if (token != "") {
			cout << "Task Name: [" << token << "]  [" << token1 << "]" << endl;

			if (token2 != "") {
				cout << " Continue to : [" << token2 << "]" << endl;
			}
			if (token3 != "") {
				cout << " Redirect to : [" << token3 << "]" << endl;
			}
		}

	}


	return 0;
}
