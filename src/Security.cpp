#include "Security.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include "../lib/json.hpp"

/** @file */

using json = nlohmann::json;

// Konstruktor dla nowego użytkownika
Security::Security(int id, const std::string &pass) : userID(id), loggedIn(false)
{
    if (!pass.empty())
    {
        password = encryptPassword(pass);
        if (!savePasswordToFile(userID, password))
        {
            throw std::runtime_error("Failed to save password to file.");
        }
    }
}

// Konstruktor dla istniejącego użytkownika
Security::Security(int id) : userID(id), loggedIn(false)
{
    std::string storedPassword;
    if (!loadPasswordFromFile(userID, storedPassword))
    {
        throw std::runtime_error("Failed to load password from file.");
    }
    password = storedPassword;
}

// Szyfrowanie hasła za pomocą prostego algorytmu
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

// Walidacja logowania
bool Security::loginValidation(const std::string &inputPassword)
{
    std::string storedPassword;
    if (loadPasswordFromFile(userID, storedPassword))
    {
        std::string encryptedInputPassword = encryptPassword(inputPassword);
        if (storedPassword == encryptedInputPassword)
        {
            loggedIn = true;
            return true;
        }
    }
    return false;
}

// Zmiana hasła
bool Security::changePassword(const std::string &newPassword)
{
    if (!loggedIn)
    {
        throw std::runtime_error("User is not logged in.");
    }

    password = encryptPassword(newPassword);
    if (!savePasswordToFile(userID, password))
    {
        throw std::runtime_error("Failed to save password to file.");
    }
    return true;
}

// Wylogowanie użytkownika
void Security::logout()
{
    loggedIn = false;
}

// Sprawdzenie, czy użytkownik jest zalogowany
bool Security::isLoggedIn() const
{
    return loggedIn;
}

// Zapis hasła do pliku
bool Security::savePasswordToFile(int userID, const std::string &encryptedPassword)
{
    std::ifstream inFile("passwords.json");
    json data;
    if (inFile.is_open())
    {
        try
        {
            inFile >> data;
        }
        catch (const json::parse_error &e)
        {
            inFile.close();
            throw std::runtime_error("JSON parse error: " + std::string(e.what()));
        }
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

// Wczytanie hasła z pliku
bool Security::loadPasswordFromFile(int userID, std::string &encryptedPassword)
{
    std::ifstream inFile("passwords.json");
    if (inFile.is_open())
    {
        json data;
        try
        {
            inFile >> data;
        }
        catch (const json::parse_error &e)
        {
            inFile.close();
            throw std::runtime_error("JSON parse error: " + std::string(e.what()));
        }
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
