#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // відкриваємо вхідний та вихідний файли
    ifstream fin("file_input.txt");
    ofstream fout("file_output.txt");

    // копіюємо вміст вхідного файла у вихідний
    fout << fin.rdbuf();

    // повертаємо покажчик на початок файлу
    fin.seekg(0);

    // читаємо вміст вхідного файла у змінну input
    string input;
    getline(fin, input);

    // рахуємо кількість відкритих та закритих дужок
    int open_brackets = count(input.begin(), input.end(), '(') +
                        count(input.begin(), input.end(), '[');
    int close_brackets = count(input.begin(), input.end(), ')') +
                         count(input.begin(), input.end(), ']');

    // перевіряємо, чи співпадає кількість відкритих та закритих дужок
    if (open_brackets == close_brackets) {
        cout << "Кількість відкритих та закритих дужок співпадає." << endl;
        fout << "Кількість відкритих та закритих дужок співпадає." << endl;
    } else {
        cout << "Кількість відкритих та закритих дужок не співпадає." << endl;
        fout << "Кількість відкритих та закритих дужок не співпадає." << endl;
    }

    // знаходимо найдовше слово
    string longest_word = "";
    string current_word = "";
    for (char c : input) {
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

    cout << "Найдовше слово: " << longest_word << endl;
    fout << "Найдовше слово: " << longest_word << endl;

    // видаляємо всі слова, що складаються тільки з латинських літер
    string output = "";
    for (char c : input) {
        if (c == ' ') {
            if (all_of(output.begin(), output.end(), [](char c) {
                    return isalpha(c) && islower(c);
                })) {
                output = "";
                continue;
            }
            fout << output << " ";
            output = "";
        } else {
        output += c;
    }
}
if (all_of(output.begin(), output.end(), [](char c) {
        return isalpha(c) && islower(c);
    })) {
    output = "";
}
fout << output << endl;

// закриваємо файли
fin.close();
fout.close();

return 0;
}
