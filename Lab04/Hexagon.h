#include<iostream> // istream
#include"Octagon.h"
class Hexagon :public Figure{
public:
	Hexagon(); // �����������
	Hexagon(std::istream &is);
	Hexagon(size_t a);
	Hexagon(const Hexagon& orig); // ?�������� �������(��� ���������� � ����)

	friend std::ostream& operator<<(std::ostream& os, const Hexagon& in);

	double Square() override; // override - �-�� ������ �������������� ����-�� �-��,
	void Print() override; // ����� �� ������� ����� �-��

	virtual ~Hexagon(); // ����������
private:
	size_t side_a;
};