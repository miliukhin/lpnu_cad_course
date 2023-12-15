#include <cereal/archives/json.hpp>
#include <iostream>
#include <fstream>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <string>
#include "../include/sweet_roll.h"

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

Warez::Warez() {};
Warez::~Warez() {};

void Warez::add_ware(Ware ware)
{
	wares.push_back(ware);
}
void Warez::show_ware(int i)
{
	wares.at(i).print_all();
}

SweetRoll::~SweetRoll()
{
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

void test_container ()
{
	SweetRoll roll;

	ObjectStore<SweetRoll> uuu;
	uuu.add(roll);
	uuu.show_ware(0);
	std::cout << "------" << std::endl;

	std::ofstream fout("storage");
	{
  		cereal::JSONOutputArchive output(fout);
		output(uuu);
	}

	ObjectStore<SweetRoll> duh;
	std::ifstream fin("storage", std::ios::in);
	{
		cereal::JSONInputArchive iarchive(fin);
		iarchive(duh);
	}
	fin.close();
	duh.show_ware(0);
	std::cout << "------" << std::endl;
}

void test_warez()
{
	Ware wra;
	Ware dwa;

	Warez bruh;
	bruh.add_ware(dwa);

	bruh.show_ware(0);

	std::ofstream fout("storage");
	{
  		cereal::JSONOutputArchive output(fout);
		output(bruh);
	}
	fout.close();

	Warez duh;

	std::ifstream fin("storage", std::ios::in);
	{
		cereal::JSONInputArchive iarchive(fin);
		iarchive(duh);
	}
	fin.close();

	duh.show_ware(0);
}

int main()
{
	test_container();
	test_warez();
}
