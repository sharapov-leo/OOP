//#include"Pentagon.h"
#include "TQueue.h"
#include<iostream>

int main()
{
	int a = 0;
	TQueue queue;
	std::cout << "Menu" << std::endl;
	std::cout << "1 - create pentagon" << std::endl;
	std::cout << "2 - push item to queue" << std::endl;
	std::cout << "3 - check queue emptiness" << std::endl;
	std::cout << "4 - delete item from queue" << std::endl;
	std::cout << "5 - display queue" << std::endl;
	std::cout << "6 - exit" << std::endl;
	std::cout << std::endl;
	while (std::cin>>a)
		switch (a) {
		case 1: // Создать пятиугольник
		{
			Pentagon *ptr = new Pentagon(std::cin);
			std::cout << *ptr;
			delete ptr;
			break;
		}
		case 2: // Добавить элемент в стек
		{
			queue.push(Pentagon(std::cin));
			break;
		}
		case 3: // Не пуст ли стек
			if (queue.empty()) std::cout << "Queue is empty" << std::endl;
			else std::cout << "Queue is not empty" << std::endl;
			break;
		case 4: // Удалить элемент из стека
			queue.pop();
			break;
		case 5: // Вывести на экран все элементы из стека
			std::cout << queue;
			break;
		case 6:
			system("pause");
			return 0;
			break;
		}
	/*std::cout << "Pentagon" << std::endl;
	/*Pentagon *ptr1 = new Pentagon;
	Pentagon *ptr2 = new Pentagon;
	*ptr1 = 2;
	*ptr2 = 2;
	std::cout << (*ptr1 != *ptr2);*/
	/*TQueue queue;

	queue.push(Pentagon(1));
	queue.push(Pentagon(2));
	queue.push(Pentagon(3));

	//std::cout << queue<< std::endl;
	//std::cout << queue.empty();
	queue.pop();
	std::cout << queue;*/

	system("pause");
	return 0;
}