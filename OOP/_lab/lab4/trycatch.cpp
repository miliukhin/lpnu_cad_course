#include <iostream>
#include <cstring>
//boost.lexical_cast c++
using namespace std;

class ClassA{
      // клас, що повідомляє про своє створення та знищення
     public:
      ClassA()
      {
	    char c = 121;
            putchar(c);
     }
     ~ClassA()
     {
          cout << "Bye!" << endl;
     }
};
int func()
{
     int a;
     a = 1; // код помилкової ситуації
     ClassA object;
     if (a==0) throw ("Trouble 1");
     if (a==1) throw ClassA();
     return 0;
}
int main(void)
{
     try
     {
          cout << "Входимо у try-блок" << endl;
          int a=func();
          cout << "Виходимо з try-блокy" << endl;
          cout << "a==" << a << endl;
     }
    catch (const char *message)
     {
	     //if (strcmp(message, "Trouble 1"))
          	cout << "Error ---" << message << endl;
          	//cout << "Error ---" << err_code << endl;
          exit(-1);
     }
     catch (ClassA)
     {
          cout << " ClassA! " << endl;
          exit(-2);
     }
}
