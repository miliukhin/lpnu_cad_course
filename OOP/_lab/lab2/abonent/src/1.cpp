#include <fstream>
#include <iostream>
#include "fstream"
#include "../include/abonent.h"
#define N 255

int main() {

	std::string banner;
	std::ifstream file ("banner");
	if (file.is_open())
	{
		while (getline (file, banner))
			std::cout << banner << '\n';
		file.close();
	}
	else std::cout << "unable to open file";


	Abonent abon;
	abon.setNum(12356092);
	abon.setLname((char *)"Hello");
	abon.printLname();
	abon.printAll();

	return 0;
}
