#include <iostream>
#include <string>

class Human
{
public:
    std::string m_name;
    int m_age;

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

    Human(std::string name = "", int age = 0)
        : m_name(name), m_age(age)
    {
    }
};

// Employee відкрито наслідує Human
class Employee: public Human
{
public:
    int m_wage;
    long m_employeeID;

    Employee(int wage = 0, long employeeID = 0)
        : m_wage(wage), m_employeeID(employeeID)
    {
    }

    void printNameAndWage() const
    {
        std::cout << m_name << ": " << m_wage << '\n';
    }
};

int main()
{
    Employee ivan(350, 787);
    ivan.m_name = "Ivan"; // ми можемо це зробити, тому що m_name є public

    ivan.printNameAndWage();

    return 0;
}
