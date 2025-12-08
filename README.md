# Uznani dochazky

Kolekce ukázkových příkladů objektově orientovaného programování.

## Obsah

| Soubor           | Téma                                         |
|------------------|----------------------------------------------|
| `paradigmy`      | Imperativní, deklarativní a OOP přístup      |
| `oop_zaklady`    | Třída, atributy, metody, zapouzdření         |
| `konstruktory`   | Konstruktory, destruktory, přetěžování metod |
| `skladani`       | Skládání objektů (kompozice)                 |
| `dedicnost`      | Dědičnost vs kompozice                       |
| `zivotni_cyklus` | Zásobník, halda, smart pointery              |
| `vztahy`         | Asociace, agregace, kompozice                |
| `kopirovani`     | Mělká/hluboká kopie, move sémantika          |
| `polymorfismus`  | Virtuální metody, abstraktní třídy           |
| `rozhrani`       | Interface, vícenásobná dědičnost rozhraní    |
| `sablony`        | Šablony funkcí a tříd, specializace          |

## Sestavení

```bash
mkdir build && cd build
cmake ..
make
./ukazky
```

## Požadavky

- CMake 3.10+
- Kompilátor s podporou C++17