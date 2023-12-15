#include <iostream>
#include <string>
#include "../include/abonent.h"
using namespace std;

/*/=================================
class Abonents {
private:
    static const int MAX_ABONENTS = 100;
    Abonent abonents[MAX_ABONENTS];
    int count;
    int max_count;

public:
    Abonents() {
        count = 0;
        max_count = MAX_ABONENTS;
    }

    Abonents(int mc) {
        count = 0;
        max_count = mc;
    }

    void addAbonent(Abonent a) {
        if (count < max_count) {
            abonents[count++] = a;
            cout << "Abonent added successfully." << endl;
        }
        else {
            cout << "Unable to add abonent. Maximum capacity reached." << endl;
        }
    }

    void editAbonent(int index) {
        if (index < count) {
            Abonent a = abonents[index];

            string cn, sn, n, pn;
            double cr, ab;

            cout << "Enter contract number: ";
            getline(cin, cn);
            a.setContractNum(cn);

            cout << "Enter surname: ";
            getline(cin, sn);
            a.setSurname(sn);

            cout << "Enter name: ";
            getline(cin, n);
            a.setName(n);

            cout << "Enter phone number: ";
            getline(cin, pn);
            a.setPhoneNum(pn);

            cout << "Enter call rate: ";
            cin >> cr;
            a.setCallRate(cr);

            cout << "Enter account balance: ";
            cin >> ab;
            a.setAccountBalance(ab);

  //          abonents[index] = a; AAAAAAAA
	}
    }
};

//======================================*/

class Abonents {
private:
    static const int MAX_SIZE = 100;
    Abonent abonents[MAX_SIZE];
    int realSize;

public:
    Abonents() {
        realSize = 0;
    }

    void addAbonent(const Abonent& abonent) {
        if (realSize >= MAX_SIZE) {
            std::cout << "Error: the maximum number of abonents has been reached" << std::endl;
            return;
        }
        abonents[realSize] = abonent;
        realSize++;
    }

    void editAbonent(int index, const Abonent& abonent) {
        if (index < 0 || index >= realSize) {
            std::cout << "Error: invalid index" << std::endl;
            return;
        }
        abonents[index] = abonent;
    }

    void removeAbonent(int index) {
        if (index < 0 || index >= realSize) {
            std::cout << "Error: invalid index" << std::endl;
            return;
        }
        for (int i = index; i < realSize - 1; i++) {
            abonents[i] = abonents[i + 1];
        }
        realSize--;
    }

    void printAbonent(int index) {
        if (index < 0 || index >= realSize) {
            std::cout << "Error: invalid index" << std::endl;
            return;
        }
        std::cout << "Abonent #" << index << std::endl;
        abonents[index].printAbonent();
    }

    void printAllAbonents() {
        std::cout << "All abonents:" << std::endl;
        for (int i = 0; i < realSize; i++) {
            std::cout << "Abonent #" << i << std::endl;
            abonents[i].printAbonent();
            std::cout << std::endl;
        }
    }
/*
    void sortAbonentsByLastName() {
        std::sort(abonents, abonents + realSize, [](const Abonent& a, const Abonent& b) {
            return a.getLastName() < b.getLastName();
        });
    }
    */

    void printAbonentsWithNegativeBalance() {
        std::cout << "Abonents with negative balance:" << std::endl;
        for (int i = 0; i < realSize; i++) {
            if (abonents[i].getAccountBalance() < 0) {
                std::cout << "Abonent #" << i << std::endl;
                abonents[i].printAbonent();
                std::cout << std::endl;
            }
        }
    }
};

int main ()
{
	Abonent mume;
	mume.printAbonent();

	return 0;
}
