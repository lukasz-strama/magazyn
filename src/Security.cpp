#include "Security.h"
#include <fstream>
#include <algorithm>
#include "json.hpp"

using json = nlohmann::json;

Security::Security(int id, const std::string &pass) : userID(id), password(pass) {}

std::string Security::encryptPassword(const std::string &password) const
{
    std::string encrypted = password;
    std::transform(encrypted.begin(), encrypted.end(), encrypted.begin(), [](char c)
                   { return c + 1; });
    return encrypted;
}

bool Security::loginValidation(const std::string &inputPassword) const
{
    std::string storedPassword;
    if (loadPasswordFromFile(*this, storedPassword))
    {
        std::string encryptedInputPassword = encryptPassword(inputPassword);
        return storedPassword == encryptedInputPassword;
    }
    return false;
}

bool Security::changePassword(const std::string &newPassword)
{
    return savePasswordToFile(*this, newPassword);
}

int Security::getUserID() const { return userID; }

bool Security::savePasswordToFile(const Security &sec, const std::string &password)
{
    std::ifstream inFile("passwords.json");
    json data;
    if (inFile.is_open())
    {
        inFile >> data;
        inFile.close();
    }

    std::string encryptedPassword = sec.encryptPassword(password);

    data[std::to_string(sec.getUserID())] = encryptedPassword;

    std::ofstream outFile("passwords.json");
    if (outFile.is_open())
    {
        outFile << data.dump(4);
        outFile.close();
        return true;
    }
    return false;
}

bool Security::loadPasswordFromFile(const Security &sec, std::string &password)
{
    std::ifstream inFile("passwords.json");
    if (inFile.is_open())
    {
        json data;
        inFile >> data;
        inFile.close();

        std::string key = std::to_string(sec.getUserID());
        if (data.contains(key))
        {
            password = data[key];
            return true;
        }
    }
    return false;
}
