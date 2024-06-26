#include "Slot.h"

Slot::Slot() : maxSize(0) {}
Slot::Slot(const size_t maxSize) : maxSize(maxSize) {}

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

const std::vector<Item> &Slot::getItems() const
{
    return items;
}

std::string Slot::getItemDetails() const
{
    std::string details;
    for (const auto &item : items)
    {
        details += item.getItemDetails() + "\n";
    }
    return details;
}
