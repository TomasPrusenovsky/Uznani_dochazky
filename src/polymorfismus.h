#pragma once

class Tvar {
public:
    virtual double obsah();
    virtual void popis() = 0;
    virtual ~Tvar() { }
};

class Kruh : public Tvar {
    double polomer;

public:
    Kruh(double r);
    double obsah() override;
    void popis() override;
};

class Ctverec : public Tvar {
    double strana;

public:
    Ctverec(double s);
    double obsah() override;
    void popis() override;
};

void ukazkaPolymorfismus();