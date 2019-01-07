#include"Hexagon.h"
#include<iostream>
#include<cmath>

Hexagon::Hexagon() : Hexagon(0) {
}
Hexagon::Hexagon(std::istream &is) {
	is >> side_a;
}
Hexagon::Hexagon(size_t a) : side_a(a) {
	std::cout << "Hexagon created: " << side_a<< std::endl;
}
Hexagon::Hexagon(const Hexagon& orig) {
	std::cout << "Hexagon copy created" << std::endl;
	side_a = orig.side_a;
}
double Hexagon::Square() {
	return (sqrt(3)*(double)(side_a*side_a)/4);
}
void Hexagon::Print() {
	std::cout << "a=" << side_a << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Hexagon& in)
{
	os << "a=" << in.side_a;
	return os;
}
Hexagon::~Hexagon() {
	std::cout << "Hexagon deleted" << std::endl;
}