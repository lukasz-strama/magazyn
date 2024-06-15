#include "Security.h"
#include <fstream>
#include <algorithm>
#include "../lib/json.hpp"

using json = nlohmann::json;

Security::Security(int id, const std::string &pass) : userID(id)
{
    if (!pass.empty())
    {
        password = encryptPassword(pass);
        savePasswordToFile(userID, password);
    }
}

std::string Security::encryptPassword(const std::string &password) const
{
    std::string encrypted = password;

    for (char &c : encrypted)
    {
        if (std::isalpha(c))
        {
            c = std::isupper(c) ? ((c - 'A' + 10) % 26) + 'A' : ((c - 'a' + 10) % 26) + 'a';
        }
        else if (std::isdigit(c))
        {
            c = ((c - '0' + 5) % 10) + '0';
        }
    }

    return encrypted;
}

bool Security::loginValidation(const std::string &inputPassword) const
{
    std::string storedPassword;
    if (loadPasswordFromFile(userID, storedPassword))
    {
        std::string encryptedInputPassword = encryptPassword(inputPassword);
        return storedPassword == encryptedInputPassword;
    }
    return false;
}

bool Security::changePassword(const std::string &newPassword)
{
    password = encryptPassword(newPassword);
    return savePasswordToFile(userID, password);
}

int Security::getUserID() const { return userID; }

bool Security::savePasswordToFile(int userID, const std::string &encryptedPassword)
{
    std::ifstream inFile("passwords.json");
    json data;
    if (inFile.is_open())
    {
        inFile >> data;
        inFile.close();
    }

    data[std::to_string(userID)] = encryptedPassword;

    std::ofstream outFile("passwords.json");
    if (outFile.is_open())
    {
        outFile << data.dump(4);
        outFile.close();
        return true;
    }
    return false;
}

bool Security::loadPasswordFromFile(int userID, std::string &encryptedPassword)
{
    std::ifstream inFile("passwords.json");
    if (inFile.is_open())
    {
        json data;
        inFile >> data;
        inFile.close();

        std::string key = std::to_string(userID);
        if (data.contains(key))
        {
            encryptedPassword = data[key];
            return true;
        }
    }
    return false;
}
