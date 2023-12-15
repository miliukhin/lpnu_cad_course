void test()
{
	List<char> list;
	list.push_back('X');
	list.push_back(10);
	list.push_back('Z');

	int x_index = -1;
	int z_index = -1;

	for (int i = 0; i < list.getSize(); i++)
		if(list[i] == 'X' && z_index < 0)
			std::cout << "dupa";
		else if(list[i] == 'Z' && x_index > -1)
			z_index = i;
		else
			continue;
	std::cout << x_index << "\t" << z_index << std::endl;


	int number_count = 4;

	std::cout << std::endl;
	for (int i = 0; i < number_count; i++)
		list.push_back(rand()%10);

	std::cout << "no_pep_front" << std::endl;
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	std::cout << "pep_front" << std::endl;

	list.pop_front();
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	std::cout << "push_front" << std::endl;
	list.push_front(rand()%10);
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	std::cout << "insert" << std::endl;
	list.insert(1, 3);
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	std::cout << "remove" << std::endl;
	list.remove_at(3);
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	std::cout << "delete_between_x_z" << std::endl;
	list.delete_between_x_z();
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	list.clear();
}
