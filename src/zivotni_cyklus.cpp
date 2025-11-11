#include "zivotni_cyklus.h"
#include <iostream>

int Objekt::pocitadlo = 0;

Objekt::Objekt(int i)
    : id(i)
{
    std::cout << "Vytvoril se objekt " << id << std::endl;
}

Objekt::Objekt(Objekt&& other) noexcept
    : id(other.id)
{
    std::cout << "Objekt " << id << " se prestehoval (move konstruktor)" << std::endl;
    other.id = -1;
}

Objekt::~Objekt()
{
    if (id != -1) {
        std::cout << "Zrusil se objekt " << id << std::endl;
    }
}

void Objekt::vypis() const
{
    std::cout << "Objekt ID: " << id << std::endl;
}

void Objekt::inkrementuj()
{
    pocitadlo++;
}

void pomocnaFunkce()
{
    Objekt lokalni(2);
}

void ukazkaUniquePtr()
{
    std::cout << "\n--- Unique pointer ---" << std::endl;
    std::unique_ptr<Objekt> ptr1 = std::make_unique<Objekt>(10);
    ptr1->vypis();

    std::cout << "Presun vlastnictvi:" << std::endl;
    std::unique_ptr<Objekt> ptr2 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 je nyni nullptr" << std::endl;
    }
    ptr2->vypis();

    std::cout << "Presun objektu (ne ukazatele):" << std::endl;
    Objekt obj1(11);
    Objekt obj2 = std::move(obj1);
}

void ukazkaSharedPtr()
{
    std::cout << "\n--- Shared pointer ---" << std::endl;
    std::shared_ptr<Objekt> sptr1 = std::make_shared<Objekt>(20);
    std::cout << "Pocet referenci: " << sptr1.use_count() << std::endl;

    {
        std::shared_ptr<Objekt> sptr2 = sptr1;
        std::cout << "Pocet referenci: " << sptr1.use_count() << std::endl;
        sptr2->vypis();
    }

    std::cout << "Pocet referenci po scope: " << sptr1.use_count() << std::endl;
}

void ukazkaZivotniCyklus()
{
    std::cout << "\n=== ZIVOTNI CYKLUS OBJEKTU ===" << std::endl;

    std::cout << "\n--- Na zasobniku ---" << std::endl;
    Objekt naZasobniku(1);

    std::cout << "\n--- Lokalni v funkci ---" << std::endl;
    pomocnaFunkce();

    std::cout << "\n--- Na halde (raw pointer) ---" << std::endl;
    Objekt* naHalde = new Objekt(3);
    delete naHalde;

    ukazkaUniquePtr();
    ukazkaSharedPtr();

    std::cout << "\n--- Staticke cleny ---" << std::endl;
    Objekt::inkrementuj();
    std::cout << "Pocitadlo: " << Objekt::pocitadlo << std::endl;

    std::cout << "\n--- Konec funkce ---" << std::endl;
}