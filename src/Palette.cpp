#include "Palette.h"
#include <iostream>
#include <exception>

// Konstruktor domyślny
Palette::Palette() {}

// Konstruktor z inicjalizacją typu i maksymalnej pojemności
Palette::Palette(const std::string type, const size_t maxSize) : Slot(maxSize), type(type) {}

// Konstruktor z inicjalizacją typu
Palette::Palette(const std::string type) : type(type) {}

// Metoda zwracająca typ palety
std::string Palette::getType() const {  return type; }

// Metoda ustawiająca typ palety
void Palette::setType(const std::string &_type)  { type = _type;}

// Metoda dodająca przedmiot do palety
bool Palette::addPackage(const Item &item)
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

// Metoda usuwająca przedmiot z palety
bool Palette::removePackage(const std::string barcode)
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
