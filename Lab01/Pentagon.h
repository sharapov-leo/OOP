#include<iostream>
#include<cstdlib>

class Pentagon {
public:
	Pentagon(); // �����������
	Pentagon(std::istream &is);
	Pentagon(size_t a); 
	Pentagon(const Pentagon& orig); // ?�������� �������(��� ���������� � ����)

	double Square(); // override - �-�� ������ �������������� ����-�� �-��,
	void Print(); // ����� �� ������� ����� �-��

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

	virtual ~Pentagon(); // ����������
private:
	size_t side_a;
};