#include "Shelf.h"

// Konstruktor z inicjalizacją wymiarów i piętra półki
Shelf::Shelf(const std::tuple<int, int, int> &dimensions, int floor, const int maxSize) : Slot(maxSize), floor(floor), dimensions(dimensions) {}

// Metoda zwracająca wymiary półki
std::tuple<int, int, int> Shelf::getDimensions() const
{
    return dimensions;
}

void Shelf::setDimensions(std::tuple<int, int, int> _dimensions)
{
    dimensions = _dimensions;
}

// Metoda zwracająca piętro półki
int Shelf::getFloor() const
{
    return floor;
}

void Shelf::setFloor(int _floor)
{
    floor = _floor;
}

bool Shelf::addPackage(const Item &item)
{
    if (!isSlotFull())
    {
        items.push_back(item);
        return true;
    }
    return false;
}

bool Shelf::removePackage(const std::string barcode)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getBarcode() == barcode)
        {
            items.erase(it);
            return true;
        }
    }
    return false;
}