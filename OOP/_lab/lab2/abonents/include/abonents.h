#include <iostream>
#include <string>
#include "abonent.h"

void displayHelp ();

class Abonents {
private:
	static const int MAX_SIZE = 100;
	Abonent abonents[MAX_SIZE];
	int real_size;

public:
	Abonents() {
		real_size = 0;
	}

	void addAbonent(); // додання абонента
	void editAbonent(int index); // зміна абонента
	void removeAbonent(int index);
	void printAbonent(int index);
	void printAllAbonents();

	void sortAbonentsByLastName();
	void printAbonentsWithNegativeBalance();

	void searchAbonent(std::string field);

};

