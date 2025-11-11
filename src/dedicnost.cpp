#include "dedicnost.h"
#include <iostream>

Zvire::Zvire(const std::string& j, int v)
    : jmeno(j)
    , vek(v)
{
    std::cout << "Vytvoreno zvire: " << jmeno << std::endl;
}

std::string Zvire::getJmeno() const
{
    return jmeno;
}

int Zvire::getVek() const
{
    return vek;
}

Pes::Pes(const std::string& j, int v, const std::string& r)
    : Zvire(j, v)
    , rasa(r)
{
    std::cout << "Vytvoren pes rasy: " << rasa << std::endl;
}

void Pes::zvuk() const
{
    std::cout << jmeno << " steka: Haf haf!" << std::endl;
}

void Pes::pohyb() const
{
    std::cout << jmeno << " bezi po ctyrech" << std::endl;
}

void Pes::aport() const
{
    std::cout << jmeno << " aportuje micek" << std::endl;
}

Kocka::Kocka(const std::string& j, int v, bool d)
    : Zvire(j, v)
    , domaci(d)
{
    std::cout << "Vytvorena kocka: " << (domaci ? "domaci" : "divoка") << std::endl;
}

void Kocka::zvuk() const
{
    std::cout << jmeno << " mnavka: Mnau!" << std::endl;
}

void Kocka::pohyb() const
{
    std::cout << jmeno << " krade se tiše" << std::endl;
}

void Kocka::prasKohoutky() const
{
    std::cout << jmeno << " si prasi kohoutky" << std::endl;
}

LetoveSchopnosti::LetoveSchopnosti(int v)
    : maxVyska(v)
{
}

void LetoveSchopnosti::vzlet() const
{
    std::cout << "Vzlet do vysky " << maxVyska << "m" << std::endl;
}

void LetoveSchopnosti::pristani() const
{
    std::cout << "Pristani" << std::endl;
}

int LetoveSchopnosti::getMaxVyska() const
{
    return maxVyska;
}

Plavani::Plavani(int r)
    : rychlost(r)
{
}

void Plavani::zaplavSi() const
{
    std::cout << "Plavu rychlosti " << rychlost << " km/h" << std::endl;
}

int Plavani::getRychlost() const
{
    return rychlost;
}

Kachna::Kachna(const std::string& j)
    : jmeno(j)
{
    letani = std::make_unique<LetoveSchopnosti>(500);
    plavani = std::make_unique<Plavani>(5);
    std::cout << "Vytvorena kachna: " << jmeno << std::endl;
}

void Kachna::let() const
{
    std::cout << jmeno << " ";
    letani->vzlet();
}

void Kachna::plav() const
{
    std::cout << jmeno << " ";
    plavani->zaplavSi();
}

void Kachna::zakejhej() const
{
    std::cout << jmeno << " dela: Kvak kvak!" << std::endl;
}

Netopyr::Netopyr(const std::string& j, int v, int maxVyska)
    : Zvire(j, v)
    , LetoveSchopnosti(maxVyska)
{
    std::cout << "Vytvoren netopyr" << std::endl;
}

void Netopyr::zvuk() const
{
    std::cout << jmeno << " piska ultrazvukem" << std::endl;
}

void Netopyr::pohyb() const
{
    std::cout << jmeno << " lita v noci" << std::endl;
}

void Netopyr::echolokace() const
{
    std::cout << jmeno << " pouziva echolokaci" << std::endl;
}

void ukazkaDedicnost()
{
    std::cout << "\n=== DEDICNOST VS KOMPOZICE ===" << std::endl;

    std::cout << "\n--- Dedicnost ---" << std::endl;
    Pes rex("Rex", 3, "Nemecky ovcak");
    rex.zvuk();
    rex.pohyb();
    rex.aport();

    Kocka micka("Micka", 2, true);
    micka.zvuk();
    micka.pohyb();
    micka.prasKohoutky();

    std::cout << "\n--- Kompozice ---" << std::endl;
    Kachna donald("Donald");
    donald.zakejhej();
    donald.plav();
    donald.let();

    std::cout << "\n--- Polymorfismus ---" << std::endl;
    std::vector<std::unique_ptr<Zvire>> zvirata;
    zvirata.push_back(std::make_unique<Pes>("Alik", 4, "Labrador"));
    zvirata.push_back(std::make_unique<Kocka>("Mourek", 3, false));

    for (const auto& zvire : zvirata) {
        zvire->zvuk();
        zvire->pohyb();
    }

    std::cout << "\n--- Vícenásobná dědičnost ---" << std::endl;
    Netopyr dracula("Dracula", 5, 2000);
    dracula.zvuk();
    dracula.pohyb();
    dracula.vzlet();
    dracula.echolokace();
}