#include<iostream>
#include"process.h"
#include "CString.h"

using namespace std;
using namespace w1;

void toProcess(const char* string, int max) {

	CString aString(string, max);

	cout << aString;

}