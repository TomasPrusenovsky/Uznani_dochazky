#include "vztahy.h"
#include <iostream>

Student::Student(std::string j)
    : jmeno(j)
{
}

Kniha::Kniha(std::string n)
    : nazev(n)
{
}

void Knihovna::pridejKnihu(Kniha* k)
{
    knihy.push_back(k);
}

void MotorV::bezi()
{
    std::cout << "Motor bezi" << std::endl;
}

void Vuz::start()
{
    motor.bezi();
}

void Ucitel::priradStudenta(Student* s)
{
    student = s;
}

void Ucitel::vypisStudenta()
{
    if (student)
        std::cout << "Student: " << student->jmeno << std::endl;
}

void ukazkaVztahy()
{
    std::cout << "\n=== VZTAHY MEZI OBJEKTY ===" << std::endl;
    Kniha k("C++ navod");
    Knihovna knihovna;
    knihovna.pridejKnihu(&k);
    std::cout << "Agregace: knihovna obsahuje knihu" << std::endl;

    Vuz auto1;
    auto1.start();

    Student s("Jan");
    Ucitel u;
    u.priradStudenta(&s);
    u.vypisStudenta();
}