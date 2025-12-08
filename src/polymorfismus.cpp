#include "polymorfismus.h"
#include <iostream>
#include <memory>
#include <vector>

Kruh::Kruh(double r)
    : polomer(r)
{
}

double Kruh::obsah() const
{
    return 3.14 * polomer * polomer;
}

void Kruh::popis() const
{
    std::cout << "Jsem kruh" << std::endl;
}

Ctverec::Ctverec(double s)
    : strana(s)
{
}

double Ctverec::obsah() const
{
    return strana * strana;
}

void Ctverec::popis() const
{
    std::cout << "Jsem ctverec" << std::endl;
}

void vypisTvar(const Tvar* t)
{
    t->popis();
    std::cout << "Obsah: " << t->obsah() << std::endl;
}

void ukazkaPolymorfismus()
{
    std::cout << "\n=== POLYMORFISMUS ===" << std::endl;

    std::vector<std::unique_ptr<Tvar>> tvary;

    tvary.push_back(std::make_unique<Kruh>(5));
    tvary.push_back(std::make_unique<Ctverec>(4));
    tvary.push_back(std::make_unique<Kruh>(2.5));

    std::cout << "Prochazeni heterogenni kolekce:" << std::endl;

    for (const auto& tvarPtr : tvary) {
        vypisTvar(tvarPtr.get());
    }
}