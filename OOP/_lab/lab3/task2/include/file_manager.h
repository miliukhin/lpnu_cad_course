#include <iostream>
#include <fstream>

class FileManager
{
	std::fstream _stream;
	std::string filename;

public:
	FileManager();
	FileManager(const char* filename);

	std::string readStringFromFile();

	void openForReading		(const char* file_name);
	void openForWriting		(const char* filename);
	void close			();
	void write			(std::string to_write);
};

