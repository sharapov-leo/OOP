class Figure
{
public:
	virtual double Square() = 0; // Площадь (?=0)
	virtual void Print() = 0; // Вывод параметров фигуры и её тип
	//virtual std::ostream& operator<<(const Derived& in) {};
	virtual ~Figure() {};
};