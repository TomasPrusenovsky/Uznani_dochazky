#include "skladani.h"
#include <iostream>

Motor::Motor(int v, const std::string& t)
    : vykony(v)
    , typ(t)
{
    std::cout << "Vytvoren motor: " << typ << ", " << vykony << " kW" << std::endl;
}

void Motor::nastartuj() const
{
    std::cout << "Motor " << typ << " (" << vykony << " kW) startuje" << std::endl;
}

int Motor::getVykony() const
{
    return vykony;
}

Karoserie::Karoserie(const std::string& b, const std::string& m)
    : barva(b)
    , material(m)
{
    std::cout << "Vytvorena karoserie: " << barva << ", " << material << std::endl;
}

std::string Karoserie::getBarva() const
{
    return barva;
}

void Karoserie::vypisInfo() const
{
    std::cout << "Karoserie: " << barva << " (" << material << ")" << std::endl;
}

Kola::Kola(int p, const std::string& t)
    : prumer(p)
    , typ(t)
{
    std::cout << "Vytvorena kola: " << typ << ", " << prumer << '"' << std::endl;
}

void Kola::vypisInfo() const
{
    std::cout << "Kola: " << typ << ", " << prumer << '"' << std::endl;
}

Automobil::Automobil(const std::string& s)
    : spz(s)
{
    std::cout << "Vytvoren automobil: " << spz << std::endl;
}

void Automobil::nastavMotor(std::unique_ptr<Motor> m)
{
    motor = std::move(m);
    std::cout << "Nainstalovan novy motor" << std::endl;
}

void Automobil::nastavKaroserii(std::unique_ptr<Karoserie> k)
{
    karoserie = std::move(k);
    std::cout << "Nainstalovana nova karoserie" << std::endl;
}

void Automobil::nastavKola(std::unique_ptr<Kola> k)
{
    kola = std::move(k);
    std::cout << "Nainstalovana nova kola" << std::endl;
}

void Automobil::jed()
{
    if (motor && karoserie && kola) {
        motor->nastartuj();
        std::cout << karoserie->getBarva() << " auto " << spz << " jede" << std::endl;
    } else {
        std::cout << "Auto neni kompletni!" << std::endl;
    }
}

void Automobil::vypisKonfiguraci() const
{
    std::cout << "\n--- Konfigurace vozidla " << spz << " ---" << std::endl;
    if (motor)
        std::cout << "Motor: " << motor->getVykony() << " kW" << std::endl;
    if (karoserie)
        karoserie->vypisInfo();
    if (kola)
        kola->vypisInfo();
    std::cout << std::endl;
}

void ukazkaSkladani()
{
    std::cout << "\n=== SKLADANI OBJEKTU ===" << std::endl;

    Automobil auto1("1A2 3456"); // Nelze pouzit auto jako nazev (keyword) XD

    auto1.nastavMotor(std::make_unique<Motor>(75, "benzinovy"));
    auto1.nastavKaroserii(std::make_unique<Karoserie>("cervena", "ocel"));
    auto1.nastavKola(std::make_unique<Kola>(16, "ocelova"));

    auto1.vypisKonfiguraci();
    auto1.jed();

    std::cout << "\n--- Vymena motoru a kol ---" << std::endl;
    auto1.nastavMotor(std::make_unique<Motor>(150, "turbodiesel"));
    auto1.nastavKola(std::make_unique<Kola>(18, "litinova"));

    auto1.vypisKonfiguraci();
    auto1.jed();
}