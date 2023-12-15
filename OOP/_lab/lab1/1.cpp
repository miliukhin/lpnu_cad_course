#include <iostream> // директива, що заміняє себе на заголовний файл iostream
#define N 255
using namespace std;

int main() // головна функція
{
	// декларація масивів символів для подальшої роботи
	char lname[N], fname[N], mname[N], group[N], variant[N];;

	//	послідовні виведення та виведення відповідних даних
	cout << "Прізвище:\n";
	cin >> lname; // запис даних зі стандартного потоку вводу у масив lname
	cout << "Ім'я:\n";
	cin >> fname;
	cout << "По батькові:\n";
	cin >> mname;

	cout << "Група:\n";
	cin >> group;

	cout << "Варіант:\n";
	cin >> variant;

	// вивід тексту та введених раніше даних
	cout << lname << " " << fname << " " << mname
		<< ", група " << group
		<< ", варіант №" << variant
		<< ", Лабораторна робота №1. Знайомство та налаштування "
		"програмного середовища Microsoft Visual Studio\n";

	return 0;
}
