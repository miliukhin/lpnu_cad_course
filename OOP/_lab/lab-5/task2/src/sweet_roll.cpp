#include "../include/sweet_roll.h"

SweetRoll::~SweetRoll()
{
}

bool SweetRoll::operator==(SweetRoll roll)
{
	return (this->name == roll.name);
}

void SweetRoll::print_sweetness()
{
	std::cout << sweetness << std::endl;
}
void SweetRoll::print_stolen()
{
	std::cout << stolen << std::endl;
}

void SweetRoll::print_all()
{
	print_name();
	print_weight();
	print_price();
	print_quantity();
	print_sweetness();
	print_stolen();
}

void SweetRoll::set_sweetness(int sweetness)
{
	this->sweetness = sweetness;
}
void SweetRoll::set_stolen(bool stolen)
{
	this->stolen = stolen;
}
