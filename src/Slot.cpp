#include "Slot.h"

// Metoda sprawdzająca czy slot jest pełny
bool Slot::isSlotFull() const
{
    return isFull;
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