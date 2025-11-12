#pragma once
#include <memory>
#include <string>

class MelkaKopie {
    int* data;

public:
    MelkaKopie(int hodnota);
    ~MelkaKopie();

    void zmen(int hodnota);
    void vypis() const;
    int* getDataPtr() const;
};

class HlubokaKopie {
    int* data;
    std::string popis;

public:
    HlubokaKopie(int hodnota, std::string p);
    HlubokaKopie(const HlubokaKopie& other);
    HlubokaKopie(HlubokaKopie&& other) noexcept;
    HlubokaKopie& operator=(const HlubokaKopie& other);
    HlubokaKopie& operator=(HlubokaKopie&& other) noexcept;
    ~HlubokaKopie();

    void zmen(int hodnota);
    void vypis() const;
    int* getDataPtr() const;
};

class SmartKopie {
    std::unique_ptr<int> data;
    std::string popis;

public:
    SmartKopie(int hodnota, std::string p);
    SmartKopie(const SmartKopie& other);
    SmartKopie(SmartKopie&& other) noexcept = default;
    SmartKopie& operator=(const SmartKopie& other);
    SmartKopie& operator=(SmartKopie&& other) noexcept = default;

    void zmen(int hodnota);
    void vypis() const;
};

void ukazkaKopirovani();