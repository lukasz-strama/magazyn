#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include <string>
#include "Item.h"
#include "Slot.h"
#include "OrderHistory.h"

/**
 * @class Warehouse
 * @brief Klasa reprezentująca magazyn.
 * 
 * Klasa Warehouse pozwala na zarządzanie magazynem, w tym dodawanie i usuwanie slotów, 
 * wyszukiwanie przedmiotów, oraz zarządzanie historią zamówień.
 * 
 * 
 * @code
 * try{
 *  Warehouse warehouse;
 *  Slot *slot1 = new Slot();
 *  warehouse.addSlotToStorageUnit(slot1);
 *  Item item1();
 *  slot1->addItem(item1);
 *  warehouse.saveOrderHistory("plik_typu_json.json");
 *  warehouse.populateOrderHistory("plik_typu_json.json");
 *  OrderHistory history = warehouse.getOrderHistory();
 *  warehouse.removeSlotFromStorageUnit(slot1);
 *  delete slot1;
 * 
 * }catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;}
 * @endcode
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
