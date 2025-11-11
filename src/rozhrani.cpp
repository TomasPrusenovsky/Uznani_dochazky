#include "rozhrani.h"
#include <iostream>

Dokument::Dokument(std::string o)
    : obsah(o)
{
}

void Dokument::tiskni()
{
    std::cout << "Tisknu: " << obsah << std::endl;
}

void Dokument::uloz()
{
    std::cout << "Ukladam dokument" << std::endl;
}

Obrazek::Obrazek(int s, int v)
    : sirka(s)
    , vyska(v)
{
}

void Obrazek::tiskni()
{
    std::cout << "Tisknu obrazek " << sirka << "x" << vyska << std::endl;
}

void ukazkaRozhrani()
{
    std::cout << "\n=== ROZHRANI ===" << std::endl;
    Dokument d("Muj text");
    d.tiskni();
    d.uloz();

    Obrazek o(800, 600);
    o.tiskni();
}