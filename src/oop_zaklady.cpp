#include "oop_zaklady.h"
#include <iostream>

Auto::Auto(const std::string& z)
    : znacka(z)
    , rychlost(0)
    , zapnuto(false)
{
}

void Auto::zapni()
{
    zapnuto = true;
}

void Auto::zrychli(int delta)
{
    if (zapnuto) {
        rychlost += delta;
    }
}

void Auto::vypis() const
{
    std::cout << znacka << ": " << rychlost << " km/h" << std::endl;
}

void ukazkaOOPZaklady()
{
    std::cout << "\n=== OOP ZAKLADY ===" << std::endl;
    Auto skoda("Skoda");
    skoda.zapni();
    skoda.zrychli(50);
    skoda.vypis();
}