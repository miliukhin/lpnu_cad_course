#include <iostream>
#include <vector>

void binaryInsertionSort(std::vector<int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int x = vec[i];
		int j = i - 1;

		int l = 0, r = j;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (vec[mid] > x)
				r = mid - 1;
			else
				l = mid + 1;
		}
		j = l;

		// зсув управо, щоб дати місце x
		while (j <= i)
		{
			int temp = vec[j];
			vec[j] = x;
			x = temp;
			j++;
		}
	}
}

int main()
{
	std::vector<int> vec = {5, 2, 6, 8, 1, 3};

	binaryInsertionSort(vec);

	std::cout << "Sorted array: ";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
