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

public:
    /**
     * @brief Dodaje towar do slotu.
     * @param towar Towar do dodania.
     * @return true jeśli towar został dodany, false w przeciwnym razie.
     */
    virtual bool addPackage(const Item& item) = 0;

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


    virtual ~Slot() = default;
};

#endif // SLOT_H
