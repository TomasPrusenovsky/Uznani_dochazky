#pragma once

class Tvar {
public:
    virtual double obsah() const = 0;
    virtual void popis() const = 0;
    virtual ~Tvar() = default;
};

class Kruh : public Tvar {
    double polomer;

public:
    Kruh(double r);
    double obsah() const override;
    void popis() const override;
};

class Ctverec : public Tvar {
    double strana;

public:
    Ctverec(double s);
    double obsah() const override;
    void popis() const override;
};

void ukazkaPolymorfismus();