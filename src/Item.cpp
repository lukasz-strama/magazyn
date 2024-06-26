#include "Item.h"
#include <optional>
#include <stdexcept>
#include <iostream>

// Konstruktor z inicjalizacją wszystkich pól
Item::Item(int id, int quantity, std::string barcode, const std::string &owner, const std::string &itemType)
    : id(id), quantity(quantity), barcode(barcode), owner(owner), itemType(itemType) {}

// Konstruktor domyślny
Item::Item() : id(0), quantity(0), barcode(""), owner(""), itemType("") {}

// Metoda zwracająca barcode przedmiotu
std::string Item::getBarcode() const { return barcode; }

// Metoda zwracająca wszystkie pola przedmiotu
std::string Item::getItemDetails() const
{
    return "ID: " + std::to_string(id) + ", Quantity: " + std::to_string(quantity) +
        ", Barcode: " + barcode + ", Owner: " + owner +
        ", Item Type: " + itemType;
}

// Metoda aktualizująca dane przedmiotu
void Item::updateItemData(std::optional<int> newId, std::optional<int> newQuantity, std::optional<std::string> newBarcode, std::optional<std::string> newOwner, std::optional<std::string> newItemType)
{
    try
    {
        if (newId)
        {
            id = *newId;
        }
        if (newQuantity)
        {
            quantity = *newQuantity;
        }
        if (newBarcode)
        {
            barcode = *newBarcode;
        }
        if (newOwner && !newOwner->empty())
        {
            owner = *newOwner;
        }
        if (newItemType && !newItemType->empty())
        {
            itemType = *newItemType;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error updating item data: " << e.what() << std::endl;
    }
}

