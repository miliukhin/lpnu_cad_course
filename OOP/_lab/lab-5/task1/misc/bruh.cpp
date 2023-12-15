class Base {
private:
int x;
public:
void mf1();
void mf1(double);};
class Derived : public Base {
public:
using Base::mf1;
void mf1();};
int x;

d.mf1(); // викликається Derived::mf1
d.mf1(x); // викликається Base::mf1(double)
