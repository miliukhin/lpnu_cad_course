#include <iostream>
#include <algorithm>
#include <vector>

void counting_sort(std::vector<int>& vec)
{
	int min_val = *std::min_element(vec.begin(), vec.end());
	int max_val = *std::max_element(vec.begin(), vec.end());

	int shift = std::abs(min_val);
	for (int& val : vec)
	{
		val += shift;
	}

	std::vector<int> count(max_val + shift + 1, 0);

	for (int val : vec)
		count[val]++;

	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i-1];
	}

	std::vector<int> sorted(vec.size());
	for (int val : vec)
	{
		sorted[count[val]-1] = val - shift;
		count[val]--;
	}

	std::copy(sorted.begin(), sorted.end(), vec.begin());
}

int main()
{
	std::vector<int> vec = {0, 21, -3, 0, -11, 31, 2, -64, 1, -4};
	counting_sort(vec);

	for (int val : vec)
		std::cout << val << " ";

	return 0;
}
