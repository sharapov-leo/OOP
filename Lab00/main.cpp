#include"Octagon.h"
#include<iostream>

int main()
{
	/*std::cout << "Pentagon" << std::endl;
	Figure *ptr = new Pentagon(std::cin);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;

	std::cout << "Hexagon" << std::endl;
	ptr = new Hexagon(std::cin);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;
	
	std::cout << "Octagon" << std::endl;
	ptr = new Octagon(std::cin);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;
	*/
	Figure *ptr;
	std::cout << "Select figure" << std::endl;
	std::cout << "1 - Pentagon" << std::endl;
	std::cout << "2 - Hexagon" << std::endl;
	std::cout << "3 - Octagon" << std::endl;
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		ptr = new Pentagon(std::cin);
		ptr->Print();
		std::cout << ptr->Square() << std::endl;
		delete ptr;
		break;
	case 2:
		ptr = new Hexagon(std::cin);
		ptr->Print();
		std::cout << ptr->Square() << std::endl;
		delete ptr;
		break;
	case 3:
		ptr = new Octagon(std::cin);
		ptr->Print();
		std::cout << ptr->Square() << std::endl;
		delete ptr;
		break;
	}
	

	system("pause");
	return 0;
}