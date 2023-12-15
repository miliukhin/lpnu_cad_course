#include "ware.h"

class SweetRoll : public Ware
{
	std::string name;
	int weight;
	int price;
	int quantity;

	bool stolen;
	int sweetness;

	public:
	SweetRoll
	(
		std::string _name = "roll",
		int _weight = 3,
		int _price = 25,
		int _quantity = 1,
		int _sweetness = 100,
		bool _stolen = false
	) :
		Ware{_name, _weight, _price, _quantity},
		name(_name),
		sweetness(_sweetness),
		stolen(_stolen)
	{};

	bool operator== (SweetRoll roll);

	virtual ~SweetRoll();

	void print_sweetness();
	void print_stolen();

	void set_sweetness(int sweetness);
	void set_stolen(bool stolen);

	virtual void print_all() override;

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive (
			CEREAL_NVP(name),
			CEREAL_NVP(weight),
			CEREAL_NVP(price),
			CEREAL_NVP(quantity),
			CEREAL_NVP(sweetness),
			CEREAL_NVP(stolen)
		);
	}
};

class FileMan
{
	public:

	SweetRoll read_obj_from_file();
	void write_obj_to_file(SweetRoll input_obj);
};

