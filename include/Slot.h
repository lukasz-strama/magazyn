#ifndef SLOT_H
#define SLOT_H

#include <vector>
#include <string>
#include "Item.h"

/**
 * @brief Abstrakcyjna klasa reprezentująca towar.
 */
class Slot {
protected:
    std::vector<Item> items; ///< Wektor towarów w slocie
    std::string location;      ///< Lokalizacja slotu
    bool isFull;               ///< Czy slot jest pełny
    size_t maxSize;          ///< Maksymalny rozmiar tablicy

public:
    /**
     * @brief Dodaje towar do slotu.
     * @param towar Towar do dodania.
     * @return true jeśli towar został dodany, false w przeciwnym razie.
     */
    virtual bool addPackage(const Item& item) = 0;

    /**
     * @brief Usuwa dany towar ze slotu.
     * @param barcode Item do usuniecia.
     * @return true jeśli towar został usuniety, false w przeciwnym razie.
     */
    virtual bool removePackage(const int barcode) = 0;


    /**
     * @brief Sprawdza czy slot jest pełny.
     * @return true jeśli slot jest pełny, false w przeciwnym razie.
     */
    bool isSlotFull() const;

    /**
     * @brief Zwraca lokalizację slotu.
     * @return Lokalizacja slotu.
     */
    std::string getLocation() const;

    /**
     * @brief Ustawia lokalizację slotu.
     */
    void setLocation(const std::string& _location);

    const std::vector<Item>& getItems() const;

    virtual ~Slot() = default;
};

#endif // SLOT_H
