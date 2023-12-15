#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include <future>

int from_10_to_300(const std::vector<int> arr)
{
	int count = 0;
	for ( int var : arr )
		if (10 < var && var < 300)
			count++;
	std::cout << std::this_thread::get_id() << std::endl;
	return count;
}

int average_even(const std::vector<int> arr)
{
	int sum = 0;
	int cnt = 0;
	for ( int var : arr )
		if (var%2 == 0)
		{
			sum+=var;
			cnt++;
		}
	std::cout << std::this_thread::get_id() << std::endl;
	return sum/cnt;
}

int main()
{

	std::vector<int> arr = {1, -2, 30, -4, 50, 60};

	int result_10300;
	std::thread t_10300
	(
		[&result_10300, arr]()
		{
			result_10300 = from_10_to_300(arr);
		}
	);
	int result_av;
	std::thread t_av
	(
		[&result_av, arr]()
		{
			result_av = average_even(arr);
		}
	);
	t_10300.join();
	t_av.join();
	std::cout << result_10300 << std::endl;
	std::cout << result_av << std::endl;
}
