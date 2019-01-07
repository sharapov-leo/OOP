#include"Octagon.h"
#include<iostream>
#include<cmath>

Octagon::Octagon() : Octagon(0) {
}
Octagon::Octagon(std::istream &is) {
	is >> side_a;
}
Octagon::Octagon(size_t a) : side_a(a) {
	std::cout << "Octagon created: " << side_a;
}
Octagon::Octagon(const Octagon& orig) {
	std::cout << "Octagon copy created" << std::endl;
	side_a = orig.side_a;
}
double Octagon::Square() {
	return (2*(double)(side_a*side_a)*(1+sqrt(2)));
}
void Octagon::Print() {
	std::cout << "a=" << side_a << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Octagon& in)
{
	os << "a=" << in.side_a;
	return os;
}
Octagon::~Octagon() {
	std::cout << "Hexagon deleted" << std::endl;
}