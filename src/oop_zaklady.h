#pragma once
#include <string>

class Auto {
private:
    std::string znacka;
    int rychlost;
    bool zapnuto;

public:
    Auto(const std::string& z);
    void zapni();
    void zrychli(int delta);
    void vypis() const;
};

void ukazkaOOPZaklady();