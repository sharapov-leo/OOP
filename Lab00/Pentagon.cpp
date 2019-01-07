#include"Pentagon.h"
#include<iostream>
#include<cmath>

Pentagon::Pentagon() : Pentagon(0) {
}
Pentagon::Pentagon(std::istream &is) {
	std::cout << "Enter side length" << std::endl;
	is >> side_a;
	std::cout << "Pentagon created" << std::endl;
}
Pentagon::Pentagon(size_t a) : side_a(a){
	std::cout << "Pentagon created: " << side_a;
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