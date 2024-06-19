#ifndef SLOT_H
#define SLOT_H

#include <vector>
#include <string>
#include "Item.h"

/** @file */


/**
 * @class Slot
 * @brief Zarządzanie slotem, umożliwiając dodanie towaru, określenie lokalizacji slotu oraz ustawienie lokalizacji slotu.
 * 
 * Klasa abstrakcyjna, umożliwiająca dodanie towaru, w sytuacji, kiedy miejsce jest puste, w przeciwnym wypadku zwraca false,
 * Pozwala na określenie lokalziacji oraz dodanie lokalizacji slotu.
 * 
 * Klasa ta obsługuje:
 * - dodanie towaru na slot,
 * - ustawienie lokalizacji,
 * - określenie lokalizacji.
 * 
 * 
 * Przykład użycia:
 * @code
 * try{
 * Slot slot; // tworzenie obiektu klasy Slot
 * bool isAdded= slot.addPackage(item); // dodanie towaru
 * if(!isSlotFull){
 * items.push_back(item);
 * return true; // slot jest pusty, dodano towar
 * }
 * else {
 * return false; // slot jest pełny, nie można dodać towaru
 * }
 * }catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
 * }
  slot.setLocation(location); // ustawienie lokalizacji slotu
  slot.getLocation(); // zwrócenie lokalizacji slotu
 * }
 * @endcode
 */


class Slot {
protected:
    std::vector<Item> items; ///< Wektor towarów w slocie
    std::string location;      ///< Lokalizacja slotu
    bool isFull;               ///< Czy slot jest pełny

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
    virtual bool addPackage(const Item& item) = 0;

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
    void setLocation(const std::string& _location);


    virtual ~Slot() = default;
};

#endif // SLOT_H
