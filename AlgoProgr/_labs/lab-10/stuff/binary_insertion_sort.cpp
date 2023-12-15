#include<iostream>

int binary_search(int a[], int item, int low, int high)
{
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (item == a[mid])
			return mid + 1;
		else if (item > a[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}

void insertion_sort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i) {
		j = i - 1;
		selected = a[i];

		// пошук місця для вставки selected
		loc = binary_search(a, selected, 0, j);

		// Move all elements after location to create space
		while (j >= loc) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

int main()
{
	int a[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	int n = sizeof(a) / sizeof(a[0]), i;

	insertion_sort(a, n);

	std::cout <<"Sorted array: \n";
	for (i = 0; i < n; i++)
		std::cout << a[i] << " ";

	return 0;
}
