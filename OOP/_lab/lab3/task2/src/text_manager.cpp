#include "../include/text_manager.h"
#include <algorithm>
#include <string>

TextContainer::TextContainer(const char* text)
{
	data = text;
}

TextContainer::TextContainer() { }

TextManager::TextManager ()
{
}
TextManager::TextManager (std::string text)
{
	_text.data = text;
}
/* - копіює вміст вхідного файла у вихідний; */
std::string TextManager::get_text ()
{
	return _text.data;
}
/* - перевіряє, чи співпадає кількість відкритих і закритих дужок у введеному рядку() [] */
bool TextManager::compare_brackets ()
{
	int open_brackets = count(_text.data.begin(), _text.data.end(), '(') +
		count(_text.data.begin(), _text.data.end(), '[');
	int close_brackets = count(_text.data.begin(), _text.data.end(), ')') +
		count(_text.data.begin(), _text.data.end(), ']');

	if (open_brackets == close_brackets)
		return true;
	else
		return false;
}
/* - знаходить найдовше слово; */
std::string TextManager::find_longest_word ()
{
	std::string longest_word = "";
	std::string current_word = "";
	for (char c : _text.data) {
		if (c == ' ') {
			if (current_word.length() > longest_word.length()) {
				longest_word = current_word;
			}
			current_word = "";
		} else {
			current_word += c;
		}
	}
	if (current_word.length() > longest_word.length()) {
		longest_word = current_word;
	}
	/* std::cout << longest_word << std::endl; */
	return longest_word;
}

/* видаляє всі слова, що складаються тільки з латинських літер */
std::string TextManager::delete_latin ()
{
	std::string temp = "";
	std::string result = "";

	for (char c : _text.data) {
		if (c == ' ') {
		if (all_of(temp.begin(), temp.end(), [](char c) { return isalpha(c); } ) )
		{
			temp = "";
			continue;
		}
			//std::cout << temp << " ";
			result += temp + " ";
			temp = "";
		}
		else
		{
			temp += c;
		}
	}
	return result;
}
