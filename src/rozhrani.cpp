#include "rozhrani.h"
#include <iostream>
#include <vector>
#include <utility>

Dokument::Dokument(std::string o)
    : obsah(std::move(o))
{
}

void Dokument::tiskni() const
{
    std::cout << "Tisknu dokument: " << obsah << std::endl;
}

void Dokument::uloz() const
{
    std::cout << "Ukladam dokument do archivu." << std::endl;
}

Obrazek::Obrazek(int s, int v)
    : sirka(s)
    , vyska(v)
{
}

void Obrazek::tiskni() const
{
    std::cout << "Tisknu obrazek (" << sirka << "x" << vyska << " px)" << std::endl;
}

void zpracujTisk(const ITisknutelne& polozka)
{
    polozka.tiskni();
}

void ukazkaRozhrani()
{
    std::cout << "\n=== DEDICNOST ROZHRANI (INTERFACE) ===" << std::endl;

    Dokument doc("Vyrocni zprava");
    Obrazek img(1920, 1080);

    std::cout << "\n--- Pouziti rozhrani ve funkci ---" << std::endl;
    zpracujTisk(doc);
    zpracujTisk(img);

    std::cout << "\n--- Heterogenni kolekce pres rozhrani ---" << std::endl;
    std::vector<ITisknutelne*> fronta;
    fronta.push_back(&doc);
    fronta.push_back(&img);

    for (const auto* polozka : fronta) {
        polozka->tiskni();
    }

    std::cout << "\n--- Vicenasobna dedicnost rozhrani ---" << std::endl;
    ITisknutelne* ptr = &doc;
    ptr->tiskni();

    if (auto* ulozitelne = dynamic_cast<IUlozitelne*>(ptr)) {
        std::cout << "Objekt podporuje i ukladani:" << std::endl;
        ulozitelne->uloz();
    }
}