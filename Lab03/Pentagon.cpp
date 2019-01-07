#include"Pentagon.h"

Pentagon::Pentagon() : Pentagon(0) {
}
Pentagon::Pentagon(std::istream &is) {
	is >> side_a;
}
Pentagon::Pentagon(size_t a) : side_a(a) {
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
std::ostream& operator<<(std::ostream& os, const Pentagon& in)
{
	os << "a=" << in.side_a;
	return os;
}

Pentagon& Pentagon::operator=(const Pentagon& right) {

	if (this == &right) return *this;

	std::cout << "Pentagon copied" << std::endl;
	side_a = right.side_a;

	return *this;
}

Pentagon::~Pentagon() {
	std::cout << "Pentagon deleted" << std::endl;
}