#include<iostream>
#include"Hexagon.h"
class Octagon : public Figure{
public:
	Octagon(); // Конструктор
	Octagon(std::istream &is);
	Octagon(size_t a);
	Octagon(const Octagon& orig); // ?Передача объекта(его параметров и типа)

	double Square() override; // override - ф-ия должна переопределять вирт-ую ф-ию,
	void Print() override; // чтобы не создать новую ф-ию

	virtual ~Octagon(); // Деструктор
private:
	size_t side_a;
};