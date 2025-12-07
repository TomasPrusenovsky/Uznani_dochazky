#pragma once
#include <string>

class ITisknutelne {
public:
    virtual void tiskni() const = 0;
    virtual ~ITisknutelne() = default;
};

class IUlozitelne {
public:
    virtual void uloz() const = 0;
    virtual ~IUlozitelne() = default;
};

class Dokument : public ITisknutelne, public IUlozitelne {
    std::string obsah;

public:
    Dokument(std::string o);
    void tiskni() const override;
    void uloz() const override;
};

class Obrazek : public ITisknutelne {
    int sirka, vyska;

public:
    Obrazek(int s, int v);
    void tiskni() const override;
};

void ukazkaRozhrani();