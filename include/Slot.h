#ifndef SLOT_H
#define SLOT_H

#include <vector>
#include <string>
#include "Item.h"

/**
 * @class Slot
 * @brief Klasa abstrakcyjna, która pozwala na przypisywanie lokalizacji towarom.
 * Każdy slot posiada wektor przechowujący obiekty typu Item,
 * lokalizację określoną przez łańcuch znaków oraz stan informujący, czy slot jest pełny.
 * Klasa ta zawiera metody do dodawania towarów, sprawdzania, czy slot jest pełny,
 * oraz zarządzania lokalizacją slotu.
 *
 */

class Slot
{
protected:
    std::vector<Item> items; ///< Wektor towarów w slocie
    std::string location;    ///< Lokalizacja slotu
    bool isFull;             ///< Czy slot jest pełny
    size_t maxSize;          ///< Maksymalny rozmiar tablicy

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
     * @brief Usuwa dany towar ze slotu.
     * @param barcode Item do usuniecia.
     * @return true jeśli towar został usuniety, false w przeciwnym razie.
     */
    virtual bool removePackage(const int barcode) = 0;

    /**
     * @brief Sprawdza czy slot jest pełny.
     * @return true jeśli slot jest pełny, false w przeciwnym razie.
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

    const std::vector<Item> &getItems() const;

    virtual ~Slot() = default;
};

#endif // SLOT_H
