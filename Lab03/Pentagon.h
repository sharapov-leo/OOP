#include<iostream>
#include"Figure.h"
class Pentagon :public Figure {
public:
	Pentagon();
	Pentagon(const Pentagon& orig);
	Pentagon(std::istream &is);
	Pentagon(size_t a);

	//friend std::istream& operator>>(std::istream& is, Pentagon& in);
	friend std::ostream& operator<<(std::ostream& os, const Pentagon& in);
	Pentagon& operator=(const Pentagon& right);

	double Square(); // �������
	void Print(); // ����������� ��������������

	virtual ~Pentagon(); // ����������
private:
	size_t side_a=0; // ������� ����������� �������������
};