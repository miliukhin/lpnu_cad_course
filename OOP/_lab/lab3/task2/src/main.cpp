#include <iostream>
#include <fstream>

#include "../include/file_manager.h"
#include "../include/text_manager.h"

int main(int argc, char*  argv[])
{
		FileManager fp;

		fp.openForReading(argv[1]);
		TextManager textus(fp.readStringFromFile());

		fp.openForWriting(argv[2]);
		fp.write( textus.get_text() );

		if(textus.compare_brackets())
			std::cout << "even\n";
		else
			std::cout << "uneven\n";

		std::cout << textus.find_longest_word() << std::endl;
		std::cout << textus.delete_latin() << std::endl;
}
