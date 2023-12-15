#include <iostream>
#include <fstream>

using namespace std;

int main () {

ofstream fout;
fout.open("test.txt",ios::app);
if (fout.is_open())
{
fout << "Hi!!!";
fout.close();
} else
{
cout << "Ошибка!!!\n";
return 0;
}

}
