#pragma once
#include <string>
#include <vector>
#include <memory>

class Student {
public:
    std::string jmeno;

    Student(std::string j);
};

class Ucitel {
    Student *student;

public:
    Ucitel();

    void priradStudenta(Student *s);

    void vypisStudenta();
};

class Kniha {
public:
    std::string nazev;

    Kniha(std::string n);
};

class Knihovna {
    std::vector<std::shared_ptr<Kniha> > knihy;

public:
    void pridejKnihu(std::shared_ptr<Kniha> k);

    void vypisKnihy() const;
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

void ukazkaVztahy();