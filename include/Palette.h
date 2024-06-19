#ifndef Palette_H
#define Palette_H

#include <string>
#include "Slot.h"

/**
 * @brief Zarzadzanie paletą.
 */
class Palette : public Slot
{
private:
    std::string type; ///< Typ palety

public:
    /**
     * @brief Zwraca typ palety.
     * @return Typ palety.
     */
    std::string getType() const;

    /**
     * @brief Ustawia typ palety.
     * @param type Typ palety.
     */
    void setType(const std::string &type);

    /**
     * @brief Dodaje towar do palety.
     * @param towar Towar do dodania.
     * @return true jeśli towar został dodany, false w przeciwnym razie.
     */
    bool addPackage(const Item &item) override;
};

#endif // Palette_H
