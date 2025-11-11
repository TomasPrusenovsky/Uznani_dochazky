#include "polymorfismus.h"
#include <iostream>

double Tvar::obsah()
{
    return 0;
}

Kruh::Kruh(double r)
    : polomer(r)
{
}

double Kruh::obsah()
{
    return 3.14 * polomer * polomer;
}

void Kruh::popis()
{
    std::cout << "Jsem kruh" << std::endl;
}

Ctverec::Ctverec(double s)
    : strana(s)
{
}

double Ctverec::obsah()
{
    return strana * strana;
}

void Ctverec::popis()
{
    std::cout << "Jsem ctverec" << std::endl;
}

void vypisTvar(Tvar* t)
{
    t->popis();
    std::cout << "Obsah: " << t->obsah() << std::endl;
}

void ukazkaPolymorfismus()
{
    std::cout << "\n=== POLYMORFISMUS ===" << std::endl;
    Kruh k(5);
    Ctverec c(4);

    vypisTvar(&k);
    vypisTvar(&c);
}