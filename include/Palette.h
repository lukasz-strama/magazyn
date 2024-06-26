#ifndef Palette_H
#define Palette_H

#include <string>
#include "Slot.h"

/**
 * @class Palette
 * @brief Klasa pozwalająca na zarzadzanie paletą,
 * dziedzicząca po klasie abstrakcyjnej Slot.
 *
 *
 * Klasa obsługuje:
 * - ustawienie na wybranej palecie,
 * -ustawienie typu palety,
 * - zwraca true jeśli towar może być dodany, false w przeciwnym wypadku.
 *
 * Przykład użycia:
 *
 * @code
 * try{
 * Palette palette;
 * palette.setType(type);
 * Item item1();
        bool added1 = palette.addPackage(item1);
       if (added1){
       //dodano na paletę
       }
       else{
       //nie dodano na paletę
       }
 * }catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
 * }
 * @endcode
 */
class Palette : public Slot
{
private:
    std::string type; ///< Typ palety

public:
    /**
     * @brief Konstruktor domyślny klasy Palette.
     * Konstruktor domyślny klasy Palette.
     */
    Palette();

    /**
     * @brief Konstruktor klasy Palette.
     * Konstruktor pozwala zainicjalizować dane o palecie,
     * Umożliwiając określenie typu palety.
     */
    Palette(const std::string type);

    /**
     * @brief Konstruktor klasy Palette.
     * Konstruktor pozwala zainicjalizować dane o palecie,
     * Umożliwiając określenie typu palety oraz maksymalnego rozmiaru.
     *
     * @param type Typ palety.
     * @param maxSize Maksymalny rozmiar palety.
     */
    Palette(const std::string type, const int maxSize);

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

    /**
     * @brief Usuwa towar z palety.
     * @param barcode Kod towaru do usuniecia.
     * @return true jeśli towar został usuniety, false w przeciwnym razie.
     */
    bool removePackage(const std::string barcode) override;
};

#endif // Palette_H
