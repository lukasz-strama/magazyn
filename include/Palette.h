#ifndef Palette_H
#define Palette_H

#include <string>
#include "Slot.h"

/**
 * @brief Zarzadzanie paletą.
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
    void setType(const std::string &type);

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
    bool addPackage(const Item &item) override;
};

#endif // Palette_H
