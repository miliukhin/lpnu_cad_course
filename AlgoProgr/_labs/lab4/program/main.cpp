#include <iostream>
#include "list.h"

void task_test()
{
	List<int> list;
	list.push_back('X');
	list.populate(5);
	list.push_back('Z');
	list.populate(5);

	for (int i = 0; i < list.getSize(); i++)
		std::cout << i << '\t' << list[i] << std::endl;

	std::cout << "\033[1mВидалення символів між X та Z\033[0m" << std::endl;
	std::cout << "\033[1m`````````````````````````````\033[0m" << std::endl;
	list.delete_between_x_z();

	std::cout << std::endl;

	for (int i = 0; i < list.getSize(); i++)
		std::cout << i << '\t' << list[i] << std::endl;

	std::cout << "\033[1mРозмір списку:\033[0m\t"
		<< list.getSize();

	list.clear();
}

int main ()
{
	task_test();
}
