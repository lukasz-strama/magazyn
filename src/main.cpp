#include <iostream>
#include "Security.h"
#include "BarcodeReader.h"
#include "OrderHistory.h"
#include "Warehouse.h"
#include "Slot.h"
#include "Shelf.h"
#include "Palette.h"
#include "Item.h"
#include "Order.h"

void registerUser(int userID, std::string initialPassword);
bool loginUser(int userID, std::string password);
bool changePassword(int userID, std::string oldPassword, std::string newPassword);

int main()
{
    int userID;
    std::string password;

    std::cout << "Do you have an account? (1 - Yes, 0 - No): ";
    bool hasAccount;
    std::cin >> hasAccount;

    std::cout << "Enter user ID: ";
    std::cin >> userID;

    bool loggedIn = false;

    while (!loggedIn)
    {
        std::cout << "Enter password: ";
        std::cin >> password;

        if (hasAccount)
        {
            loggedIn = loginUser(userID, password);
        }
        else
        {
            registerUser(userID, password);
            hasAccount = true;
            loggedIn = true;
        }

        if (!loggedIn)
        {
            std::cout << "Please try again." << std::endl;
        }
    }

    password = "";

    Warehouse warehouse;
    BarcodeReader reader;

    warehouse.populateOrderHistory("orders.json");
    OrderHistory orderHistory = warehouse.getOrderHistory();

    std::cout << "Order History: " << std::endl;
    orderHistory.showAllHistory();

    Shelf shelf1(std::make_tuple(2, 5, 10), 1);
    Shelf shelf2(std::make_tuple(2, 5, 10), 2);
    Palette palette1("euro");
    Palette palette2("block");

    warehouse.addSlotToStorageUnit(&shelf1);
    warehouse.addSlotToStorageUnit(&shelf2);

    warehouse.addSlotToStorageUnit(&palette1);
    warehouse.addSlotToStorageUnit(&palette2);

    std::string barcode = "";

    reader.generateBarcode(1, "11111", "55555");
    barcode = reader.getBarcode();
    shelf1.addPackage(*(new Item(1, 5, barcode, "Alice", "Electronics")));

    reader.generateBarcode(2, "54321", "11111");
    barcode = reader.getBarcode();
    shelf1.addPackage(*(new Item(2, 10, barcode, "Bob", "Clothing")));

    shelf2.addPackage(*(new Item(3, 15, "67890", "Charlie", "Food")));
    shelf2.addPackage(*(new Item(4, 20, "98765", "David", "Electronics")));

    palette1.addPackage(*(new Item(5, 25, "13579", "Eve", "Clothing")));
    palette1.addPackage(*(new Item(6, 30, "24680", "Frank", "Food")));

    palette2.addPackage(*(new Item(7, 35, "11223", "Grace", "Electronics")));
    palette2.addPackage(*(new Item(8, 40, "33445", "Heidi", "Clothing")));

    std::cout << "Shelf details: " << std::endl;
    std::cout << shelf1.getItemDetails() << std::endl;
    std::cout << shelf2.getItemDetails() << std::endl;

    std::cout << "Palette details: " << std::endl;
    std::cout << palette1.getItemDetails() << std::endl;
    std::cout << palette2.getItemDetails() << std::endl;

    if (shelf1.removePackage("12345"))
    {
        std::cout << "Item removed successfully." << std::endl;
    }
    else
    {
        std::cout << "Item not found." << std::endl;
    }

    std::cout << "Shelf details after removing item: " << std::endl;
    std::cout << shelf1.getItemDetails() << std::endl;

    Order order1(3, "Alice", Order::Type::Outgoing, "Electronics");
    order1.setDetails("Order for electronics");

    warehouse.addOrderToHistory(order1);
    orderHistory = warehouse.getOrderHistory();
    warehouse.saveOrderHistory("orders.json");

    std::cout << "Order History after adding order: " << std::endl;
    orderHistory.showAllHistory();

    return 0;
}

void registerUser(int userID, std::string initialPassword)
{
    try
    {
        User newUser(userID, initialPassword);
        std::cout << "Registered new user successfully." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

bool loginUser(int userID, std::string password)
{
    try
    {
        User existingUser(userID);
        bool isLoggedIn = existingUser.loginValidation(password);
        if (isLoggedIn)
        {
            std::cout << "Logged in as existing user." << std::endl;
            existingUser.logout();
            return true;
        }
        else
        {
            std::cout << "Invalid login credentials." << std::endl;
            return false;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

bool changePassword(int userID, std::string oldPassword, std::string newPassword)
{
    try
    {
        User existingUser(userID);
        bool isLoggedIn = existingUser.loginValidation(oldPassword);
        if (isLoggedIn)
        {
            existingUser.changePassword(newPassword);
            existingUser.logout();
            return true;
        }
        else
        {
            std::cout << "Invalid login credentials." << std::endl;
            return false;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}
