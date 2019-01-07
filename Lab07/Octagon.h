#include<iostream>
#include"Pentagon.h"
class Octagon :public Figure {
public:
	Octagon(); // �����������
	Octagon(std::istream &is);
	Octagon(size_t a);
	Octagon(const Octagon& orig); // ?�������� �������(��� ���������� � ����)

	friend std::ostream& operator<<(std::ostream& os, const Octagon& in);
	bool less(Octagon& right) { return false; };

	double Square(); // override - �-�� ������ �������������� ����-�� �-��,
	void Print(); // ����� �� ������� ����� �-��

	virtual ~Octagon(); // ����������
private:
	size_t side_a;
};