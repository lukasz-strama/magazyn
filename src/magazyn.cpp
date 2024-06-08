#include "Magazyn.h"
#include <iostream>

Magazyn::Magazyn(int pojemnosc, int ilosc) : _pojemnosc(pojemnosc), _ilosc(ilosc) {}
Magazyn::Magazyn() : _pojemnosc(0), _ilosc(0) {}

Magazyn::~Magazyn() {}

int Magazyn::getPojemnosc() const { return _pojemnosc; }

int Magazyn::getIlosc() const { return _ilosc; }

void Magazyn::setPojemnosc(int pojemnosc) { _pojemnosc = pojemnosc; }

void Magazyn::setIlosc(int ilosc) { _ilosc = ilosc; }

void Magazyn::pokazStan() const
{
    std::cout << "Pojemnosc: " << _pojemnosc << std::endl;
    std::cout << "Ilosc: " << _ilosc << std::endl;
}
