// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include <functional>
#include "Grades.h"

//function letter
void letter (double i) {
	if (i <= 100 && i >= 90) std::cout << "A+" << std::endl;
	if (i < 90 && i >= 80) std::cout << "A" << std::endl;
	if (i < 80 && i >= 75) std::cout << "B+" << std::endl;
	if (i < 75 && i >= 70) std::cout << "B" << std::endl;
	if (i < 70 && i >= 65) std::cout << "C+" << std::endl;
	if (i < 65 && i >= 60) std::cout << "C" << std::endl;
	if (i < 60 && i >= 55) std::cout << "D+" << std::endl;
	if (i < 55 && i >= 50) std::cout << "D" << std::endl;
	if (i < 50) std::cout << "F" << std::endl;
};

int main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	try {

		Grades grades(argv[1]);
		void(*ptrletter)(double);
		ptrletter = &letter;
		grades.displayGrades(std::cout, ptrletter);


		//Lambda using pointer
		auto b = [](double i) {
			if (i <= 100 && i >= 90) std::cout << "A+" << std::endl;
			if (i < 90 && i >= 80) std::cout << "A" << std::endl;
			if (i < 80 && i >= 75) std::cout << "B+" << std::endl;
			if (i < 75 && i >= 70) std::cout << "B" << std::endl;
			if (i < 70 && i >= 65) std::cout << "C+" << std::endl;
			if (i < 65 && i >= 60) std::cout << "C" << std::endl;
			if (i < 60 && i >= 55) std::cout << "D+" << std::endl;
			if (i < 55 && i >= 50) std::cout << "D" << std::endl;
			if (i < 50) std::cout << "F" << std::endl;
		};

		void(*fp)(double ) = b;

		grades.displayGrades(std::cout, fp);
	}

	//will throw error message if file fail to open
	catch (const char* message) {
		std::cout << message << std::endl;
	}

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}

