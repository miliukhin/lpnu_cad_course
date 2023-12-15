#include <iostream>
#include "../include/hier.h"

B1::B1()
{
	std::cout << "B1 constructor" << std::endl;
	data=30;
}
B1::~B1()
{
	std::cout << "B1 destructor" << std::endl;
}

void B1::show ()
{
	printf("%d", data);
}

B2::B2()
{
	std::cout << "B2 constructor" << std::endl;
	data=30;
}
B2::~B2()
{
	std::cout << "B2 destructor" << std::endl;
}
void B2::show()
{
	std::cout << "B1 constructor" << std::endl;
	std::cout << data << std::endl;
}

D1::D1() : B1(), B2()
{
	std::cout << "D1 constructor" << std::endl;
	data=222;
}

D1::~D1()
{
	std::cout << "D1 destructor" << std::endl;
}

void D1::show()
{
	std::cout << data << std::endl;
}

D2::D2()
{
	std::cout << "D2 constructor" << std::endl;
	data = 50;
}

D2::~D2()
{
	std::cout << "D2 destructor" << std::endl;
}

void D2::show()
{
	std::cout << data << std::endl;
}

D3::D3()
{
	std::cout << "D3 constructor" << std::endl;
	data = 63;
}

D3::~D3()
{
	std::cout << "D3 destructor" << std::endl;
}

void D3::show()
{
	std::cout << data << std::endl;
}

D4::D4()
{
	std::cout << "D4 constructor" << std::endl;
	data = 64;
}

D4::~D4()
{
	std::cout << "D4 destructor" << std::endl;
}

void D4::show()
{
	std::cout << data << std::endl;
}
