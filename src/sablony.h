#pragma once

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
class Zasobnik {
    T* pole;
    int velikost;
    int vrchol;

public:
    Zasobnik(int v)
        : velikost(v)
        , vrchol(-1)
    {
        pole = new T[velikost];
    }

    ~Zasobnik()
    {
        delete[] pole;
    }

    void push(T hodnota)
    {
        if (vrchol < velikost - 1) {
            pole[++vrchol] = hodnota;
        }
    }

    T pop()
    {
        if (vrchol >= 0) {
            return pole[vrchol--];
        }
        return T();
    }

    bool jePrazdny()
    {
        return vrchol == -1;
    }
};

void ukazkaSablony();