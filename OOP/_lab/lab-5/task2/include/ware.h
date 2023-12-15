#include <cereal/cereal.hpp>

class Ware
{
	std::string name;
	int weight;
	int price;
	int quantity;

	public:

	Ware
	(
		std::string _name = "ware",
		int _weight = 0,
		int _price = 0,
		int _quantity = 1
	) :
		name (_name),
		weight(_weight),
		price(_price),
		quantity(_quantity)
	{};

	virtual ~Ware();


	void set_name(std::string name);
	void set_weight(int weight);
	void set_price(int price);
	void set_quantity(int quantity);

	void print_name();
	void print_weight();
	void print_price();
	void print_quantity();
	virtual void print_all();

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive (
			CEREAL_NVP(name),
			CEREAL_NVP(weight),
			CEREAL_NVP(price),
			CEREAL_NVP(quantity)
		);
	}
};

