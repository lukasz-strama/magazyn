#include "Warehouse.h"
#include <algorithm>
#include <iostream>
#include <exception>


// Metoda zwracajaca historie zamówień
OrderHistory Warehouse::getOrderHistory() const  { return orderHistory; }

// Metoda dodająca slot do jednostek magazynowych
bool Warehouse::addSlotToStorageUnit(Slot *slot)
{
    try
    {
        if (slot)
        {
            storageUnits.push_back(slot);
            return true;
        }
        return false;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error adding slot to storage unit: " << e.what() << std::endl;
        return false;
    }
}

// Metoda usuwająca slot z jednostki magazynowej
bool Warehouse::removeSlotFromStorageUnit(const Slot *slot)
{
    try
    {
        auto it = std::find(storageUnits.begin(), storageUnits.end(), slot);
        if (it != storageUnits.end())
        {
            storageUnits.erase(it);
            return true;
        }
        return false;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error removing slot from storage unit: " << e.what() << std::endl;
        return false;
    }
}

// Metoda wyszukująca przedmiot po kodzie kreskowym
Item Warehouse::searchItem(std::string barcode) const
{
    try
    {
        for (const auto &slot : storageUnits)
        {
            for (const auto &item : slot->getItems())
            {
                if (item.getBarcode() == barcode)
                {
                    return item;
                }
            }
        }
        return Item(); // Pusty przedmiot jako domyślna wartość
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error searching item: " << e.what() << std::endl;
        return Item(); // Zwraca pusty przedmiot w przypadku błędu
    }
}


// Metoda zczytująca zamoówienia z pliku
bool Warehouse::populateOrderHistory(const std::string &filename)
{
    try
    {
        orderHistory.loadFromFile(filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error populating order history: " << e.what() << std::endl;
        return false;
    }
}

// Metoda zapisująca historię zamówień do pliku
bool Warehouse::saveOrderHistory(const std::string &filename) const
{
    try
    {
        orderHistory.saveToFile(filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving order history: " << e.what() << std::endl;
        return false;
    }
}

// Metoda dodająca zamówienie do historii
bool Warehouse::addOrderToHistory(const Order &order)
{
    try
    {
        orderHistory.addOrder(order);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error adding order to history: " << e.what() << std::endl;
        return false;
    }
}


