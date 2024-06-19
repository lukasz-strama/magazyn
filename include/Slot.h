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
    std::string location;    ///< Lokalizacja slotu
    bool isFull;             ///< Czy slot jest pełny

public:
    /**
     * @brief Publiczna metoda, dodająca towar do slotu.
     * Zwrca true, jeśli dodanie towaru jest możliwe, false w przeciwnym wypadku.
     * 
     * @param towar Towar do dodania.
     * 
     * Warunek sprawdza, czy:
     * - na wybrany slot możliwe jest dodoanie towaru.
     * 
     * W sytuacji zwrócenia true, towar dodawany jest na slot,
     * W przeciwnej sytuacji (slot jest pełny), zwraca false.
     * 
     * @return zwraca true, jeśli towar został dodany, false kiedy dodanei towaru nie jest możliwe.
     */
    virtual bool addPackage(const Item &item) = 0;

    /**
     * @brief Publiczna metoda, sprawdzająca, czy slot jest pełny.
     * 
     * Warunek sprawdza, czy:
     * - wybrany slot jest pełny.
     * 
     * W sytuacji zwrócenia true, slot jest pusty, możliwe jest dodanie towaru,
     * W przeciwnej sytuacji (slot jest pełny), zwraca false.
     * 
     * @return zwraca true, jeśli slot jest pełny, false w przeciwnym wypadku.
     */
    bool isSlotFull() const;

    /**
     * @brief Zwraca lokalizację slotu.
     * 
     * @return zwraca lokalizację slotu.
     */
    std::string getLocation() const;

    /**
     * @brief Ustawia lokalizację slotu.
     */
    void setLocation(const std::string &_location);

    virtual ~Slot() = default;
};

#endif // SLOT_H
