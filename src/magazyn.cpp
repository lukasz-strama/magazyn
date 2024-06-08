#include <iostream>

class Magazyn
{
private:
    int _pojemnosc;
    int _ilosc;

public:
    int getPojemnosc() const { return _pojemnosc; }
    int getIlosc() const { return _ilosc; }

    void setPojemnosc(int pojemnosc) { _pojemnosc = pojemnosc; }
    void setIlosc(int ilosc) { _ilosc = ilosc; }

    Magazyn(int pojemnosc, int ilosc) : _pojemnosc(pojemnosc), _ilosc(ilosc) {}
    Magazyn() : _pojemnosc(0), _ilosc(0) {}
    ~Magazyn() {}

    void pokazStan() const
    {
        std::cout << "Pojemnosc: " << _pojemnosc << std::endl;
        std::cout << "Ilosc: " << _ilosc << std::endl;
    }
};