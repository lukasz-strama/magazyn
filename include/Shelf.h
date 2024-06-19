#ifndef SHELF_H
#define SHELF_H

#include "Slot.h"
#include <tuple>

/**
 * @brief Zarządzanie półką.
 */
class Shelf : public Slot {
private:
    std::tuple<int, int, int> dimensions; ///< Wymiary półki
    int floor; ///< Piętro, na którym znajduje się półka

public:
    /**
     * @brief Konstruktor klasy Półka.
     * @param dimensions Wymiary półki.
     * @param floor Piętro, na którym znajduje się półka.
     */
    Shelf(const std::tuple<int, int, int>& dimensions, int floor);

    /**
     * @brief Zwraca wymiary półki.
     * @return Wymiary półki.
     */
    std::tuple<int, int, int> getDimensions() const;

    /**
     * @brief Zwraca piętro, na którym znajduje się półka.
     * @return Piętro.
     */
    int getFloor() const;

    /**
     * @brief Dodaje towar do półki.
     * @param towar Towar do dodania.
     * @return true jeśli towar został dodany, false w przeciwnym razie.
     */
    bool addPackage(const Item& towar) override;
};

#endif // SHELF_H
