#include "Palette.h"

Palette::Palette(const std::string type) : type(type) {}

std::string Palette::getType() const
{
    return type;
}

void Palette::setType(const std::string &_type)
{
    type = _type;
}

bool Palette::addPackage(const Item &item)
{
    if (!isSlotFull())
    {
        items.push_back(item);
        return true;
    }
    return false;
}

bool Palette::removePackage(const int barcode)
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