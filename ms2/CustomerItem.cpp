#include "CustomerItem.h"


class Item;

/*! One parameter constructor that takes in name of the task*/
CustomerItem::CustomerItem(const std::string& name_) {
	
	//set name to parameter value
	if (!name_.empty()) name = name_;	
	
	//initializing
	code = 0;
	filled = false;
}


/*! \return true if name is not empty */
bool CustomerItem::asksFor(const Item& i) const {
	return name == i.getName();
}


/*! \return filled status*/
bool CustomerItem::isFilled() const { return filled; }


/*! \return code from Item */
void CustomerItem::setCode(int c) { code = c; }


/*! \return name */
const std::string& CustomerItem::getName() const { return name; }


/*! function set code to paramater value and filled status to true */
void CustomerItem::fill(const unsigned int c) {
	code = c;
	filled = true;
}


/*! function set code to 0 and filled status to false */
void CustomerItem::clear() {
	code = 0;
	filled = false;
}

/*! function display an item to ostream*/
void CustomerItem::display(std::ostream& os) const {
	
	if (filled == true) os << " + "; //print + if item is filled
	else os << " - "; //else print -
	
	os << "[";
	os.setf(std::ios::right);
	os.fill('0');
	os.width(CODE_WIDTH);
	os << code << "] ";
	os.unsetf(std::ios::right);

	os << name << std::endl;
}
