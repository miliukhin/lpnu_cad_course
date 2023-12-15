#include "../include/file_manager.h"

FileManager::FileManager() { }
FileManager::FileManager(const char* filename) { this->filename = filename; }

std::string FileManager::readStringFromFile()
{
	std::string input_string;
	std::getline(_stream, input_string, '\n');
	return input_string;
}

void FileManager::openForReading(const char* filename)
{
	_stream.close();
	this->filename = filename;
	_stream.open(filename, std::ios::in);
	if ( !_stream )
		std::cout << "unable to open file";
}

void FileManager::openForWriting(const char* filename)
{
	_stream.close();
	this->filename = filename;
	_stream.open(filename, std::ios::out | std::ios::trunc);
	if ( !_stream )
		std::cout << "unable to open file";
}

void FileManager::write(std::string to_write)
{
	openForWriting(filename.c_str());

	_stream << to_write << std::endl;

	_stream.flush();
	_stream.close();
}

void FileManager::close()
{
	_stream.close();
}
