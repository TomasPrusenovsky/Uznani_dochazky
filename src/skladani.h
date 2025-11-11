#pragma once
#include <memory>
#include <string>

class Motor {
    int vykony;
    std::string typ;

public:
    Motor(int v, const std::string& t);
    void nastartuj() const;
    int getVykony() const;
};

class Karoserie {
    std::string barva;
    std::string material;

public:
    Karoserie(const std::string& b, const std::string& m);
    std::string getBarva() const;
    void vypisInfo() const;
};

class Kola {
    int prumer;
    std::string typ;

public:
    Kola(int p, const std::string& t);
    void vypisInfo() const;
};

class Automobil {
    std::unique_ptr<Motor> motor;
    std::unique_ptr<Karoserie> karoserie;
    std::unique_ptr<Kola> kola;
    std::string spz;

public:
    Automobil(const std::string& s);

    void nastavMotor(std::unique_ptr<Motor> m);
    void nastavKaroserii(std::unique_ptr<Karoserie> k);
    void nastavKola(std::unique_ptr<Kola> k);

    void jed();
    void vypisKonfiguraci() const;
};

void ukazkaSkladani();