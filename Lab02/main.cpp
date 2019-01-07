#include<iostream>
#include"TQueue.h"
int main() 
{

	std::shared_ptr<Figure> t;
	TQueue queue;

	queue.push(std::shared_ptr<Pentagon>(new Pentagon(1)));
	queue.push(std::shared_ptr<Hexagon>(new Hexagon(0)));
	queue.push(std::shared_ptr<Octagon>(new Octagon(3)));

	
	std::cout << queue;
	t = queue.pop(); t->Print();
	/*t = stack.pop(); t->Print();
	
	t = stack.pop(); t->Print();
	t = stack.pop(); t->Print();*/

	system("pause");
	return 0;
}