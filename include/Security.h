#ifndef SECURITY_H
#define SECURITY_H

#include <string>

/**
 * @file
 * @brief Klasa Security odpowiedzialna jest za zarządzanie systemem logowania.
 * - Umożliwia logowanie, rejestracje oraz zmiana hasła użytkownika.
 * - Szyfruje hasła jednokierunkowo i zapisuej je w formacie JSON do pliku.
 * - Dla czytelności dozwolone jest używanie aliasu User zamiast Security.
 *
 * Przykład użycia:
 * @code
 *  User user(userID, initialPassword); // dla nowego użytkownika
 *  User user(userID); // dla istniejacego użytkownika
 *  user.validateLogin(providedPassword);
 * @endcode
 */
class Security
{
private:
    int userID;           /**< ID użytkownika */
    std::string password; /**< Hasło użytkownika */

    /**
     * @brief Funkcja szyfrująca hasło jednokierunkowo.
     *
     * @param password Hasło do zaszyfrowania
     * @return Zaszyfrowane hasło
     */
    std::string encryptPassword(const std::string &password) const;

    /**
     * @brief Metoda statyczna do zapisu hasła użytkownika do pliku.
     *
     * @param userID ID użytkownika
     * @param encryptedPassword Zaszyfrowane hasło do zapisania
     * @return Zwraca true jeśli zapis się powiódł, false w przeciwnym razie
     */
    static bool savePasswordToFile(int userID, const std::string &encryptedPassword);

    /**
     * @brief Metoda statyczna do wczytania hasła użytkownika z pliku.
     *
     * @param userID ID użytkownika
     * @param encryptedPassword Zmienna referencyjna, do której zostanie wczytane hasło
     * @return Zwraca true jeśli wczytanie się powiodło, false w przeciwnym razie
     */
    static bool loadPasswordFromFile(int userID, std::string &encryptedPassword);

public:
    /**
     * @brief Konstruktor inicjalizujący obiekt Security, służy do rejestracji nowego użytkownika.
     *
     * @param id ID użytkownika
     * @param pass hasło użytkownika
     */
    Security(int id, const std::string &pass);

    /**
     * @brief Konstruktor inicjalizujący obiekt Security, służy do logowania istniejącego użytkownika.
     *
     * @param id ID użytkownika
     */
    Security(int id);

    /**
     * @brief Funkcja do walidacji logowania.
     *
     * @param inputPassword Hasło podane przez użytkownika
     * @return Zwraca true jeśli hasło jest poprawne, false w przeciwnym razie
     */
    bool loginValidation(const std::string &inputPassword) const;

    /**
     * @brief Funkcja do zmiany hasła użytkownika.
     *
     * @param newPassword Nowe hasło do ustawienia
     * @return Zwraca true jeśli zmiana hasła powiodła się, false w przeciwnym razie
     */
    bool changePassword(const std::string &newPassword);

    /**
     * @brief Funkcja zwracająca ID użytkownika.
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
