#include <iostream>
using namespace std;

class Gun
{
	public:
	virtual void Shoot() // final забороняє змінювати
	{
		cout << "wqorqwur" << endl;
	}

};

class Mgun:public Gun
{
	public:
	void Shoot() override
	{
		cout << "uirqw" << endl;
	}

};

int main()
{
	Gun gun;
	gun.Shoot();

	Mgun mgun;
	mgun.Shoot();
}
