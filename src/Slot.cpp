#include "Slot.h"

// Metoda sprawdzająca czy slot jest pełny
bool Slot::isSlotFull() const
{
    return items.size() == maxSize;
}

// Metoda zwracająca lokalizację slotu
std::string Slot::getLocation() const
{
    return location;
}

// Metoda ustawiająca lokalizację slotu
void Slot::setLocation(const std::string &_location)
{
    location = _location;
}

const std::vector<Item>& Slot::getItems() const {
    return items;
}