#include "Palette.h"

std::string Palette::getType() const {
    return type;
}

void Palette::setType(const std::string& _type) {
    type = _type;
}

bool Palette::addPackage(const Item& item) {
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


bool Palette::removePackage(const int barcode) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getBarcode() == barcode) {
            items.erase(it);
            isFull = !items.empty(); // Update the isFull status
            return true;
        }
    }
    return false;
}