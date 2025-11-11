#pragma once
#include <string>
#include <vector>

class Student {
public:
    std::string jmeno;
    Student(std::string j);
};

class Kniha {
public:
    std::string nazev;
    Kniha(std::string n);
};

class Knihovna {
    std::vector<Kniha*> knihy;

public:
    void pridejKnihu(Kniha* k);
};

class MotorV {
public:
    void bezi();
};

class Vuz {
    MotorV motor;

public:
    void start();
};

class Ucitel {
    Student* student;

public:
    void priradStudenta(Student* s);
    void vypisStudenta();
};

void ukazkaVztahy();