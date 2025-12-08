#include "vztahy.h"
#include <iostream>
#include <memory>
#include <utility>

Student::Student(std::string j)
    : jmeno(std::move(j))
{
}

Ucitel::Ucitel()
    : student(nullptr)
{
}

void Ucitel::priradStudenta(Student* s)
{
    student = s;
}

void Ucitel::vypisStudenta()
{
    if (student)
        std::cout << "Ucitel zna studenta: " << student->jmeno << std::endl;
    else
        std::cout << "Ucitel nema prirazeneho studenta." << std::endl;
}

Kniha::Kniha(std::string n)
    : nazev(std::move(n))
{
}

void Knihovna::pridejKnihu(std::shared_ptr<Kniha> k)
{
    knihy.push_back(k);
}

void Knihovna::vypisKnihy() const
{
    std::cout << "Knihy v knihovne:" << std::endl;
    for (const auto& kniha : knihy) {
        std::cout << "- " << kniha->nazev << std::endl;
    }
}

void MotorV::bezi()
{
    std::cout << "Motor (soucast vozu) bezi" << std::endl;
}

void Vuz::start()
{
    std::cout << "Vuz startuje..." << std::endl;
    motor.bezi();
}

void ukazkaVztahy()
{
    std::cout << "\n=== VZTAHY MEZI OBJEKTY ===" << std::endl;

    std::cout << "\n--- Kompozice (Vuz 'vlastni' MotorV) ---" << std::endl;
    Vuz auto1;
    auto1.start();

    std::cout << "\n--- Agregace (Knihovna 'sdili' Knihy) ---" << std::endl;
    auto k1 = std::make_shared<Kniha>("C++ pro zacatecniky");
    auto k2 = std::make_shared<Kniha>("Efektivni C++");

    Knihovna knihovna;
    knihovna.pridejKnihu(k1);
    knihovna.pridejKnihu(k2);

    knihovna.vypisKnihy();

    std::cout << "Kniha k1 stale existuje: " << k1->nazev << std::endl;

    std::cout << "\n--- Asociace (Ucitel 'zna' Studenta) ---" << std::endl;
    Student s("Jan Novak");
    Ucitel u;

    u.priradStudenta(&s);
    u.vypisStudenta();
}