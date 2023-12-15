#include <iostream>
#include <string>
#include <math.h>
#define PI 3.14159
using namespace std;
/*Оголошуємо клас complex. Усередині класу вказані лише
прототипи методів, а самі функіїи описані за межами класу
*/
class complex
{
public:

complex(); //Прототип конструктора класу

double modul(); //Прототип метода modul()

double argument(); //Прототип метода argument()

private:

double x;

double y;

void show_complex(); //Прототип метода show_complex()
};
int main()
{
/*Описуємо екземпляр класу, під час виконання
програми після створення змінної автоматично викликається
конструктор */

complex chyslo;

cout << "Modul kompleksnogo chysla=" <<
chyslo.modul();

cout << endl << "Argument kompleksnogo chysla = " <<
chyslo.argument() << endl;

return 1;
}

//Текст функції конструктор класса complex
complex::complex()
{
	cout << "Vvedit x\t";
	cin >> x;
	cout << "Vvedit y\t"; cin >> y;
	show_complex();
}
//Текст метода modul класу complex
double complex::modul()
{
return pow(x * x + y * y, 0.5);
}
//Текст метода argument класу complex
double complex::argument()
{
return atan2(y, x) * 180 / PI;
}
//Текст метода show_complex класса complex.
void complex::show_complex()
{
	if (y >= 0) cout << x << "+" << y << "i" << endl;
	else cout << x << y << "i" << endl;
}
