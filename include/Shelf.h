#ifndef SHELF_H
#define SHELF_H

#include "Slot.h"
#include <tuple>

/** @file */

/**
 * @class Shelf
 * @brief Klasa zarządzająca półką, umożliwiając scharakteryzowanie półki oraz dodać towar na półkę.
 *
 * Klasa Shelf pozwala dodać wymairy półki, określić piętro, na którym jest półka oraz dodać towar na wybraną półkę.
 *
 * Klasa ta obsługuje:
 * - dodawanie charakterystyki półki (wymiary, piętro),
 * - ułożenie towaru na półkę, jeśli jest pusta.
 *
 * Przykład użycia:
 * @code
 * try{
 * Shelf newShelf (dimensions); // zainicjalizowanie nowego obiektu klasy Shelf
 * bool isAdded = newShelf.addPackage(item);
 * if(!isSlotFull){
 * items.push_back(item);
 * return true; // półka jest pusta, dodano towar
 * }
 * else
 * return false; // półka jest pełna, nie można dodać towaru
 * }
 * catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
 * }
 * @endcode
 */
class Shelf : public Slot
{
private:
    std::tuple<int, int, int> dimensions; ///< Wymiary półki
    int floor;                            ///< Piętro, na którym znajduje się półka

public:
    /**
     * @brief Konstruktor klasy Półka.
     * Konstruktor pozwala zainicjalizować dane o półce,
     * Umożliwiając określenie wymiarów oraz piętra.
     *
     * @param dimensions Wymiary półki.
     * @param floor Piętro, na którym znajduje się półka.
     */
    Shelf(const std::tuple<int, int, int> &dimensions, int floor, const size_t maxSize);
    /**
     * @brief Publiczna metoda, zwracająca wymiary półki.
     * @return zwraca wymiary półki.
     */
    std::tuple<int, int, int> getDimensions() const;

    /**
     * @brief Ustawia wymiary półki.
     */
    void setDimensions(std::tuple<int, int, int> __dimensions);

    /**
     * @brief Publiczna metoda, zwracajaca piętro, na którym znajduje się półka.
     * @return zwraca piętro.
     */
    int getFloor() const;

    /**
     * @brief Ustawia piętro, na którym znajduje się półka.
     */
    void setFloor(int _floor);

    /**
     * @brief Publiczna metoda, umożliwiająca dodanie towaru do półki.
     * @param towar Towar do dodania.
     *
     * Metoda sprawdza, czy:
     * - wybrana półka jest pełna.
     *
     * W sytuacji, w której półka jest pusta, zwraca true,
     * W przeciwnej sytuacji zwraca false (półka jest zajęta).
     *
     * @return true jeśli towar został dodany, false w przeciwnym razie.
     */
    bool addPackage(const Item &towar) override;

    /**
     * @brief Usuwa towar z palety.
     * @param barcode Kod towaru do usuniecia.
     * @return true jeśli towar został usuniety, false w przeciwnym razie.
     */
    bool removePackage(const std::string barcode) override;
};

#endif // SHELF_H
