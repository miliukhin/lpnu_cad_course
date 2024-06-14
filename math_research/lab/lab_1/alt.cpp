#include <vector>
#include <iostream>
/* #define debug */

std::vector<int> altlist = {
	95, 39, 49, 20, 67, 26, 63, 77, 96, 81, 65, 60, 36, 55, 70, 18, 11, 42, 32, 96
};

#define LOOP for (int i=0; i < q1.size(); ++i) { bool add_it = true; for (int j=0; j < q2.size(); ++j) {

std::vector<int> pareto (std::vector<int> q1, std::vector<int> q2) {
	std::vector<int> pareto_list;
	for (int i=0; i < q1.size(); ++i) {
		bool add_it = true;
		for (int j=0; j < q2.size(); ++j) {
			if(i != j
					&& q1[j] >= q1[i]
					&& q2[j] >= q2[i]
					&& (q1[j] > q1[i] || q2[j] > q2[i])) {
				add_it = false;
				break;
			}
		}
		if (add_it)
			pareto_list.push_back(i);
	}
	return pareto_list;
}

std::vector<int> slater (std::vector<int> q1, std::vector<int> q2) {
	std::vector<int> slater_list;
	LOOP
			if(i != j
					&& q1[j] > q1[i]
					&& q2[j] > q2[i]) {
				add_it = false;
				break;
			}
		}
		if (add_it)
			slater_list.push_back(i);
	}
	return slater_list;
}

int main() {
	std::vector<int> q1_list;
	std::vector<int> q2_list;
	for (int i = 0; i < altlist.size(); ++i)
	{
		q1_list.push_back(altlist[i] / 10);
		q2_list.push_back(altlist[i] % 10);
#ifdef debug
		std::cout << altlist[i] << ' ';
		std::cout << q1_list[i] << ' ';
		std::cout << q2_list[i] << '\n';
#endif
	}
	std::vector<int> pareto_list = pareto(q1_list, q2_list);
	std::vector<int> slater_list = slater(q1_list, q2_list);

	for (int i = 0; i < pareto_list.size(); ++i) {
		std::cout << '\n' ;
		std::cout << '\t' << q1_list[pareto_list[i]] << q2_list[pareto_list[i]] ;
	}
	std::cout << '\n';
	for (int i = 0; i < slater_list.size(); ++i) {
		std::cout << '\n' ;
		std::cout << '\t' << q1_list[slater_list[i]] << q2_list[slater_list[i]] ;
	}
}
