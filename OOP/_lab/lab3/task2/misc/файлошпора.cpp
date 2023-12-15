#include <iostream>
#include <fstream>

int main ()
{
	std::fstream fout;

	fout.open("testfile");				// створить новий файл, якщо нема; є --- перезапише
	fout.open ("testfile", std::ios::app);		// допише (append)
	fout.open ("testfile", std::ios::ate);		// пошук потрібних даних починає з кінця файлу
	fout.open ("testfile", std::ios::binary);	// двійковий
	fout.open ("testfile", std::ios::in);		// для введення
	fout.open ("testfile", std::ios::out);		// для виведення
	fout.open ("testfile", std::ios::trunc);	// призводить до руйнування вмісту???

	fout << "DUHHHHHHHHHHHHHHHHH" << std::endl;

	fout.close();

	std::ofstream miu("testfile");

	std::ifstream fin; fin.open("testfile");

	if (! fin) // або (! fin.is_open ())
	{
		std::cout << "Помилка !!!\n";
		return 1;
	}

	int x, f;

	fin >> x >> f; // читання з файлу // числових даних


	return 0;
}
