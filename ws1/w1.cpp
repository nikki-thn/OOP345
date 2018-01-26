#include<iostream>
#include"process.h"

int main(int argc, char*argv[]) {

	int max = 0;
	if (argc > 1) {
		std::cout << "Maximum number of characaters stored: ";
		std::cin >> max;
		for (int i = 1; i <= argc - 1; i++) {
			std::cout << (i - 1) << ":";
			std::cout.width(3);
			toProcess(argv[i], max);
		}
	}
	else if (argc == 1) {
		std::cout << "Insufficient number of arguments (min 1)" << std::endl;
	}

	return 0;

}