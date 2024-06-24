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
     * @brief Bezparametrowy konstruktor klasy Item.
     */
    Item(); 

    /**
     * @brief Zwraca szczegóły towaru.
     * @return Szczegóły towaru w formacie string.
     */
    std::string getItemDetails() const ;

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
