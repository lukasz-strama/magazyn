#include "Shelf.h"
#include <iostream>
#include <exception>

// Konstruktor z inicjalizacją wymiarów i piętra półki
Shelf::Shelf(const std::tuple<int, int, int> &dimensions, int floor, const size_t maxSize) : Slot(maxSize), dimensions(dimensions), floor(floor) {}

// Metoda zwracająca wymiary półki
std::tuple<int, int, int> Shelf::getDimensions() const { return dimensions;}

// Metoda ustawiająca wymiary półki
void Shelf::setDimensions(std::tuple<int, int, int> _dimensions) { dimensions = _dimensions; }

// Metoda zwracająca piętro półki
int Shelf::getFloor() const { return floor; }

// Metoda ustawiająca piętro półki
void Shelf::setFloor(int _floor) { floor = _floor; }


// Metoda dodająca przedmiot do półki
bool Shelf::addPackage(const Item &item)
{
    try
    {
        if (!isSlotFull())
        {
            items.push_back(item);
            return true;
        }
        return false;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error adding package: " << e.what() << std::endl;
        return false;
    }
}

// Metoda usuwająca przedmiot z półki
bool Shelf::removePackage(const std::string barcode)
{
    try
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
    catch (const std::exception &e)
    {
        std::cerr << "Error removing package: " << e.what() << std::endl;
        return false;
    }
}
