#include "konstruktory.h"
#include <iostream>
#include <utility>

Clovek::Clovek()
    : jmeno("Neznamy")
    , vek(0)
{
    std::cout << "Prazdny konstruktor" << std::endl;
}

Clovek::Clovek(const std::string& j)
    : jmeno(j)
    , vek(0)
{
    std::cout << "Konstruktor se jmenem: " << j << std::endl;
}

Clovek::Clovek(const std::string& j, int v)
    : jmeno(j)
    , vek(v)
{
    std::cout << "Konstruktor: " << j << ", " << v << " let" << std::endl;
}

Clovek::Clovek(const Clovek& other)
    : jmeno(other.jmeno)
    , vek(other.vek)
{
    std::cout << "Kopirovaci konstruktor" << std::endl;
}

Clovek::Clovek(Clovek&& other) noexcept
    : jmeno(std::move(other.jmeno))
    , vek(other.vek)
{
    std::cout << "Move konstruktor" << std::endl;
}

Clovek& Clovek::operator=(const Clovek& other)
{
    if (this != &other) {
        jmeno = other.jmeno;
        vek = other.vek;
        std::cout << "Operator prirazeni" << std::endl;
    }
    return *this;
}

Clovek& Clovek::operator=(Clovek&& other) noexcept
{
    if (this != &other) {
        jmeno = std::move(other.jmeno);
        vek = other.vek;
        std::cout << "Move operator prirazeni" << std::endl;
    }
    return *this;
}

Clovek::~Clovek()
{
    std::cout << "Destruktor: " << jmeno << std::endl;
}

void Clovek::predstavSe() const
{
    std::cout << "Ahoj, jsem " << jmeno << std::endl;
}

void Clovek::predstavSe(bool podrobne) const
{
    if (podrobne) {
        std::cout << "Ahoj, jsem " << jmeno << " a je mi " << vek << " let" << std::endl;
    } else {
        std::cout << "Ahoj, jsem " << jmeno << std::endl;
    }
}

void Clovek::oslavNarozeniny()
{
    vek++;
    std::cout << jmeno << " oslavil narozeniny!" << std::endl;
}

void Clovek::oslavNarozeniny(int pocet)
{
    vek += pocet;
    std::cout << jmeno << " oslavil " << pocet << " narozenin!" << std::endl;
}

void ukazkaKonstruktory()
{
    std::cout << "\n=== KONSTRUKTORY A PRETEZOVANI ===" << std::endl;
    Clovek c1;
    Clovek c2("Jan");
    Clovek c3("Petr", 25);

    c3.predstavSe();
    c3.predstavSe(true);
    c3.oslavNarozeniny();
    c3.oslavNarozeniny(5);

    std::cout << "\nKopirovani:" << std::endl;
    Clovek c4 = c3;

    std::cout << "\nMove konstruktor:" << std::endl;
    Clovek c5 = std::move(c2);

    std::cout << "\nOperator prirazeni:" << std::endl;
    Clovek c6;
    c6 = c3;

    std::cout << "\nMove operator prirazeni:" << std::endl;
    c6 = std::move(c4);
    std::cout << std::endl;
}