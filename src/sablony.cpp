#include "sablony.h"
#include <iostream>
#include <string>

void ukazkaSablony()
{
    std::cout << "\n=== SABLONY A GENERICKE PROGRAMOVANI ===" << std::endl;

    std::cout << "\n--- Sablonove funkce ---" << std::endl;

    std::cout << "maximum(5, 10): " << maximum(5, 10) << std::endl;
    std::cout << "maximum(3.14, 2.71): " << maximum(3.14, 2.71) << std::endl;
    std::cout << "maximum('a', 'z'): " << maximum('a', 'z') << std::endl;

    std::cout << "\nFunkce s vice typovymi parametry:" << std::endl;
    std::cout << "secti(5, 3.14): " << secti(5, 3.14) << std::endl;
    std::cout << "secti(10, 20): " << secti(10, 20) << std::endl;

    std::cout << "\n--- Sablonova trida (Zasobnik) ---" << std::endl;

    {
        Zasobnik<int> cisla(5);
        cisla.push(10);
        cisla.push(20);
        cisla.push(30);

        std::cout << "Zasobnik cisel (pocet: " << cisla.pocet() << "): ";
        while (!cisla.jePrazdny()) {
            std::cout << cisla.pop() << " ";
        }
        std::cout << std::endl;
    }

    {
        Zasobnik<std::string> texty(3);
        texty.push("ahoj");
        texty.push("svete");
        texty.push("!");

        std::cout << "Zasobnik retezcu: ";
        while (!texty.jePrazdny()) {
            std::cout << texty.pop() << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n--- Sablona s vice typy (Par<K,V>) ---" << std::endl;

    Par<std::string, int> vek("Jan", 25);
    Par<int, double> mereni(1, 3.14159);
    Par<std::string, std::string> preklad("hello", "ahoj");

    vek.vypis();
    mereni.vypis();
    preklad.vypis();

    std::cout << "\n--- Sablona s netypovym parametrem ---" << std::endl;

    StatickePole<int, 5> pole5;
    for (int i = 0; i < pole5.velikost(); i++) {
        pole5[i] = (i + 1) * 10;
    }
    pole5.vypis();

    StatickePole<double, 3> pole3;
    pole3[0] = 1.1;
    pole3[1] = 2.2;
    pole3[2] = 3.3;
    pole3.vypis();

    std::cout << "\n--- Explicitni specializace sablony ---" << std::endl;

    Tiskarna<int> tiskInt;
    Tiskarna<double> tiskDouble;
    Tiskarna<std::string> tiskString;
    Tiskarna<bool> tiskBool;

    tiskInt.tiskni(42);
    tiskDouble.tiskni(3.14159);
    tiskString.tiskni("Ahoj svete");
    tiskBool.tiskni(true);
    tiskBool.tiskni(false);

    std::cout << "\n--- Sablona s defaultnim parametrem ---" << std::endl;

    Kontejner<> defaultKontejner;
    defaultKontejner.pridej(1);
    defaultKontejner.pridej(2);
    defaultKontejner.pridej(3);
    defaultKontejner.vypisPrvky();

    Kontejner<std::string> stringKontejner;
    stringKontejner.pridej("jedna");
    stringKontejner.pridej("dva");
    stringKontejner.vypisPrvky();
}