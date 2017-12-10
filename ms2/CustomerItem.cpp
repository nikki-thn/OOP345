#include "CustomerItem.h"
#include <iomanip>

const int CODE_WIDTH = 6;

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
		os << std::setw(CODE_WIDTH) << "[" << os.fill('0') << code << "] ";
		os << name << std::endl;
	}
	else {
		os << std::setw(CODE_WIDTH) << "[" << os.fill('0') << "] ";
		os << name << std::endl;
	}
}