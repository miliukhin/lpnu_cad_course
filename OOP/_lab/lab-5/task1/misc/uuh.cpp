// Приведення вказівників похідного класу до базового
#include<iostream>
using namespace std;
class A
{

int data;
public:

void ShowA()

{


cout << data << endl;

}
};

class C : public A
{

int data2;
public:

void showC()

{


cout << data2 << endl;

}
};

int main()
{

A* pta;

C c;

pta = &c;

pta->ShowA();
}
