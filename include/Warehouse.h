#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include <string>
#include "Item.h"
#include "Slot.h"


/**
 * @brief Klasa reprezentująca magazyn.
 */
class Warehouse {
private:
    std::vector<Slot*> storageUnits; ///< Wektor jednostek magazynowych

public:
    /**
     * @brief Dodaje slot do jednostek magazynowych.
     * @param slot Slot do dodania.
     * @return true jeśli slot został dodany, false w przeciwnym razie.
     */
    bool addSlotToStorageUnit(Slot* slot);

    /**
     * @brief Usuwa slot z jednostki magazynowej.
     * @param slot Slot do usunięcia.
     * @return true jeśli slot został usunięty, false w przeciwnym razie.
     */
    bool removeSlotFromStorageUnit(const Slot* slot);

    /**
     * @brief Wyszukuje przedmiot po kodzie kreskowym.
     * @param barcode Kod kreskowy przedmiotu do wyszukania.
     * @return Znaleziony przedmiot.
     */
    Item searchItem(int barcode) const;
};

#endif // WAREHOUSE_H
