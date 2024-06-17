#ifndef SECURITY_H
#define SECURITY_H

#include <string>

/** @file */

/**
 * @class Security
 * @brief Zarządza systemem logowania, umożliwiając rejestrację, logowanie oraz zmianę hasła użytkownika.
 *
 * Klasa Security zapewnia mechanizmy uwierzytelniania użytkowników oraz zarządzania hasłami.
 * Hasła są szyfrowane za pomocą algorytmu jednokierunkowego i przechowywane w formacie JSON.
 * Dla wygody, można używać aliasu User zamiast Security.
 *
 * Przykład użycia:
 * @code
 *  User user(userID, initialPassword); // dla nowego użytkownika
 *  User user(userID); // dla istniejącego użytkownika
 *  user.validateLogin(providedPassword);
 * @endcode
 */
class Security
{
private:
    int userID;           /**< ID użytkownika */
    std::string password; /**< Hasło użytkownika */

    /**
     * @brief Szyfruje hasło za pomocą algorytmu jednokierunkowego.
     *
     * @param password Hasło do zaszyfrowania
     * @return Zaszyfrowane hasło
     */
    std::string encryptPassword(const std::string &password) const;

    /**
     * @brief Statyczna metoda do zapisu zaszyfrowanego hasła użytkownika do pliku.
     *
     * @param userID ID użytkownika
     * @param encryptedPassword Zaszyfrowane hasło do zapisania
     * @return Zwraca true, jeśli zapis się powiódł, false w przeciwnym razie
     */
    static bool savePasswordToFile(int userID, const std::string &encryptedPassword);

    /**
     * @brief Statyczna metoda do wczytania zaszyfrowanego hasła użytkownika z pliku.
     *
     * @param userID ID użytkownika
     * @param encryptedPassword Zmienna referencyjna, do której zostanie wczytane zaszyfrowane hasło
     * @return Zwraca true, jeśli wczytanie się powiodło, false w przeciwnym razie
     */
    static bool loadPasswordFromFile(int userID, std::string &encryptedPassword);

public:
    /**
     * @brief Konstruktor do rejestracji nowego użytkownika.
     *
     * @param id ID użytkownika
     * @param pass Hasło użytkownika
     */
    Security(int id, const std::string &pass);

    /**
     * @brief Konstruktor do logowania istniejącego użytkownika.
     *
     * @param id ID użytkownika
     */
    Security(int id);

    /**
     * @brief Waliduje próbę logowania za pomocą podanego hasła.
     *
     * @param inputPassword Hasło podane przez użytkownika
     * @return Zwraca true, jeśli hasło jest poprawne, false w przeciwnym razie
     */
    bool loginValidation(const std::string &inputPassword) const;

    /**
     * @brief Zmienia hasło użytkownika na nowe.
     *
     * @param newPassword Nowe hasło do ustawienia
     * @return Zwraca true, jeśli zmiana hasła się powiodła, false w przeciwnym razie
     */
    bool changePassword(const std::string &newPassword);

    /**
     * @brief Zwraca ID użytkownika.
     *
     * @return ID użytkownika
     */
    int getUserID() const;
};

/**
 * @brief Alias dla klasy Security. Umożliwia używanie User zamiast Security.
 */
using User = Security;

#endif // SECURITY_H
