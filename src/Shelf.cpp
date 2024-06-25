#include "Shelf.h"

// Konstruktor z inicjalizacją wymiarów i piętra
Shelf::Shelf(const std::tuple<int, int, int> &dimensions, int floor)
    : dimensions(dimensions), floor(floor) {}

// Metoda zwracająca wymiary półki
std::tuple<int, int, int> Shelf::getDimensions() const
{
    return dimensions;
}

void Shelf::setDimensions(std::tuple<int,int,int> _dimensions) {
    dimensions = _dimensions;
}

// Metoda zwracająca piętro półki
int Shelf::getFloor() const
{
    return floor;
}

void Shelf::setFloor(int _floor) {
    floor = _floor;
}

bool Shelf::addPackage(const Item& item) {
    if (!isSlotFull()) {
        items.push_back(item);
        isFull = true;
        return true;

        if (items.size() >= maxSize) {
            isFull = true;
        }
    }
    return false;
}


bool Shelf::removePackage(const int barcode) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getBarcode() == barcode) {
            items.erase(it);
            isFull = !items.empty(); 
            return true;
        }
    }
    return false;
}