#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include <string>
#include "Item.h"
#include "Slot.h"
#include "OrderHistory.h"

/**
 * @brief Klasa reprezentująca magazyn.
 */
class Warehouse
{
private:
    std::vector<Slot *> storageUnits; ///< Wektor jednostek magazynowych
    OrderHistory orderHistory;        ///< Historia zamówień

public:
    /**
     * @brief Dodaje slot do jednostek magazynowych.
     * @param slot Slot do dodania.
     * @return true jeśli slot został dodany, false w przeciwnym razie.
     */
    bool addSlotToStorageUnit(Slot *slot);

    /**
     * @brief Usuwa slot z jednostki magazynowej.
     * @param slot Slot do usunięcia.
     * @return true jeśli slot został usunięty, false w przeciwnym razie.
     */
    bool removeSlotFromStorageUnit(const Slot *slot);

    /**
     * @brief Wyszukuje przedmiot po kodzie kreskowym.
     * @param barcode Kod kreskowy przedmiotu do wyszukania.
     * @return Znaleziony przedmiot.
     */
    Item searchItem(std::string barcode) const;

    /**
     * @brief Wypełnia historię zamówień danymi z pliku JSON.
     * @param filename Nazwa pliku do odczytu.
     * @return true jeśli operacja się powiodła, false w przeciwnym razie.
     */
    bool populateOrderHistory(const std::string &filename);

    /**
     * @brief Zapisuje historię zamówień do pliku JSON.
     * @param filename Nazwa pliku do zapisu.
     * @return true jeśli operacja się powiodła, false w przeciwnym razie.
     */
    bool saveOrderHistory(const std::string &filename) const;

    /**
     * @brief Dodaje zamówienie do historii zamówień.
     * @param order Zamówienie do dodania.
     * @return true jeśli zamówienie zostało dodane, false w przeciwnym razie.
     */
    bool addOrderToHistory(const Order &order);

    /**
     * @brief Zwraca historię zamówień.
     * @return Historia zamówień.
     */
    OrderHistory getOrderHistory() const;
};

#endif // WAREHOUSE_H
