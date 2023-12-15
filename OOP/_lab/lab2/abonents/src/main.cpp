#include <fstream>
#include <iostream>
#include <string>
#include "fstream"
#include "../include/abonents.h"
#define N 255

std::string input = "duh";

static bool parseCommands(std::string input, Abonents &abonents)
{
	if(input == "help")
	{
		displayHelp();
		return true;
	}
	else if(input == "edit")
	{
		int index;
		std::cin >> index;
    		std::cin.clear();
    		fflush(stdin);

		abonents.editAbonent(index);
	}
	else if(input == "delete")
	{
		int index;
		std::cin >> index;
    		std::cin.clear();
    		fflush(stdin);
		abonents.removeAbonent(index);
	}
	else if(input == "add")
		abonents.addAbonent();
	else if(input == "print all")
		abonents.printAllAbonents();
	else if(input == "print negative")
		abonents.printAbonentsWithNegativeBalance();
	else if(input == "sort")
		abonents.sortAbonentsByLastName();
	else
		return true;
	return true;
}

bool test () {

Abonents db;
db.addAbonent();
db.addAbonent();
db.addAbonent();
db.addAbonent();
db.addAbonent();
db.removeAbonent(2);
db.printAbonent(2);
db.addAbonent();
db.addAbonent();
db.addAbonent();
//db.printAllAbonents();
//db.printAllAbonents();

return true;
}

static bool getInput(void)
{
	printf("\n$ ");
	std::getline(std::cin, input);
	if(input == "quit" || input == "exit")
		return false;
	else
		return true;
}

void displayWelcome () {
	std::string banner;
	std::ifstream file ("banner");
	if (file.is_open())
	{
		while (getline (file, banner))
			std::cout << banner << '\n';
		file.close();
	}
	else std::cout << "unable to open file";
}
void displayHelp ()
{
	std::cout << "\033[1mAvailable commands:\033[0m" << std::endl;
	std::cout << "\033[1m```````````````````\033[0m" << std::endl;

	std::cout << "\033[1mhelp\033[0m\t\t\tdisplay this help message" << std::endl;
	std::cout << "\033[1mquit\033[0m\t\t\tquit program" << std::endl;

	std::cout << "\033[1madd\033[0m\t\tadd an abonent" << std::endl;
	std::cout << "\033[1medit\033[0m\t\tedit an abonent" << std::endl;
	std::cout << "\033[1mdelete\033[0m\t\tdelete an abonent" << std::endl;
	std::cout << "\033[1mprint all\033[0m\t\tprint all abonents" << std::endl;
	std::cout << "\033[1mprint negative\033[0m\t\tprint abonents with negative balance" << std::endl;
}

int main ()
{
	displayWelcome();
	displayHelp();

	Abonents babadase;
	while (parseCommands(input, babadase) && getInput());

	printf("\nExiting...\n");
	return 0;
}
