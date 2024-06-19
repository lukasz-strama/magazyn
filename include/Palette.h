#ifndef Palette_H
#define Palette_H

#include <string>
#include "Slot.h"

/** @file */

/**
 * @class Palette 
 * @brief Zarzadzanie paletą, umożliwiając dodawanie na slot.
 * 
 * Klasa Palette pozwala na zarządzanie paletą, określenie jej typu.
 * Pozwala również na dodawanie na slot w razie, gdy jest on pusty. 
 * 
 * Klasa ta obsługuje:
 * - określanie typu palety,
 * - ustawienie palety na slocie. 
 *  
 * 
 * 
 * Przykład użycia:
 * @code
 * try{
 * Palette newPalette(type); // stworzenie objektu klasy Palette
 * bool isAdded = newPalette.addPackage(item); // dodanie towaru na paletę
 * if(!isSlotFull){
 * items.push_back(item);
 * return true; // paleta jest pusta, dodano towar
 * }
 * else 
 * return false; // paleta jest pełna, nie można dodać towaru
 * }
 * catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
 * @endcode
 */

class Palette : public Slot{
private:
    std::string type; ///< Typ palety

public:
    /**
     * @brief Metoda publiczna, zwracająca typ palety.
     * @param type Typ palety
     * 
     * @return zwraca typ palety jako string.
     */
    std::string getType() const;

    /**
     * @brief Metoda publiczna, umożliwiająca ustawienie typu palety.
     * 
     * @param type Typ palety.
     */
    void setType(const std::string& type);

    /**
     * @brief Metoda publiczna, która umożliwia dodanie towaru do palety.
     * @param towar Towar do dodania.
     * 
     * Warunek sprawdza, czy:
     * - wybrana paleta jest pełna.
     * 
     * W sytuacji zwrócenia true, towar dodawany jest na paletę,
     * W przeciwnej sytuacji (paleta jest pełna), zwraca false.
     * 
     * @return true jeśli towar został dodany, false w przeciwnym razie.
     */
    bool addPackage(const Item& item) override;
};

#endif // Palette_H
