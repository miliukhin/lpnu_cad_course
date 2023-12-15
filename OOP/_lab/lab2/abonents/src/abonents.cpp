#include <iostream>
#include <string>
#include <algorithm> // для SORT
#include "../include/abonents.h"
#define N 255

void Abonents::addAbonent() {
	Abonent abonent;
	if (real_size >= MAX_SIZE) {
		std::cout << "Error: the maximum number of abonents has been reached" << std::endl;
		return;
	}
	abonents[real_size] = abonent;
	real_size++;
	editAbonent(real_size-1);
}

void Abonents::editAbonent(int index) {
	//	std::cout << real_size << '\n';
	if (index < 0 || index >= real_size) {
		#include "snippets/invalidindex"
		return;
	}
	else
	{
		#include "snippets/options"

		char c;
		while((c = getchar()) != 'q')
		{
			c = toupper(c);
			int temp_num;
			double temp_numf;
			char temp_str[N];
			std::cout << "> ";

			switch(c)
			{
				case 'P':
					std::cout << "\b\bInput data:" << std::endl << "> ";
					std::cin >> temp_num;
					if(temp_num > 2000000000)
						#include "snippets/overflow"
					else
				  		abonents[index].setNum(temp_num);
				  	break;
				case 'C':
					std::cout << "Input data:" << std::endl << "> ";
				  	std::cin >> temp_num;
					if(temp_num > 2000000000)
						#include "snippets/overflow"
					else
					{
						std::cin.clear();
						std::fflush(stdin);
				  		abonents[index].setContract(temp_num);
					}
				  	break;
				case 'R':
					std::cout << "Input data:" << std::endl << "> ";
					std::cin >> temp_numf;
					if(temp_num > 2000000000) // <++>
						#include "snippets/overflow"
					else
					{
						std::cin.clear();
						std::fflush(stdin);
				  		abonents[index].setRate(temp_numf);
					}
				  	break;
				case 'B':
					std::cout << "Input data:" << std::endl << "> ";
					std::cin >> temp_numf;
					if(temp_num > 2000000000) // <++>
						#include "snippets/overflow"
					else
					{
						std::cin.clear();
						std::fflush(stdin);
				  		abonents[index].setBalance(temp_numf);
					}
				  	break;
				case 'F':
					std::cout << "Input data:" << std::endl << "> ";
					std::cin >> temp_str;

					std::cin.clear();
					std::fflush(stdin);

				  	abonents[index].setFname(temp_str);
				  	break;
				case 'L':
					std::cout << "Input data:" << std::endl << "> ";
					std::cin >> temp_str;

					std::cin.clear();
					std::fflush(stdin);

				  	abonents[index].setLname(temp_str);
				  	break;
			}
		}
	}
}

void Abonents::removeAbonent(int index) {
	if (index < 0 || index >= real_size) {
		#include "snippets/invalidindex"
		return;
	}
	else
	{
		std::cout << "Removing ";
		std::cout << abonents[index].getNum() << " (" << index << ")..." << std::endl;
		for (int i = index; i < real_size - 1; i++)
		{
			abonents[i] = abonents[i + 1];
		}
		std::cout << "Done.\n";
		real_size--;
	}
}

void Abonents::printAbonent(int index) {
	if (index < 0 || index >= real_size) {
		#include "snippets/invalidindex"
		return;
	}
	#include "snippets/abonentIndex"
	abonents[index].printAll();
}

void Abonents::printAllAbonents() {
	std::cout << "\033[1mAll abonents:\033[0m" << std::endl;
	std::cout << "\033[1m`````````````\033[0m" << std::endl;
	for (int index = 0; index < real_size; index++)
	{
		#include "snippets/abonentIndex"
		abonents[index].printAll();
		std::cout << std::endl;
	}
}

bool comp (Abonent& a, Abonent& b)
	{
		std::string first = a.getLname();
		std::string second = b.getLname();
		return  first < second;
	}

void Abonents::sortAbonentsByLastName() {
	std::sort(abonents, abonents + real_size, comp);
}

void Abonents::printAbonentsWithNegativeBalance() {
	std::cout << "Abonents with negative balance:" << std::endl;
	for (int index = 0; index < real_size; index++) {
		if (abonents[index].getBalance() < 0) {
			#include "snippets/abonentIndex"
			abonents[index].printAll();
			std::cout << std::endl;
		}
	}
}
