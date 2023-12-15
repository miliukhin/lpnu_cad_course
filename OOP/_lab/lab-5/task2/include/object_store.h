#include <fstream>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/string.hpp>

template<typename T>
class ObjectStore
{
	std::vector<T> objects;

public:
	void add(T obj)
	{
		objects.push_back(obj);
	}

	void remove(T obj)
	{
		auto it = std::find(objects.begin(), objects.end(), obj);
		if (it != objects.end())
		{
			objects.erase(it);
		}
	}

	void show_ware(int i)
	{
		objects.at(i).print_all();
	}

	std::vector<T> getObjects() const
	{
		return objects;
	}

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive ( CEREAL_NVP(objects) );
	}

	void write_to_file ()
	{
		std::ofstream fout("storage");
		{
  			cereal::JSONOutputArchive output(fout);
			output(objects);
		}
	}

	void read_from_file ()
	{
		std::ifstream fin("storage", std::ios::in);
		{
			cereal::JSONInputArchive iarchive(fin);
			iarchive(objects);
		}
		fin.close();
	}
};

