#include <cstdlib>
#include <iostream>
#include <memory>

#include "TQueue.h"

int main(int argc, char** argv) {

	TQueue<Figure> figure;
    
    std::shared_ptr<Figure> t;
    
	std::cout << "1 - Push pentagon" << std::endl;
	std::cout << "2 - Push octagon" << std::endl;
	std::cout << "3 - Push hexagon" << std::endl;
	std::cout << "4 - delete item from figure" << std::endl;
	std::cout << "5 - display figure" << std::endl;
	for (;;) {
		int n;
		int tmp;
		std::cin >> n;
		switch (n)
		{
		case 1:
			std::cout << "Enter number" << std::endl;
			std::cin >> tmp;
			figure.push(std::shared_ptr<Figure>(new Pentagon(tmp)));
			break;
		case 2:
			std::cout << "Enter number" << std::endl;
			std::cin >> tmp;
			figure.push(std::shared_ptr<Figure>(new Octagon(tmp)));
			break;
		case 3:
			std::cout << "Enter number" << std::endl;
			std::cin >> tmp;
			figure.push(std::shared_ptr<Figure>(new Hexagon(tmp)));
			break;
		case 4:
			if (!figure.empty()) { t = figure.pop(); t->Print(); }
			else std::cout << "Stack is empty" << std::endl;
			break;
		case 5:
			if (!figure.empty()) std::cout << figure;
			else std::cout << "Stack is empty" << std::endl;
		}
	}
	
	system("pause");
    return 0;
}
