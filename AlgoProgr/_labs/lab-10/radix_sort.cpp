#include <iostream>
#include <vector>
#include <cmath>

// Функція для отримання цифри в розряді
int get_digit(int num, int pos)
{
	return num / (int)pow(10, pos) % 10;
}

// виконання сортування підрахунком з використанням указаного розряду
void count_sort(std::vector<int>& arr, int exp)
{
	std::vector<int> count(10, 0);
	std::vector<int> output(arr.size());

	for (int i = 0; i < arr.size(); i++)
	{
		count[get_digit(arr[i], exp)]++;
	}

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		int digit = get_digit(arr[i], exp);
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}

	std::copy(output.begin(), output.end(), arr.begin());
}

void radix_sort(std::vector<int>& arr)
{
	int max = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	// Сортування кожного розряду
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(arr, exp);
	}
}

int main()
{
	std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66, 18};

	std::cout << "Original array:\t";
	for (int val : arr)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	radix_sort(arr);

	std::cout << "Sorted array:\t";
	for (int val : arr)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	return 0;
}
