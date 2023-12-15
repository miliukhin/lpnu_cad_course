#include <iostream>
#include "../include/hier.h"

int main ()
{
	std::cout << "\033[1;7;31mD1\033[0m" << std::endl ;
	D1 d1_obj;
	d1_obj.show();

	d1_obj.~D1();

	std::cout << "\033[1;7;31mD2\033[0m" << std::endl ;
	D2 d2_obj;
	d2_obj.show();

	std::cout << "\033[1;7;31mD3\033[0m" << std::endl ;
	D3 d3_obj;
	d3_obj.show();

	std::cout << "\033[1;7;31mD4\033[0m" << std::endl ;
	D4 d4_obj;
	d4_obj.show();
}
