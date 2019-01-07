#include<iostream>
#include"Hexagon.h"
class Octagon : public Figure{
public:
	Octagon(); // �����������
	Octagon(std::istream &is);
	Octagon(size_t a);
	Octagon(const Octagon& orig); // ?�������� �������(��� ���������� � ����)

	double Square() override; // override - �-�� ������ �������������� ����-�� �-��,
	void Print() override; // ����� �� ������� ����� �-��

	virtual ~Octagon(); // ����������
private:
	size_t side_a;
};