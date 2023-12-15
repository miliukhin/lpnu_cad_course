#include <iostream>
#define N 255

class Abonent
{
	private:
	int phone_num;
	int contract_num;

	double min_rate;
	double balance;

	char fname[N];
	char lname[N];

	public:
	Abonent ();

	Abonent (
			int phone_num,
			int contract_num,
			double min_rate,
			double balance,
			char fname[],
			char lname[]
		);

	/* Функції для задання значень полів	*/
	void setNum (int phone_num); // номер телефона
	void setContract (int contract_num); // номер контракту
	void setRate (double min_rate); // плата за хвилину
	void setBalance (double balance); // баланс
	void setFname (char fname[]); // зміна імені
	void setLname (char lname[]); // зміна прізвища

	/* Функції для виведення значень полів	*/
	void printNum (); // номер телефона
	void printContract (); // номер контракту
	void printRate (); // ціна за хвилину
	void printBalance (); // отримання суми коштів на рахунку
	void printFname (); // ім'я
	void printLname (); // прізвище
	void printAll (); // прізвище
	void print(char arg); // прізвище

	/* Функції для отримання значень полів	*/
	int getNum (); // номер телефона
	int getContract (); // номер контракту
	double getRate (); // плата за хвилину
	double getBalance (); // баланс

	char * getFname (); // ім'я
	char * getLname (); // прізвище
};

