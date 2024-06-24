#include "Warehouse.h"
#include <algorithm> 

// Metoda dodająca slot do jednostek magazynowych
bool Warehouse::addSlotToStorageUnit(Slot* slot) {
    if(slot) {
        storageUnits.push_back(slot);
        return true;
    }
    return false;
}

// Metoda usuwająca slot z jednostki magazynowej
bool Warehouse::removeSlotFromStorageUnit(const Slot* slot) {
    auto it = std::find(storageUnits.begin(), storageUnits.end(), slot);
    if(it != storageUnits.end()) {
        storageUnits.erase(it);
        return true;
    }
    return false;
}

// Metoda wyszukująca przedmiot po kodzie kreskowym
Item Warehouse::searchItem(int barcode) const {
    for(const auto& slot : storageUnits) {
        for(const auto& item : slot->getItems()) {
            if(item.getBarcode() == barcode) {
                return item;
            }
        }
    }
    return Item(); // Pusty przedmiot jako domyślna wartość
}

