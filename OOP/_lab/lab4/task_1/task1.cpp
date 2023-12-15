#include <iostream>
#include <boost/lexical_cast.hpp>
#include <bits/stdc++.h>

using boost::lexical_cast;
using boost::bad_lexical_cast;

/*
   Визначити обробник виняткової ситуації,
   яка виникає при перетворенні об’єкта
   класу у значення цілочисельного типу.
*/

class TestClass{
	std::string c;

	public:
	TestClass() {}
	~TestClass() {}

	void assign_value(std::string input);
	std::string get_string()
	{
		return c;
	}
};

void TestClass::assign_value (std::string input)
{
	try
	{
		int num = lexical_cast<int>(input);
	}
	catch (bad_lexical_cast &e)
	{
    		std::cout << e.what() << std::endl;
	}
}

void checks()
{
	TestClass object;
	object.assign_value(object.get_string());
}
int main()
{
	checks();
}
