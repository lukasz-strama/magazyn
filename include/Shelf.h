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
     * @brief Ustawia wymiary półki.
     */
    void setDimensions(std::tuple<int, int, int> __dimensions);


    /**
     * @brief Zwraca piętro, na którym znajduje się półka.
     * @return Piętro.
     */
    int getFloor() const;

     /**
     * @brief Ustawia piętro, na którym znajduje się półka.
     */
    void setFloor(int _floor) ;
    

    /**
     * @brief Dodaje towar do półki.
     * @param towar Towar do dodania.
     * @return true jeśli towar został dodany, false w przeciwnym razie.
     */
    bool addPackage(const Item& towar) override;

     /**
     * @brief Usuwa towar z palety.
     * @param barcode Kod towaru do usuniecia.
     * @return true jeśli towar został usuniety, false w przeciwnym razie.
     */
    bool removePackage(const int barcode) override;
};

#endif // SHELF_H
