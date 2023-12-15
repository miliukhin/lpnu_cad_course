#include<iostream>
#include<list>

int main ()
{
	std::list<char> test_list;

	for (int i = 0; i <= test_list.size(); i++)
		test_list.push_back(42);

	for (int i = 0; i < test_list.size(); i++)
	{
		auto it = std::next(test_list.begin(), i);
		//std::cout << it << std::endl;
	}
}
