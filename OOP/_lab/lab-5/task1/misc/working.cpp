#include <iostream>
#include <fstream>
using namespace std;

class A
{
	public:

	int x;

	protected:

	int y;

	private:

	int z;
	public:

	// конструктор класу А, виконується ініціалізація полів класу

	A(){};
	A(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};
};

class B: public A
{

	int data;
	public:

	// конструктор класу В, виконується виклик конструктора батьківського класу

	// та ініціалізація поля класу В

	B(){};
	B(int _x, int _y, int _z, int _data) : A(_x, _y,
	_z), data(_data) {};

	void PrintData()

	{
		cout << x << '\n'; // доступно, бо в базовому класі специфікатор public

		cout << y << '\n'; // доступно, бо в базовому класі специфікатор protected
		//
		/* cout << z << '\n'; // не доступно, бо в базовому класі специфікатор private */

		cout << data << '\n';
	}
};

class C: public B
{

	int data;
	public:

	// конструктор класу В, виконується виклик конструктора батьківського класу

	// та ініціалізація поля класу В

	C() : B() {};
	C(int _x, int _y, int _z, int _data) : B(_x, _y, _z, _data) {};

};

int main()
{

B b1(1,2,3,4);
C c1(9,9,9,9);

b1.x=5; //поле х доступно для об’єкту класа B

ofstream file1;
file1.open( "Employee.txt", ios::app );

file1.write( (char*)&c1, sizeof(c1) );
file1.close();

C c2;

ifstream file2;
file2.open( "Employee.txt", ios::in );
file2.read( (char*)&c2, sizeof(c2) );

file2.close();

/* b1.y=4; //поле у не доступно для об’єкту класа B */
/* b1.z=3; //поле у не доступно для об’єкту класа B */

b1.PrintData();
c1.PrintData();

c2.PrintData();

return 0;
}
