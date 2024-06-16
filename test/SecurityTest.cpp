#include "../include/Security.h"
#include <iostream>

void runLoginTests()
{
    try
    {
        User user1(1, "initialPassword1");
        User user2(2, "initialPassword2");
        User user3(3, "initialPassword3");

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

        if (user1.changePassword("newPassword50"))
        {
            std::cout << "Password for user 1 changed successfully." << std::endl;
        }
        else
        {
            std::cout << "Failed to change password for user 1." << std::endl;
        }

        if (user2.changePassword("newPassword60"))
        {
            std::cout << "Password for user 2 changed successfully." << std::endl;
        }
        else
        {
            std::cout << "Failed to change password for user 2." << std::endl;
        }

        if (user1.loginValidation("newPassword50"))
        {
            std::cout << "Login for user 1 with new password successful." << std::endl;
        }
        else
        {
            std::cout << "Login for user 1 with new password failed." << std::endl;
        }

        if (user2.loginValidation("newPassword60"))
        {
            std::cout << "Login for user 2 with new password successful." << std::endl;
        }
        else
        {
            std::cout << "Login for user 2 with new password failed." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}