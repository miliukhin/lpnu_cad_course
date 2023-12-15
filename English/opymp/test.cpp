#include<iostream>
int main()

{
float result = 1;
for (int a = 0; a < 17; a +=5)
{
	result = result * (a < 10? 2:1.5);
}
	std::cout << result;
}
