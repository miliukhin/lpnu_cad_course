#include<iostream>
#include<vector>

std::vector<int> shell_sort(std::vector<int>& a)
{
	for (int gap = a.size()/2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < a.size(); i++)
		{
			for (int j = i; j >= gap && a[j-gap] > a[j]; j -= gap)
				std::swap(a[j], a[j-gap]);
		}
	}
	return a;
}

int main()
{
	std::vector<int> vec = {12, 19, 2, 329, 1, 23 };

	for(int val : vec)
		std::cout << val << std::endl;
	std::cout << std::endl;

	shell_sort(vec);

	for(int val : vec)
		std::cout << val << std::endl;
	std::cout << std::endl;
}
