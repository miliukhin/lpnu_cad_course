#include<iostream>
#include <mutex>
#include<thread>
#include<vector>

std::mutex arr_mutex;

void print_matrix (std::vector<std::vector<int>> arr)
{
	for ( int i = 0; i < arr.size(); i++ )
	{
		for ( int j = 0; j < arr[i].size(); j++ )
			std::cout << arr[i][j] << '\t';
		std::cout << std::endl;
	}
}

void square_negatives(std::vector<std::vector<int>> & arr)
{
	std::lock_guard<std::mutex> guard(arr_mutex);
	std::cout << "locked by square_negatives" << std::endl;
	for ( int i = 0; i < arr.size(); i++ )
		for ( int j = 0; j < arr[i].size(); j++ )
			if(arr[i][j] < 0)
			{
				std::cout << arr[i][j] << "^2" << std::endl;
				arr[i][j]*=arr[i][j];
				std::this_thread::sleep_for(std::chrono::seconds(3));
			}
	print_matrix(arr);
}

int non_negative_rows(std::vector<std::vector<int>> & arr)
{
	std::lock_guard<std::mutex> guard(arr_mutex);
	std::cout << "locked by non_negative_rows" << std::endl;
	int cnt = 0;
	bool found = false;
	for ( int i = 0; i < arr.size(); i++ )
	{
		found = false;
		for ( int j = 0; j < arr[i].size(); j++ )
			if(arr[i][j] < 0)
			{
				if(!found)
				{
					cnt++;
					found = true;
					std::cout << "found" << arr[i][j] << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(2));
				}
			}
	}
	std::cout << "rows with no negative numbers: " << (arr.size() - cnt) << std::endl;
	print_matrix(arr);
	return (arr.size() - cnt);
}

int main()
{
	std::vector<std::vector<int>> arr = {
		{1,	-2,	3,	-4,	5,	6},
		{1,	2,	3,	4,	5,	6},
		{1,	2,	3,	4,	-5,	6}
	};
	std::thread t (square_negatives, std::ref(arr));
	std::thread t_neg_count(non_negative_rows, std::ref(arr));

 	t.join();
	t_neg_count.join();
}
