#include "../include/Security.h"
#include <iostream>

void runLoginTests()
{
    if (User::savePasswordToFile(User(1, "initialPassword1"), "initialPassword1"))
    {
        std::cout << "Password for user 1 saved successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to save password for user 1." << std::endl;
    }

    if (User::savePasswordToFile(User(2), "initialPassword2"))
    {
        std::cout << "Password for user 2 saved successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to save password for user 2." << std::endl;
    }

    std::string loadedPassword1, loadedPassword2;
    if (User::loadPasswordFromFile(User(1), loadedPassword1))
    {
        std::cout << "Password for user 1 loaded successfully: " << loadedPassword1 << std::endl;
    }
    else
    {
        std::cout << "Failed to load password for user 1." << std::endl;
    }

    if (User::loadPasswordFromFile(User(2), loadedPassword2))
    {
        std::cout << "Password for user 2 loaded successfully: " << loadedPassword2 << std::endl;
    }
    else
    {
        std::cout << "Failed to load password for user 2." << std::endl;
    }

    if (User(1).loginValidation("initialPassword1"))
    {
        std::cout << "Login for user 1 successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 1 failed." << std::endl;
    }

    if (User(2).loginValidation("initialPassword2"))
    {
        std::cout << "Login for user 2 successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 2 failed." << std::endl;
    }

    if (User(1).loginValidation("wrongPassword"))
    {
        std::cout << "Login for user 1 (wrong password) successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 1 (wrong password) failed." << std::endl;
    }

    if (User(2).loginValidation("wrongPassword"))
    {
        std::cout << "Login for user 2 (wrong password) successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 2 (wrong password) failed." << std::endl;
    }

    if (User(1).changePassword("newPassword1"))
    {
        std::cout << "Password for user 1 changed successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to change password for user 1." << std::endl;
    }

    if (User(2).changePassword("newPassword2"))
    {
        std::cout << "Password for user 2 changed successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to change password for user 2." << std::endl;
    }

    if (User(1).loginValidation("newPassword1"))
    {
        std::cout << "Login for user 1 with new password successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 1 with new password failed." << std::endl;
    }

    if (User(2).loginValidation("newPassword2"))
    {
        std::cout << "Login for user 2 with new password successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 2 with new password failed." << std::endl;
    }
}