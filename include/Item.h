#ifndef ITEM_H
#define ITEM_H

#include <string>

/** @file */

/**
 * @class Item
 * @brief Służy do przechowywania informacji o towarze.
 * 
 * Klasa Item zawiera informacje takie jak: 
 * identyfikator towaru, ilość towaru, wygenerowany i przypisany kod towaru, kto jest właścicielem oraz jakiego typu jest towar. 
 * 
 * Klasa ta obsługuje:
 * - scharakteryzowanie towaru znajdującego się na magazynie,
 * - zaktualizowanie ilości towaru.
 * 
 * Przykład użycia:
 * @code
 * try{
 * Item newItem(id, quantity, barcode, owner, itemType); // zainicjalizowanie nowego obiektu klasy Item
 * std::cout << newItem.getItemDetails(); // wyświetlenie danych o towarze
 * newItem.updateQuantity(quantity) // zaktualizowanie danych o ilości towaru
 * 
 * } catch (const std::exception &e) {
 *      std::cerr << "Error: " << e.what() << std::endl;
 * }
 * @endcode
 */
class Item
{
private:
    int id;               ///< Identyfikator towaru
    int quantity;         ///< Ilość towaru
    int barcode;          ///< Kod kreskowy towaru
    std::string owner;    ///< Właściciel towaru
    std::string itemType; ///< Typ towaru

public:
    /**
     * @brief Konstruktor klasy Item.
     * 
     * Zadaniem konstruktora jest zainicjalizowanie objektu.
     * 
     * @param id Identyfikator towaru.
     * @param quantity Ilość towaru.
     * @param barcode Kod kreskowy towaru.
     * @param owner Właściciel towaru.
     * @param itemType Typ towaru.
     */
    Item(int id, int quantity, int barcode, const std::string &owner, const std::string &itemType);

     /**
     * @brief Bezparametrowy konstruktor klasy Item.
     */
    Item(); 

    /**
     * @brief Publiczna metoda, zwracająca dane towaru.
     * Dane charakteryzujące towar to: identyfikator, ilość, kod, właściciel oraz typ. 
     * 
     * @return zwraca szczegóły towaru w formacie string.
     */
    std::string getItemDetails() const;

    /**
     * @brief Aktualizuje dane towaru.
     * @param newId Nowy identyfikator towaru (opcjonalny).
     * @param newQuantity Nowa ilość towaru (opcjonalna).
     * @param newBarcode Nowy kod kreskowy towaru (opcjonalny).
     * @param newOwner Nowy właściciel towaru (opcjonalny).
     * @param newItemType Nowy typ towaru (opcjonalny).
     */
    void updateItemData(std::optional<int> newId = std::nullopt, std::optional<int> newQuantity = std::nullopt, std::optional<int> newBarcode = std::nullopt, std::optional<std::string> newOwner = std::nullopt, std::optional<std::string> newItemType = std::nullopt);

    /**
     * @brief Zwraca barcode towaru.
     * @return Barcode towaru w formacie string.
     */
    int getBarcode() const ;



};

#endif // ITEM_H
