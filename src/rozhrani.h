#pragma once
#include <string>

class ITisknutelne {
public:
    virtual void tiskni() = 0;
    virtual ~ITisknutelne() { }
};

class IUlozitelne {
public:
    virtual void uloz() = 0;
    virtual ~IUlozitelne() { }
};

class Dokument : public ITisknutelne, public IUlozitelne {
    std::string obsah;

public:
    Dokument(std::string o);
    void tiskni() override;
    void uloz() override;
};

class Obrazek : public ITisknutelne {
    int sirka, vyska;

public:
    Obrazek(int s, int v);
    void tiskni() override;
};

void ukazkaRozhrani();