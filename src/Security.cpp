#include "Security.h"
#include <fstream>
#include <algorithm>
#include "../lib/json.hpp"

/** @file */

// Definicja aliasu dla nlohmann::json
using json = nlohmann::json;

// Konstruktor dla nowego użytkownika
Security::Security(int id, const std::string &pass = "") : userID(id)
{
    if (!pass.empty())
    {
        // Jeśli podano hasło, zaszyfruj je i zapisz do pliku
        password = encryptPassword(pass);
        savePasswordToFile(userID, password);
    }
}

// Konstruktor dla istniejącego użytkownika
Security::Security(int id) : userID(id)
{
    std::string storedPassword;
    if (loadPasswordFromFile(userID, storedPassword))
    {
        // Jeśli uda się wczytać hasło z pliku, przypisz je do zmiennej password
        password = storedPassword;
    }
}

// Szyfrowanie hasła za pomocą prostego algorytmu
std::string Security::encryptPassword(const std::string &password) const
{
    std::string encrypted = password;

    for (char &c : encrypted)
    {
        if (std::isalpha(c))
        {
            // Szyfrowanie liter: przesunięcie o 10 pozycji w alfabecie
            c = std::isupper(c) ? ((c - 'A' + 10) % 26) + 'A' : ((c - 'a' + 10) % 26) + 'a';
        }
        else if (std::isdigit(c))
        {
            // Szyfrowanie cyfr: przesunięcie o 5 pozycji
            c = ((c - '0' + 5) % 10) + '0';
        }
    }

    return encrypted;
}

// Walidacja logowania
bool Security::loginValidation(const std::string &inputPassword) const
{
    std::string storedPassword;
    if (loadPasswordFromFile(userID, storedPassword))
    {
        // Szyfruj wprowadzone hasło i porównaj z zapisanym
        std::string encryptedInputPassword = encryptPassword(inputPassword);
        return storedPassword == encryptedInputPassword;
    }
    return false;
}

// Zmiana hasła użytkownika
bool Security::changePassword(const std::string &newPassword)
{
    // Szyfruj nowe hasło i zapisz do pliku
    password = encryptPassword(newPassword);
    return savePasswordToFile(userID, password);
}

// Zwracanie ID użytkownika
int Security::getUserID() const { return userID; }

// Zapis zaszyfrowanego hasła do pliku JSON
bool Security::savePasswordToFile(int userID, const std::string &encryptedPassword)
{
    std::ifstream inFile("passwords.json");
    json data;
    if (inFile.is_open())
    {
        // Wczytaj istniejące dane z pliku
        inFile >> data;
        inFile.close();
    }

    // Zaktualizuj dane dla danego użytkownika
    data[std::to_string(userID)] = encryptedPassword;

    std::ofstream outFile("passwords.json");
    if (outFile.is_open())
    {
        // Zapisz zaktualizowane dane do pliku
        outFile << data.dump(4);
        outFile.close();
        return true;
    }
    return false;
}

// Wczytanie zaszyfrowanego hasła z pliku JSON
bool Security::loadPasswordFromFile(int userID, std::string &encryptedPassword)
{
    std::ifstream inFile("passwords.json");
    if (inFile.is_open())
    {
        // Wczytaj dane z pliku
        json data;
        inFile >> data;
        inFile.close();

        // Sprawdź, czy dane dla danego użytkownika istnieją
        std::string key = std::to_string(userID);
        if (data.contains(key))
        {
            encryptedPassword = data[key];
            return true;
        }
    }
    return false;
}
