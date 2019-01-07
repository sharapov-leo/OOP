#include<iostream> // istream
#include"Octagon.h"
class Hexagon :public Figure{
public:
	Hexagon(); // Конструктор
	Hexagon(std::istream &is);
	Hexagon(size_t a);
	Hexagon(const Hexagon& orig); // ?Передача объекта(его параметров и типа)

	friend std::ostream& operator<<(std::ostream& os, const Hexagon& in);

	double Square() override; // override - ф-ия должна переопределять вирт-ую ф-ию,
	void Print() override; // чтобы не создать новую ф-ию

	virtual ~Hexagon(); // Деструктор
private:
	size_t side_a;
};