#include "Item.h"

Item::Item(int id, int quantity, int barcode, const std::string& owner, const std::string& itemType) 
    : id(id), quantity(quantity), barcode(barcode), owner(owner), itemType(itemType) {}

std::string Item::getItemDetails() const  {
    return "ID: " + std::to_string(id) + ", Quantity: " + std::to_string(quantity) +
           ", Barcode: " + std::to_string(barcode) + ", Owner: " + owner +
           ", Item Type: " + itemType;
}

void Item::updateQuantity(int newQuantity)  {
    quantity = newQuantity;
}
