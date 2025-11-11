#include "dedicnost.h"
#include "konstruktory.h"
#include "kopirovani.h"
#include "oop_zaklady.h"
#include "paradigmy.h"
#include "polymorfismus.h"
#include "rozhrani.h"
#include "sablony.h"
#include "skladani.h"
#include "vztahy.h"
#include "zivotni_cyklus.h"
#include <iostream>

int main()
{
    std::cout << "C++ OOP UKAZKY" << std::endl;
    std::cout << "==============" << std::endl;

    ukazkaParadigmat();
    ukazkaOOPZaklady();
    ukazkaKonstruktory();
    ukazkaSkladani();
    ukazkaDedicnost();
    ukazkaZivotniCyklus();
    ukazkaVztahy();
    ukazkaKopirovani();
    ukazkaPolymorfismus();
    ukazkaRozhrani();
    ukazkaSablony();

    std::cout << "\n==============" << std::endl;
    std::cout << "KONEC UKAZEK" << std::endl;

    return 0;
}