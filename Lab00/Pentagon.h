#include<iostream> // istream
#include"Figure.h"
class Pentagon :public Figure {
public:
	Pentagon(); // Конструктор
	Pentagon(std::istream &is);
	Pentagon(size_t a); 
	Pentagon(const Pentagon& orig); // ?Передача объекта(его параметров и типа)

	double Square() override; // override - ф-ия должна переопределять вирт-ую ф-ию,
	void Print() override; // чтобы не создать новую ф-ию

	virtual ~Pentagon(); // Деструктор
private:
	size_t side_a;
};