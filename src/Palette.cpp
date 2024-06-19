#include "Palette.h"

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
        isFull = true;
        return true;
    }
    return false;
}