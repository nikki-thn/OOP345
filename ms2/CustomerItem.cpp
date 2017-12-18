#include "CustomerItem.h"
#include <iomanip>

const int CODE_WIDTH = 5;

CustomerItem::CustomerItem(const std::string& name_) {
	
	if (!name_.empty()) {
		name = name_;	
	}
	code = 0;
	filled = false;
}

void CustomerItem::fill(const unsigned int c) {
	code = c;
	filled = true;
}
void CustomerItem::clear() {
	code = 0;
	filled = false;
}
void CustomerItem::display(std::ostream& os) const {
	if (filled == true) {
		
		os << " + ";
	}
	else {
		os << " - ";
	}

	os << "[";
	os.setf(std::ios::right);
	os.fill('0');
	os.width(CODE_WIDTH);
	os << code << "] ";
	os.unsetf(std::ios::right);

	os << name << std::endl;
}