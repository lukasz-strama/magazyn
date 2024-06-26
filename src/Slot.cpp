#include "Slot.h"
#include <exception>
#include <iostream>

// Konstruktor domyślny
Slot::Slot() : maxSize(0) {}

// Konstruktor z inicjalizacją maksymalnej pojemności
Slot::Slot(const size_t maxSize) : maxSize(maxSize) {}

// Metoda sprawdzająca czy slot jest pełny
bool Slot::isSlotFull() const {  return items.size() == maxSize; }

// Metoda zwracająca lokalizację slotu
std::string Slot::getLocation() const { return location;}

// Metoda ustawiająca lokalizację slotu
void Slot::setLocation(const std::string &_location) { location = _location;}

// Metoda dodająca przedmiot do slotu
const std::vector<Item> &Slot::getItems() const { return items; }


// Metoda usuwająca przedmiot z slotu
std::string Slot::getItemDetails() const
{
    try
    {
        std::string details;
        for (const auto &item : items)
        {
            details += item.getItemDetails() + "\n";
        }
        return details;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error getting item details: " << e.what() << std::endl;
        return "Error retrieving item details";
    }
}