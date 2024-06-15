#ifndef SECURITY_H
#define SECURITY_H

#include <string>

/**
 * @brief Klasa Security odpowiedzialna jest za zarządzanie systemem logowania.
 * Umożliwia logowanie, rejestracje oraz zmiana hasła użytkownika.
 * Dozwolone jest jedynie jednokierunkowe szyfrowanie hasła (zapisywane są w formacie JSON).
 * Dla czytelności dozwolone jest używanie aliasu User zamiast Security.
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
     * @return true jeśli zapis się powiódł, false w przeciwnym razie
     */
    static bool savePasswordToFile(int userID, const std::string &encryptedPassword);

    /**
     * @brief Metoda statyczna do wczytania hasła użytkownika z pliku.
     *
     * @param userID ID użytkownika
     * @param encryptedPassword Zmienna referencyjna, do której zostanie wczytane hasło
     * @return true jeśli wczytanie się powiodło, false w przeciwnym razie
     */
    static bool loadPasswordFromFile(int userID, std::string &encryptedPassword);

public:
    /**
     * @brief Konstruktor inicjalizujący obiekt Security.
     *
     * @param id ID użytkownika
     * @param pass Opcjonalne: hasło użytkownika (domyślnie puste)
     */
    Security(int id, const std::string &pass = "");

    /**
     * @brief Funkcja do walidacji logowania.
     *
     * @param inputPassword Hasło podane przez użytkownika
     * @return true jeśli hasło jest poprawne, false w przeciwnym razie
     */
    bool loginValidation(const std::string &inputPassword) const;

    /**
     * @brief Funkcja do zmiany hasła użytkownika.
     *
     * @param newPassword Nowe hasło do ustawienia
     * @return true jeśli zmiana hasła powiodła się, false w przeciwnym razie
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
