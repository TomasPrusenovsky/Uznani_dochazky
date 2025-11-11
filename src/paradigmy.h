#pragma once
#include <vector>

int soucetImperativni(const std::vector<int>& cisla);
int soucetDeklarativni(const std::vector<int>& cisla);

class Kalkulacka {
    int aktualni;

public:
    Kalkulacka();
    void pricti(int hodnota);
    int ziskej() const;
};

void ukazkaParadigmat();