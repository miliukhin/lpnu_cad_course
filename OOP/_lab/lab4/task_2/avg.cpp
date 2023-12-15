#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

double average(std::vector<double> nums) {
	double sum = 0;
	int count = 0;

	for (double num : nums) {
		if (num > 0) {
			sum += num;
			count++;
		}
	}

	if (count == 0) {
		throw std::runtime_error("input contains no positive numbers");
	}

	return sum / count;
}

int main(int argc, char** argv) {
	std::vector<double> nums = {};

	for (int i = 0; i < argc; i++)
	{
		double temp = atof(argv[i]);
		nums.push_back(temp);
	}

	try {
		double avg = average(nums);
		std::cout << avg << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Bruh: " << e.what() << std::endl;
	}

	return 0;
}
