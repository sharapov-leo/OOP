#include"Pentagon.h"
#include<iostream>
#include<cmath>

Pentagon::Pentagon() : Pentagon(0) {
}
Pentagon::Pentagon(std::istream &is) {
	std::cout << "Enter the number" << std::endl;
	is >> side_a;
}
Pentagon::Pentagon(size_t a) : side_a(a){
	std::cout << "Pentagon created: " << side_a << std::endl;
}
Pentagon::Pentagon(const Pentagon& orig) {
	std::cout << "Pentagon copy created" << std::endl;
	side_a = orig.side_a;
}
double Pentagon::Square() {
	return (((double)side_a*(double)side_a*sqrt(25 + 10 * sqrt(5))) / 4);
}
void Pentagon::Print() {
	std::cout << "a=" << side_a << std::endl;
}
Pentagon::~Pentagon() {
	std::cout << "Pentagon deleted" << std::endl;
}

Pentagon& Pentagon::operator=(const Pentagon& right) {

    if (this == &right) return *this;

    std::cout << "Pentagon copied" << std::endl;
    side_a = right.side_a;

    return *this;
}

bool Pentagon::operator==(const Pentagon& right) {

	if (this->side_a == right.side_a) return true;
	else return false;
}

bool Pentagon::operator!=(const Pentagon& right) {

	if (this->side_a != right.side_a) return true;
	else return false;
}

Pentagon& Pentagon::operator++() {
    side_a++;    
    return *this;
}

Pentagon& Pentagon::operator++(int) {
	side_a++;
	return *this;
}

Pentagon& Pentagon::operator--() {

	if (side_a - 1 > 0) this->side_a--;
	return *this;
}
Pentagon& Pentagon::operator--(int) {
	if (side_a - 1 > 0) this->side_a--;
	return *this;
}

Pentagon operator+(const Pentagon& left,const Pentagon& right) {
  
    return Pentagon(left.side_a+right.side_a);
}

Pentagon Pentagon::operator-(const Pentagon& right) {
	if (this->side_a - right.side_a > 0) this->side_a -= right.side_a;
	return *this;
}


std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {

    os << "Figure: Pentagon" << std::endl << "a=" << obj.side_a << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Pentagon& obj) {

    is >> obj.side_a;

    return is;
}
