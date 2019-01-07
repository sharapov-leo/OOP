#include <cstdlib>
#include <iostream>
#include <memory>

#include "TQueue.h"
#include "IRemoveCriteriaByValue.h"


// template stack on shared_ptr

int main(int argc, char** argv) {

    TQueue<Figure> queue;
	
	
	IRemoveCriteriaByValue<Figure> criteria(std::shared_ptr<Figure>(new Pentagon(3)));

    std::shared_ptr<Figure> t;
	std::cout << "1 - Push pentagon" << std::endl;
	std::cout << "2 - Push octagon" << std::endl;
	std::cout << "3 - Push hexagon" << std::endl;
	std::cout << "4 - delete item from stack" << std::endl;
	std::cout << "5 - display stack" << std::endl;
	std::cout << "6 - display stack (for)" << std::endl;
	std::cout << "7 - exit" << std::endl;
	for (;;) {
		int n;
		int tmp;
		std::cin >> n;
		switch (n)
		{
		case 1:
			std::cout << "Enter number" << std::endl;
			std::cin >> tmp;
			queue.push(std::shared_ptr<Figure>(new Pentagon(tmp)));
			break;
		case 2:
			std::cout << "Enter number" << std::endl;
			std::cin >> tmp;
			queue.push(std::shared_ptr<Figure>(new Octagon(tmp)));
			break;
		case 3:
			std::cout << "Enter number" << std::endl;
			std::cin >> tmp;
			queue.push(std::shared_ptr<Figure>(new Hexagon(tmp)));
			break;
		case 4:
			if (!queue.empty()) { t = queue.pop(); }//t->Print(); }
			else std::cout << "Stack is empty" << std::endl;
			break;
		case 5:
			if (!queue.empty()) std::cout << queue;
			else std::cout << "Stack is empty" << std::endl;
			break;
		case 6:
			//int numt;
			//std::cin >> numt;
			//IRemoveCriteriaByValue<Figure> criteria(std::shared_ptr<Figure>(new Pentagon(numt)));
			queue.RemoveSubitem(&criteria);
			//for (auto i : queue) i->Print();
			break;
		case 7:
			system("pause");
			return 0;
		}
	}

	system("pause");
    return 0;
}
