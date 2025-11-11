#include <memory>
#include <string>
#include <vector>

class Zvire {
protected:
    std::string jmeno;
    int vek;

public:
    Zvire(const std::string& j, int v);
    virtual ~Zvire() = default;

    virtual void zvuk() const = 0;
    virtual void pohyb() const = 0;

    std::string getJmeno() const;
    int getVek() const;
};

class Pes : public Zvire {
    std::string rasa;

public:
    Pes(const std::string& j, int v, const std::string& r);

    void zvuk() const override;
    void pohyb() const override;
    void aport() const;
};

class Kocka : public Zvire {
    bool domaci;

public:
    Kocka(const std::string& j, int v, bool d);

    void zvuk() const override;
    void pohyb() const override;
    void prasKohoutky() const;
};

class LetoveSchopnosti {
    int maxVyska;

public:
    LetoveSchopnosti(int v);
    void vzlet() const;
    void pristani() const;
    int getMaxVyska() const;
};

class Plavani {
    int rychlost;

public:
    Plavani(int r);
    void zaplavSi() const;
    int getRychlost() const;
};

class Kachna {
    std::string jmeno;
    std::unique_ptr<LetoveSchopnosti> letani;
    std::unique_ptr<Plavani> plavani;

public:
    Kachna(const std::string& j);

    void let() const;
    void plav() const;
    void zakejhej() const;
};

class Netopyr : public Zvire, public LetoveSchopnosti {
public:
    Netopyr(const std::string& j, int v, int maxVyska);

    void zvuk() const override;
    void pohyb() const override;
    void echolokace() const;
};

void ukazkaDedicnost();