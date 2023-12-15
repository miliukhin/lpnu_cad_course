#include <iostream>
#include "vector.h"

int main()
{
	Vector test(1, 1);
	Vector testt(2, 0);

	Vector res = test + testt;

	std::cout << res.getX() << '\t';
	std::cout << res.getY() << std::endl;

	Vector res2 = test - testt;

	std::cout << res2.getX() << '\t';
	std::cout << res2.getY() << std::endl;

	return res < res2;
}
