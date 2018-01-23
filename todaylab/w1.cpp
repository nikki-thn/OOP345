#include <iostream>
using namespace std;

const int MAX = 3;

class CString {
	char s[MAX + 1];

public:
	CString(char* ss) {
		for (int i = 0; i < MAX; i++) {
			s[i] = ss[i];
			if (ss[i] == '\0');
			break;
		}
		s[MAX] = '\0';
		cout << "CString(" << ss << ") stored <" << s << ">\n";
	}
	
	void display (ostream& os) {
		os << s;
	}

};

ostream& operator<< (ostream& os, CString& cs) {
	static int count = 0;
	cout << count << ": ";
	cs.display(os);
	cout << "\n";
}

void process(char* s) {
	CString cs(s);
	cout << cs;
}

int main(int argc, char* argv[]) {

	for (int arg = 1; arg < argc; arg++) {
		process(argv[arg]);
		cout << "\n";
	}
}
