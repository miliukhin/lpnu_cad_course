#include <iostream>
#include <math.h>
#define PI 3.14159
using namespace std;
class complex
{
//Відкриті методи
public:
	void vvid();
	double modul();
	double argument();
	//Закриті члени і методи
private:
	double x;
	double y;
	void show_complex();
};
//Опис відкритого метода vvod класа complex
void complex::vvid()
{
	cout << "Vvedite x: ";
	cin >> x; cout << "Vvedite y: ";
	cin >> y;
// Виклик закритого метода show_complex із відкритого
//метода vvid show_complex();
}
//Опис відкритого методу modul класса complex
double complex::modul()
{
	return pow(x * x + y * y, 0.5);
}
//Опис відкритого метода argument класса complex
double complex::argument()
{
	return atan2(y, x) * 180 / PI;
}
//Опис закритого метода modul класса complex
void complex::show_complex()
{
	if (y >= 0) cout << x << "+" << y << "i" << endl;
	else cout << x << y << "i" << endl;
}

int main()
{
	complex chyslo;
	chyslo.vvid();
	cout << "Modul kompleksnogo chysla=" <<
	chyslo.modul();
	cout << endl << "Argument kompleksnogo chysla=" <<
	chyslo.argument()
	<< endl;
	system("pause");
	return 0;
}
/* Під час створення в програмі екземпляра класу, формується
вказівник this, в якому зберігається адреса змінної-екземпляра класу. Вказівник
*/
