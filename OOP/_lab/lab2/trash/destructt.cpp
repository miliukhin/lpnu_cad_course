class MyClass
{int data;
public :
…
// Конструктор класу
MyClass (int value)
{
data=value;
cout <<"Об’єкт"<<data<< "Виклик конструктора" << endl;
}
~MyClass()
{cout <<"Об’єкт"<<data<< "Виклик деструктора" << endl;
}};
void Foo()
{cout << "Foo початок роботи" << endl;
MyClass a(1);
cout << "Foo кінець роботи" << endl;
}
int main (){
Foo;
return 0;
