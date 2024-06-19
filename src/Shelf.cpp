#include "Shelf.h"

// Konstruktor z inicjalizacją wymiarów i piętra
Shelf::Shelf(const std::tuple<int, int, int>& dimensions, int floor)
    : dimensions(dimensions), floor(floor) {}

// Metoda zwracająca wymiary półki
std::tuple<int, int, int> Shelf::getDimensions() const {
    return dimensions;
}

// Metoda zwracająca piętro półki
int Shelf::getFloor() const {
    return floor;
}

// Metoda dodająca przedmiot na półkę
bool Shelf::addPackage(const Item& item) {
    if (!isSlotFull()) {
        items.push_back(item);
        return true;
    }
    return false;
}
