#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T, typename U>
auto secti(T a, U b) -> decltype(a + b)
{
    return a + b;
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
        std::cout << "Zasobnik<T>: vytvoreni s kapacitou " << velikost << std::endl;
    }

    ~Zasobnik()
    {
        delete[] pole;
        std::cout << "Zasobnik<T>: destruktor" << std::endl;
    }

    Zasobnik(const Zasobnik&) = delete;
    Zasobnik& operator=(const Zasobnik&) = delete;

    void push(const T& hodnota)
    {
        if (vrchol < velikost - 1) {
            pole[++vrchol] = hodnota;
        } else {
            std::cout << "Zasobnik je plny!" << std::endl;
        }
    }

    T pop()
    {
        if (vrchol >= 0) {
            return pole[vrchol--];
        }
        std::cout << "Zasobnik je prazdny!" << std::endl;
        return T();
    }

    const T& top() const
    {
        return pole[vrchol];
    }

    bool jePrazdny() const
    {
        return vrchol == -1;
    }

    int pocet() const
    {
        return vrchol + 1;
    }
};

template <typename K, typename V>
class Par {
    K klic;
    V hodnota;

public:
    Par(const K& k, const V& v)
        : klic(k)
        , hodnota(v)
    {
    }

    K getKlic() const { return klic; }
    V getHodnota() const { return hodnota; }

    void vypis() const
    {
        std::cout << "[" << klic << ": " << hodnota << "]" << std::endl;
    }
};

template <typename T, int N>
class StatickePole {
    T data[N];

public:
    StatickePole()
    {
        std::cout << "StatickePole<T, " << N << ">: vytvoreni" << std::endl;
        for (int i = 0; i < N; i++) {
            data[i] = T();
        }
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    constexpr int velikost() const
    {
        return N;
    }

    void vypis() const
    {
        std::cout << "Pole[" << N << "]: ";
        for (int i = 0; i < N; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Tiskarna {
public:
    void tiskni(const T& hodnota) const
    {
        std::cout << "Obecny typ: " << hodnota << std::endl;
    }
};

template <>
class Tiskarna<std::string> {
public:
    void tiskni(const std::string& hodnota) const
    {
        std::cout << "Retezec (delka " << hodnota.length() << "): \"" << hodnota << "\"" << std::endl;
    }
};

template <>
class Tiskarna<bool> {
public:
    void tiskni(const bool& hodnota) const
    {
        std::cout << "Boolean: " << (hodnota ? "PRAVDA" : "NEPRAVDA") << std::endl;
    }
};

template <typename T = int, typename Alokator = std::allocator<T>>
class Kontejner {
    std::vector<T, Alokator> data;

public:
    void pridej(const T& hodnota)
    {
        data.push_back(hodnota);
    }

    void vypisPrvky() const
    {
        std::cout << "Kontejner obsahuje: ";
        for (const auto& prvek : data) {
            std::cout << prvek << " ";
        }
        std::cout << std::endl;
    }

    size_t pocet() const
    {
        return data.size();
    }
};

void ukazkaSablony();