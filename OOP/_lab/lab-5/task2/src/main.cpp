#include <cereal/archives/json.hpp>
#include <iostream>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <string>

#include "../include/sweet_roll.h"
#include "../include/object_store.h"

void test_container ()
{
	SweetRoll roll;
	SweetRoll roll_2("roll_2", 123, 4298, 48, 842, true);

	ObjectStore<SweetRoll> uuu;
	uuu.add(roll);
	uuu.add(roll_2);
	uuu.show_ware(0);
	uuu.show_ware(1);
	std::cout << "------" << std::endl;
	uuu.write_to_file();
	uuu.remove(roll);
	uuu.show_ware(0);
	std::cout << "------" << std::endl;

	ObjectStore<SweetRoll> duh;
	duh.read_from_file();

	duh.show_ware(0);
	std::cout << "------" << std::endl;
}

int main()
{
	test_container();
	return 0;
}
