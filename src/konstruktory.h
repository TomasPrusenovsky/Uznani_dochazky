#pragma once
#include <string>

class Clovek {
    std::string jmeno;
    int vek;

public:
    Clovek();
    Clovek(const std::string& j);
    Clovek(const std::string& j, int v);
    Clovek(const Clovek& other);
    Clovek(Clovek&& other) noexcept;
    Clovek& operator=(const Clovek& other);
    Clovek& operator=(Clovek&& other) noexcept;
    ~Clovek();

    void predstavSe() const;
    void predstavSe(bool podrobne) const;
    void oslavNarozeniny();
    void oslavNarozeniny(int pocet);
};

void ukazkaKonstruktory();
