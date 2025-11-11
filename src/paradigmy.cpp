#include "paradigmy.h"
#include <iostream>
#include <numeric>

int soucetImperativni(const std::vector<int>& cisla)
{
    int vysledek = 0;
    for (int cislo : cisla) {
        vysledek += cislo;
    }
    return vysledek;
}

int soucetDeklarativni(const std::vector<int>& cisla)
{
    return std::accumulate(cisla.begin(), cisla.end(), 0);
}

Kalkulacka::Kalkulacka()
    : aktualni(0)
{
}

void Kalkulacka::pricti(int hodnota)
{
    aktualni += hodnota;
}

int Kalkulacka::ziskej() const
{
    return aktualni;
}

void ukazkaParadigmat()
{
    std::cout << "\n=== PARADIGMATA ===" << std::endl;
    std::vector<int> data = { 1, 2, 3, 4, 5 };

    std::cout << "Imperativni: " << soucetImperativni(data) << std::endl;
    std::cout << "Deklarativni: " << soucetDeklarativni(data) << std::endl;

    Kalkulacka k;
    for (int n : data) {
        k.pricti(n);
    }
    std::cout << "OOP: " << k.ziskej() << std::endl;
}