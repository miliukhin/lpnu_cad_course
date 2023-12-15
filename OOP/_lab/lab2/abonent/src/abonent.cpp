#include <iostream>
#include <string>
#include <cstring>
#include "../include/abonent.h"

	/* Функції для задання значень полів	*/
	void Abonent::setNum (int phone_num) // номер телефона
	{
		if (phone_num <= 0 )
			std::cout << "invalid phone number!"  << '\n' ;
		else
			this->phone_num = phone_num;
	}
	void Abonent::setContract (int contract_num) // номер контракту
	{
		if (contract_num <= 0)
			std::cout << "invalid contract number!"  << '\n' ;
		else
			this->contract_num = contract_num;
	}
	void Abonent::setRate (double min_rate) // плата за хвилину
	{
		if (min_rate <= 0)
			std::cout << "invalid rate!"  << '\n' ;
		else
			this->min_rate = min_rate;
	}
	void Abonent::setBalance (double balance) // баланс
	{
		if (!balance)
			std::cout << "invalid balance!"  << '\n' ;
		else
			this->balance = balance;
	}
	void Abonent::setFname (char fname[]) // зміна імені
	{
		strcpy(this->fname, fname);
	}
	void Abonent::setLname (char lname[]) // зміна прізвища
	{
		strcpy(this->lname, lname);
	}

	/* Функції для виведення значень полів	*/
	void Abonent::printNum ()
	{
		std::cout << "Phone number:\t\t" << phone_num  << '\n' ;
	}
	void Abonent::printContract ()
	{
		std::cout << "Contract number:\t" << contract_num  << '\n' ;
	}
	void Abonent::printRate () // ціна за хвилину
	{
		std::cout << "Minute rate:\t\t" << min_rate  << '\n' ;
	}
	void Abonent::printBalance () // отримання суми коштів на рахунку
	{
		std::cout << "Balance:\t\t" << balance  << '\n' ;
	}
	void Abonent::printFname () // ім'я
	{
		std::cout << "First name:\t\t" << fname  << '\n' ;
	}
	void Abonent::printLname () // прізвище
	{
		std::cout << "Last name:\t\t" << lname  << '\n' ;
	}
	void Abonent::printAll () // всі
	{
		printNum ();
		printContract ();
		printRate ();
		printBalance (); // отримання суми коштів на рахунку
		printFname (); // ім'я
		printLname (); // прізвище
	}
	void Abonent::print(char arg)
	{
		switch(arg)
		{
			case 'p':
				printNum();
				break;
			case 'l':
				printLname();
				break;
			case 'f':
				printFname();
				break;
			case 'b':
				printBalance();
				break;
			case 'r':
				printRate();
				break;
			case 'c':
				printContract();
				break;
		}
	}

	Abonent::Abonent ()
	{
		phone_num = 0;
		contract_num = 0;

		min_rate = 3.;
		balance = 0.;

		strcpy(this->fname, "");
		strcpy(this->lname, "");
	}

	Abonent::Abonent (int phone_num, int contract_num, double min_rate, double balance, char fname[], char lname[])
	{
		this->phone_num = phone_num;
		this->contract_num = contract_num;

		this->min_rate = min_rate;
		this->balance = balance;

		strcpy(this->fname, fname);
		strcpy(this->lname, lname);
	}
