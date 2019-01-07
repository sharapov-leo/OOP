class Figure
{
public:
	virtual double Square() = 0; // Площадь (?=0)
	virtual void Print() = 0; // Вывод параметров фигуры и её тип

	//Figure& operator++();
	//Pentagon& operator--();
	//friend Figure operator+(const Figure& left, const Figure& right);
	//friend Pentagon operator-(const Pentagon& left, const Pentagon& right);

	//friend std::ostream& operator<<(std::ostream& os, const Figure& obj);
	//friend std::istream& operator>>(std::istream& is, Figure& obj);
	//virtual ~Figure();
};