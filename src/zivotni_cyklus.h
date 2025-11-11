#pragma once
#include <memory>

class Objekt {
    int id;

public:
    Objekt(int i);
    Objekt(Objekt&& other) noexcept;
    ~Objekt();

    void vypis() const;

    static int pocitadlo;
    static void inkrementuj();
};

void pomocnaFunkce();
void ukazkaUniquePtr();
void ukazkaSharedPtr();
void ukazkaZivotniCyklus();