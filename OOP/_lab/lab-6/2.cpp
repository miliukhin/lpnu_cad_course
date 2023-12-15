#include<vector>
#include<stack>
#include<iostream>
#include<memory>

bool is_safe( std::vector<std::vector<int>> arr, int x, int y)
{
	if (x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && arr[x][y] == 1)
		return true;
	return false;
}

bool find_path(
		std::vector<std::vector<int>> arr,
		int start_x,
		int start_y,
		int end_x,
		int end_y
	)
{
	std::unique_ptr<std::stack<std::pair<int, int>>> meow(new std::stack<std::pair<int, int>>);

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	meow->push({start_x, start_y});

	std::cout << "\033[32;1;1m+[" << meow->top().first << ", ";
	std::cout << meow->top().second << "]\n" ;
	arr[start_x][start_y] = 0; // відмічаємо, що цю точку відвідали

	while (!meow->empty()) {


    		int x = meow->top().first;
    		int y = meow->top().second;
    		if (x == end_x && y == end_y)
		{
        		meow->push({x, y});
        		return true;
    		} else

    		for (int i = 0; i < 4; i++)
		{
        		int next_x = x + dx[i];
        		int next_y = y + dy[i];

        		if (is_safe(arr, next_x, next_y))
			{
            			meow->push({next_x, next_y});

				std::cout << "\033[32;1;1m+[" << meow->top().first << ", ";
				std::cout << meow->top().second << "]\n" ;

            			arr[next_x][next_y] = 0;
				break;
        		} else if (i == 3)
			{
				std::cout << "\033[31;1;1m-[" << meow->top().first << ", ";
				std::cout << meow->top().second << "]\n" ;
				meow->pop();
			}
    		}
	}

	std::cout << "Шлях не знайдено\n";
	return false;
}

void print_matrix(std::vector<std::vector<int>> arr)
{
	std::cout << "   ";
	for(int i = 0; i < arr[0].size(); i++)
		std::cout << i << " ";
	std::cout << '\n';
	std::cout << "  ";
	for(int i = 0; i < arr[0].size(); i++)
		std::cout << "--";
	std::cout << '\n';
	for(int i = 0; i < arr.size(); i++)
	{
		std::cout << i << " |";
		for(int j = 0; j < arr[0].size(); j++)
			std::cout << arr[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << '\n';
}

int main()
{

	std::vector<std::vector<int>> arr =
	{
		{1,0,0,0,1,1,1},
		{1,1,1,0,1,0,1},
		{1,0,1,1,1,1,1},
		{1,0,1,0,1,0,0},
		{1,0,1,1,1,1,1},
	};

	print_matrix(arr);

	find_path(arr, 0, 0, 4, 6);
	return 0;
}
