#include "../include/Security.h"
#include <iostream>

void runLoginTests()
{
    User user1(1, "initialPassword1");
    User user2(2, "initialPassword2");

    if (user1.loginValidation("initialPassword1"))
    {
        std::cout << "Login for user 1 successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 1 failed." << std::endl;
    }

    if (user2.loginValidation("initialPassword2"))
    {
        std::cout << "Login for user 2 successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 2 failed." << std::endl;
    }

    if (user1.loginValidation("wrongPassword"))
    {
        std::cout << "Login for user 1 (wrong password) successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 1 (wrong password) failed." << std::endl;
    }

    if (user2.loginValidation("wrongPassword"))
    {
        std::cout << "Login for user 2 (wrong password) successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 2 (wrong password) failed." << std::endl;
    }

    if (user1.changePassword("newPassword1"))
    {
        std::cout << "Password for user 1 changed successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to change password for user 1." << std::endl;
    }

    if (user2.changePassword("newPassword2"))
    {
        std::cout << "Password for user 2 changed successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to change password for user 2." << std::endl;
    }

    if (user1.loginValidation("newPassword1"))
    {
        std::cout << "Login for user 1 with new password successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 1 with new password failed." << std::endl;
    }

    if (user2.loginValidation("newPassword2"))
    {
        std::cout << "Login for user 2 with new password successful." << std::endl;
    }
    else
    {
        std::cout << "Login for user 2 with new password failed." << std::endl;
    }
}