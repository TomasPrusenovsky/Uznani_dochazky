#include "sablony.h"
#include <iostream>
#include <string>

void ukazkaSablony()
{
    std::cout << "\n=== SABLONY ===" << std::endl;
    std::cout << "Max(5, 10): " << maximum(5, 10) << std::endl;
    std::cout << "Max(3.14, 2.71): " << maximum(3.14, 2.71) << std::endl;

    Zasobnik<int> cisla(5);
    cisla.push(1);
    cisla.push(2);
    cisla.push(3);

    std::cout << "Zasobnik cisel: ";
    while (!cisla.jePrazdny()) {
        std::cout << cisla.pop() << " ";
    }
    std::cout << std::endl;

    Zasobnik<std::string> texty(3);
    texty.push("ahoj");
    texty.push("svete");

    std::cout << "Zasobnik textu: ";
    while (!texty.jePrazdny()) {
        std::cout << texty.pop() << " ";
    }
    std::cout << std::endl;
}