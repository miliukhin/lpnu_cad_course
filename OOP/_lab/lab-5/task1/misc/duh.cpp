#include <iostream>
using namespace std;

class A
{
	public:
		string msgOne = "bruh";
	private:
		string msgTwo = "bruh";
	protected:
		string msgThree = "bruh";
};

class B : public A
{
	public:
		void PrintMsg()
		{
			cout << msgOne << endl;
			cout << msgThree << endl;
		}
};

int main()
{
	B b;
	b.PrintMsg();

	return 0;
}
