#include <cctype>
#include<list>
#include<iostream>
#include<fstream>

template<typename F>
double average (std::list<F> lst)
{
	double sum = 0;
    	for (auto v : lst)
	{
        	std::cout << v << " ";
		sum += v;
	}
	std::cout << std::endl;
	return sum/lst.size();
}

bool is_number(const std::string& s){
    return !s.empty() && s.find_first_not_of("+-.0123456789") == std::string::npos;
}

int main()
{
	std::fstream fin("uru", std::ios::in);
	std::list<double> lst;

	std::string temp;
	int err_counter=0;
	while(fin >> temp)
	{
		if(is_number(temp))
		{
			lst.push_back(std::stod(temp));
		}
		else
			err_counter++;
	}
	if(err_counter!=0)
		std::cout << "ignoring " << err_counter << " non-numeric character[s]\n";

    	for (auto v : lst)
	{
        	std::cout << v << " ";
	}
	std::cout << std::endl;

	lst.sort( [](double a, double b){ return a>b; });

	int n = lst.size();
	for(int i = 0; i < n - 10; i++)
		lst.pop_back();

	std::cout << average(lst);

	return 0;
}
