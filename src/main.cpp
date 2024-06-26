#include <iostream>
#include "Security.h"
#include "Warehouse.h"
#include "Slot.h"
#include "Shelf.h"
#include "Palette.h"
#include "Item.h"

bool login(bool login_flag, int login_id, std::string password);

int main()
{
    bool login_flag;
    int login_id;
    std::string password;

    do
    {
        std::cout << "czy posiadasz konto? (1/0)" << std::endl;
        std::cin >> login_flag;

        std::cout << "Podaj login: ";
        std::cin >> login_id;

        std::cout << "Podaj haslo: ";
        std::cin >> password;

    } while (login(login_flag, login_id, password) == false);

    Warehouse warehouse;
    warehouse.populateOrderHistory("orders.json");
    warehouse.addSlotToStorageUnit(new Shelf(std::make_tuple(2, 5, 10), 1));
    warehouse.addSlotToStorageUnit(new Shelf(std::make_tuple(2, 5, 10), 2));

    warehouse.addSlotToStorageUnit(new Palette("euro"));
    warehouse.addSlotToStorageUnit(new Palette("block"));

    return 0;
}

bool login(bool login_flag, int login_id, std::string password)
{

    if (login_flag == true)
    {
        User user(login_id);
        if (user.loginValidation(password))
        {
            std::cout << "Zalogowano" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Bledne dane" << std::endl;
            return false;
        }
    }
    else
    {
        User existingUser(login_id);
        if (existingUser.loginValidation(password))
        {
            std::cout << "Taki uzytkownik juz istnieje" << std::endl;
            return false;
        }
        else
        {
            User user(login_id, password);
            if (user.loginValidation(password))
            {
                std::cout << "Zarejestrowano" << std::endl;
                return true;
            }
            else
            {
                std::cout << "Cos poszlo nie tak" << std::endl;
                return false;
            }
        }
    }
}
