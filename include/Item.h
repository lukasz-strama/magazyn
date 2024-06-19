#ifndef ITEM_H
#define ITEM_H

#include <string>

/** @file */

/**
 * @brief Służy do przechowywania informacji o towarze.
 */
class Item {
private:
    int id;             ///< Identyfikator towaru
    int quantity;       ///< Ilość towaru
    int barcode;        ///< Kod kreskowy towaru
    std::string owner;  ///< Właściciel towaru
    std::string itemType; ///< Typ towaru

public:
    /**
     * @brief Konstruktor klasy Towar.
     * @param id Identyfikator towaru.
     * @param quantity Ilość towaru.
     * @param barcode Kod kreskowy towaru.
     * @param owner Właściciel towaru.
     * @param itemType Typ towaru.
     */
    Item(int id, int quantity, int barcode, const std::string& owner, const std::string& itemType) ;

    /**
     * @brief Zwraca szczegóły towaru.
     * @return Szczegóły towaru w formacie string.
     */
    std::string getItemDetails() const ;

    /**
     * @brief Aktualizuje ilość towaru.
     * @param newQuantity Nowa ilość towaru.
     */
    void updateQuantity(int newQuantity) ;
};

#endif // ITEM_H
