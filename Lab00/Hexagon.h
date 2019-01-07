#include<iostream> // istream
#include"Pentagon.h"

class Hexagon :public Figure {
public:
	Hexagon(); // �����������
	Hexagon(std::istream &is);
	Hexagon(size_t a);
	Hexagon(const Hexagon& orig); // ?�������� �������(��� ���������� � ����)

	double Square() override; // override - �-�� ������ �������������� ����-�� �-��,
	void Print() override; // ����� �� ������� ����� �-��

	virtual ~Hexagon(); // ����������
private:
	size_t side_a;
};