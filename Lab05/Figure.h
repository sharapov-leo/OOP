class Figure
{
public:
	virtual double Square() = 0; // ������� (?=0)
	virtual void Print() = 0; // ����� ���������� ������ � � ���
	//virtual std::ostream& operator<<(const Derived& in) {};
	virtual ~Figure() {};
};