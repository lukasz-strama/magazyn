#ifndef MAGAZYN_H
#define MAGAZYN_H

class Magazyn
{
private:
    int _pojemnosc;
    int _ilosc;

public:
    // Konstruktory i destruktor
    Magazyn(int pojemnosc, int ilosc);
    Magazyn();
    ~Magazyn();

    // Metody dostępowe
    int getPojemnosc() const;
    int getIlosc() const;
    void setPojemnosc(int pojemnosc);
    void setIlosc(int ilosc);

    // Metoda wyświetlająca stan magazynu
    void pokazStan() const;
};

#endif /* MAGAZYN_H */
