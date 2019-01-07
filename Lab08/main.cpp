#include <cstdlib>
#include <iostream>
#include <memory>
#include <functional>
#include <random>
#include <future>
#include <thread>

#include "TQueue.h"
#include "TStack.h"



// template stack on shared_ptr

int main(int argc, char** argv) {
	TStack<Figure> stack_figure;
	typedef std::function<void(void)> command;
	TStack <command> stack_cmd;


	command cmd_insert = [&]() {
		std::cout << "Command: Create triangles" << std::endl;
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1, 1000);

		for (int i = 0; i < 10; i++) {
			int side = distribution(generator);
			stack_figure.push(std::shared_ptr<Figure>(new Pentagon(side)));
		}
	};

	command cmd_print = [&]() {
		std::cout << "Command: Print stack" << std::endl;
		std::cout << stack_figure;
	};


	command cmd_reverse = [&]() {
		std::cout << "Command: Reverse stack" << std::endl;

		TStack<Figure> stack_tmp;
		while (!stack_figure.empty()) stack_tmp.push(stack_figure.pop_last());
		while (!stack_tmp.empty()) stack_figure.push(stack_tmp.pop());


	};

	stack_cmd.push(std::shared_ptr<command>(&cmd_print, [](command*) {
	})); // using custom deleter
	stack_cmd.push(std::shared_ptr<command>(&cmd_reverse, [](command*) {
	})); // using custom deleter
	stack_cmd.push(std::shared_ptr<command>(&cmd_print, [](command*) {
	})); // using custom deleter
	stack_cmd.push(std::shared_ptr<command>(&cmd_insert, [](command*) {
	})); // using custom deleter


	while (!stack_cmd.empty()) {
		std::shared_ptr<command> cmd = stack_cmd.pop();
		std::future<void> ft = std::async(*cmd);
		ft.get();
	}
	
	system("pause");
    return 0;
}
