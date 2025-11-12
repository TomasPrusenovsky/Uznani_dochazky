#include "kopirovani.h"
#include <iostream>
#include <utility> // Pro std::move

MelkaKopie::MelkaKopie(int hodnota)
{
    data = new int(hodnota);
    std::cout << "MelkaKopie: konstruktor, data=" << *data << std::endl;
}

MelkaKopie::~MelkaKopie()
{
    std::cout << "MelkaKopie: destruktor, data=" << *data << std::endl;
    delete data;
}

void MelkaKopie::zmen(int hodnota)
{
    *data = hodnota;
}

void MelkaKopie::vypis() const
{
    std::cout << "Hodnota: " << *data << ", Adresa: " << data << std::endl;
}

int* MelkaKopie::getDataPtr() const
{
    return data;
}

HlubokaKopie::HlubokaKopie(int hodnota, std::string p)
    : popis(std::move(p))
{
    data = new int(hodnota);
    std::cout << "HlubokaKopie: konstruktor (" << popis << "), data=" << *data << std::endl;
}

HlubokaKopie::HlubokaKopie(const HlubokaKopie& other)
    : popis(other.popis + "_kopie")
{
    data = new int(*other.data);
    std::cout << "HlubokaKopie: kopirovaci konstruktor (" << popis << ")" << std::endl;
}

HlubokaKopie::HlubokaKopie(HlubokaKopie&& other) noexcept
    : data(other.data)
    , popis(std::move(other.popis))
{
    other.data = nullptr;
    std::cout << "HlubokaKopie: move konstruktor" << std::endl;
}

HlubokaKopie& HlubokaKopie::operator=(const HlubokaKopie& other)
{
    if (this != &other) {
        // POZNAMKA: Tato implementace neni "exception-safe".
        // Pokud by 'new int' selhalo (napr. nedostatek pameti),
        // puvodni 'data' uz byla smazana a objekt zustane v neplatnem stavu.
        // Robustnejsi reseni pouziva "copy-and-swap" idiom.
        delete data;
        data = new int(*other.data);
        popis = other.popis + "_prirazeno";
        std::cout << "HlubokaKopie: operator prirazeni" << std::endl;
    }
    return *this;
}

HlubokaKopie& HlubokaKopie::operator=(HlubokaKopie&& other) noexcept
{
    if (this != &other) {
        delete data;
        data = other.data;
        popis = std::move(other.popis);
        other.data = nullptr;
        std::cout << "HlubokaKopie: move operator prirazeni" << std::endl;
    }
    return *this;
}

HlubokaKopie::~HlubokaKopie()
{
    if (data) {
        std::cout << "HlubokaKopie: destruktor (" << popis << "), data=" << *data << std::endl;
        delete data;
    } else {
        std::cout << "HlubokaKopie: destruktor (presunuto)" << std::endl;
    }
}

void HlubokaKopie::zmen(int hodnota)
{
    if (data) {
        *data = hodnota;
    }
}

void HlubokaKopie::vypis() const
{
    if (data) {
        std::cout << popis << " - Hodnota: " << *data << ", Adresa: " << data << std::endl;
    } else {
        std::cout << popis << " - Objekt presunut" << std::endl;
    }
}

int* HlubokaKopie::getDataPtr() const
{
    return data;
}

SmartKopie::SmartKopie(int hodnota, std::string p)
    : data(std::make_unique<int>(hodnota))
    , popis(std::move(p))
{
    std::cout << "SmartKopie: konstruktor (" << popis << ")" << std::endl;
}

SmartKopie::SmartKopie(const SmartKopie& other)
    : data(std::make_unique<int>(*other.data))
    , popis(other.popis + "_kopie")
{
    std::cout << "SmartKopie: kopirovaci konstruktor" << std::endl;
}

SmartKopie& SmartKopie::operator=(const SmartKopie& other)
{
    if (this != &other) {
        data = std::make_unique<int>(*other.data);
        popis = other.popis + "_prirazeno";
        std::cout << "SmartKopie: operator prirazeni" << std::endl;
    }
    return *this;
}

void SmartKopie::zmen(int hodnota)
{
    *data = hodnota;
}

void SmartKopie::vypis() const
{
    std::cout << popis << " - Hodnota: " << *data << ", Adresa: " << data.get() << std::endl;
}

void ukazkaKopirovani()
{
    std::cout << "\n=== KOPIROVANI OBJEKTU ===" << std::endl;

    std::cout << "\n--- Melka kopie (PROBLEM!) ---" << std::endl;
    {
        MelkaKopie m1(100);
        m1.vypis();
        // Poznamka: Kod zde zamerne neukazuje kopii,
        // protoze by to vedlo k padu programu (double free).
        // HlubokaKopie ukazuje reseni tohoto problemu.
    }

    std::cout << "\n--- Hluboka kopie ---" << std::endl;
    HlubokaKopie h1(10, "original");
    h1.vypis();

    std::cout << "\nKopirovaci konstruktor:" << std::endl;
    HlubokaKopie h2 = h1;
    h2.vypis();

    std::cout << "\nZmena original:" << std::endl;
    h1.zmen(20);
    h1.vypis();
    h2.vypis();

    std::cout << "\nOperator prirazeni:" << std::endl;
    HlubokaKopie h3(30, "treti");
    h3 = h1;
    h3.vypis();

    std::cout << "\nMove semantika:" << std::endl;
    HlubokaKopie h4 = std::move(h1);
    h4.vypis();
    h1.vypis();

    std::cout << "\n--- Smart pointery ---" << std::endl;
    SmartKopie s1(50, "smart1");
    s1.vypis();

    SmartKopie s2 = s1;
    s2.vypis();

    s1.zmen(60);
    std::cout << "Po zmene s1:" << std::endl;
    s1.vypis();
    s2.vypis();

    std::cout << "\nMove s smart pointery:" << std::endl;
    SmartKopie s3 = std::move(s1);
    s3.vypis();
}