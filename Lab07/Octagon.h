#include<iostream>
#include"Pentagon.h"
class Octagon :public Figure {
public:
	Octagon(); // Конструктор
	Octagon(std::istream &is);
	Octagon(size_t a);
	Octagon(const Octagon& orig); // ?Передача объекта(его параметров и типа)

	friend std::ostream& operator<<(std::ostream& os, const Octagon& in);
	bool less(Octagon& right) { return false; };

	double Square(); // override - ф-ия должна переопределять вирт-ую ф-ию,
	void Print(); // чтобы не создать новую ф-ию

	virtual ~Octagon(); // Деструктор
private:
	size_t side_a;
};