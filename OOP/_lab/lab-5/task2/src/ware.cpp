#include "../include/ware.h"

Ware::~Ware() {};

void Ware::set_name(std::string name)
{
	this->name = name;
}
void Ware::set_weight(int weight)
{
	this->weight = weight;
}
void Ware::set_price(int price)
{
	this->price = price;
}
void Ware::set_quantity(int quantity)
{
	this->quantity = quantity;
}

void Ware::print_name()
{
	std::cout << name << std::endl;
}
void Ware::print_weight()
{
	std::cout << weight << std::endl;
}
void Ware::print_price()
{
	std::cout << price << std::endl;
}
void Ware::print_quantity()
{
	std::cout << quantity << std::endl;
}
void Ware::print_all()
{
	print_name();
	print_weight();
	print_price();
	print_quantity();
}
