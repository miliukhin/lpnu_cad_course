#include <iostream>
#include <cstring>

//gf gF <to the line following the file name>
// 5gt tabn
// gT tabp
//tabmove -+N

class Abonent
{
	private:
	int phone_num;
	int contract_num;

	double min_rate;
	double balance;

	char fname[40] = "";
	char lname[40] = "";
	protected:
	public:

	Abonent ()
	{
		phone_num = 0;
		contract_num = 0;

		min_rate = 3.;
		balance = 0.;

		strcpy(this->fname, "");
		strcpy(this->lname, "");
	}

	Abonent (int phone_num, int contract_num, double min_rate, double balance, char fname[], char lname[])
	{
		this->phone_num = phone_num;
		this->contract_num = contract_num;

		this->min_rate = min_rate;
		this->balance = balance;

		strcpy(this->fname, fname);
		strcpy(this->lname, lname);
	}

	/* Функції для задання значень полів	*/

	void setNum (int phone_num) // номер телефона
	{
		this->phone_num = phone_num;
	}
	void setContract (int contract_num) // номер контракту
	{
		this->contract_num = contract_num;
	}
	void setRate (double min_rate) // плата за хвилину
	{
		this->min_rate = min_rate;
	}
	void setBalance (double balance) // баланс
	{
		this->balance = balance;
	}
	void setFname (char fname[]) // зміна імені
	{
		strcpy(this->fname, fname);
	}
	void setLname (char lname[]) // зміна прізвища
	{
		strcpy(this->lname, lname);
		//std::cout << this->lname;
	}

	/* Функції для отримання значень полів	*/
	void getNum ()
	{
		std::cout << phone_num ;
	}
	void getContract ()
	{
		std::cout << contract_num ;
	}
	void getRate (double min_rate) // ціна за хвилину
	{
		std::cout << min_rate ;
	}
	void getBalance () // отримання суми коштів на рахунку
	{
		std::cout << balance ;
	}
	void getFname () // ім'я
	{
		std::cout << fname ;
	}
	void getLname () // прізвище
	{
		std::cout << lname ;
	}
};

