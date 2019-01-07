#include<iostream>
#include<cstdlib>

class Pentagon {
public:
	Pentagon(); // Конструктор
	Pentagon(std::istream &is);
	Pentagon(size_t a); 
	Pentagon(const Pentagon& orig); // ?Передача объекта(его параметров и типа)

	double Square(); // override - ф-ия должна переопределять вирт-ую ф-ию,
	void Print(); // чтобы не создать новую ф-ию

	Pentagon& operator++();
	Pentagon& operator--();
	Pentagon& operator++(int);
	Pentagon& operator--(int);
	friend Pentagon operator+(const Pentagon& left, const Pentagon& right);
	Pentagon operator-(const Pentagon& right);

	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	friend std::istream& operator>>(std::istream& is, Pentagon& obj);

	Pentagon& operator=(const Pentagon& right);
	bool operator==(const Pentagon& right);
	bool operator!=(const Pentagon& right);

	virtual ~Pentagon(); // Деструктор
private:
	size_t side_a;
};