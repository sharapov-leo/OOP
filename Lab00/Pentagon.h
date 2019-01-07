#include<iostream> // istream
#include"Figure.h"
class Pentagon :public Figure {
public:
	Pentagon(); // �����������
	Pentagon(std::istream &is);
	Pentagon(size_t a); 
	Pentagon(const Pentagon& orig); // ?�������� �������(��� ���������� � ����)

	double Square() override; // override - �-�� ������ �������������� ����-�� �-��,
	void Print() override; // ����� �� ������� ����� �-��

	virtual ~Pentagon(); // ����������
private:
	size_t side_a;
};