#include <iostream>
#include "Security.h"
#include "OrderHistory.h"
#include "Warehouse.h"
#include "Slot.h"
#include "Shelf.h"
#include "Palette.h"
#include "Item.h"

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
    warehouse.populateOrderHistory("orders.json");
    OrderHistory orderHistory = warehouse.getOrderHistory();

    std::cout << "Order History: " << std::endl;
    orderHistory.showAllHistory();

    warehouse.addSlotToStorageUnit(new Shelf(std::make_tuple(2, 5, 10), 1));
    warehouse.addSlotToStorageUnit(new Shelf(std::make_tuple(2, 5, 10), 2));

    warehouse.addSlotToStorageUnit(new Palette("euro"));
    warehouse.addSlotToStorageUnit(new Palette("block"));

    return 0;
}

// Function definitions
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
