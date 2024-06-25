#include "Item.h"
#include <optional>

Item::Item(int id, int quantity, int barcode, const std::string &owner, const std::string &itemType)
    : id(id), quantity(quantity), barcode(barcode), owner(owner), itemType(itemType) {}

std::string Item::getItemDetails() const
{
    return "ID: " + std::to_string(id) + ", Quantity: " + std::to_string(quantity) +
           ", Barcode: " + std::to_string(barcode) + ", Owner: " + owner +
           ", Item Type: " + itemType;
}

void Item::updateItemData(std::optional<int> newId, std::optional<int> newQuantity, std::optional<int> newBarcode, std::optional<std::string> newOwner, std::optional<std::string> newItemType) {
    if (newId) {
        id = *newId;
    }
    if (newQuantity) {
        quantity = *newQuantity;
    }
    if (newBarcode) {
        barcode = *newBarcode;
    }
    if (newOwner && !newOwner->empty()) {
        owner = *newOwner;
    }
    if (newItemType && !newItemType->empty()) {
        itemType = *newItemType;
    }

}

int Item::getBarcode() const {
    return barcode;
}

