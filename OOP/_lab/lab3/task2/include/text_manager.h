#include <iostream>

class TextContainer
{
public:
	std::string data;
	TextContainer();
	TextContainer(const char* text);
};

class TextManager
{
	TextContainer _text;

public:
	TextManager(std::string text);
	TextManager();

   /* - копіює вміст вхідного файла у вихідний; */
	std::string get_text ();
   /* - перевіряє, чи співпадає кількість відкритих і закритих дужок у введеному рядку  () [] */
	bool compare_brackets ();
   /* - знаходить найдовше слово; */
	std::string find_longest_word ();
   /* видаляє всі слова, що складаються тільки з латинських літер */
	std::string delete_latin ();
};

