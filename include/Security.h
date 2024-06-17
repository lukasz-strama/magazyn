#ifndef SECURITY_H
#define SECURITY_H

#include <string>

/** @file */

/**
 * @class Security
 * @brief Zarządza systemem logowania, umożliwiając rejestrację, logowanie, zmianę hasła użytkownika oraz wylogowanie.
 *
 * Klasa Security zapewnia mechanizmy uwierzytelniania użytkowników oraz zarządzania hasłami.
 * Hasła są szyfrowane za pomocą algorytmu jednokierunkowego i przechowywane w formacie JSON.
 * Dla wygody, można używać aliasu User zamiast Security.
 *
 * Klasa ta obsługuje:
 * - Rejestrację nowych użytkowników (szyfrowanie i zapis hasła)
 * - Logowanie istniejących użytkowników (walidacja hasła)
 * - Zmianę hasła (aktualizacja zaszyfrowanego hasła w pliku)
 * - Wylogowanie użytkownika
 *
 *
 *
 * Przykład użycia:
 * @code
 *  try {
 *      User newUser(userID, initialPassword); // rejestracja nowego użytkownika
 *      User existingUser(userID); // logowanie istniejącego użytkownika
 *      bool isLoggedIn = existingUser.loginValidation(providedPassword);
 *      if (isLoggedIn) {
 *          existingUser.changePassword(newPassword); // zmiana hasła
 *          existingUser.logout(); // wylogowanie użytkownika
 *      }
 *  } catch (const std::exception &e) {
 *      std::cerr << "Error: " << e.what() << std::endl;
 *  }
 * @endcode
 */
class Security
{
private:
    int userID;           /**< ID użytkownika */
    std::string password; /**< Hasło użytkownika */
    bool loggedIn;        /**< Status zalogowania użytkownika */

    /**
     * @brief Szyfruje hasło za pomocą algorytmu jednokierunkowego.
     *
     * Algorytm szyfruje litery poprzez przesunięcie o 10 pozycji w alfabecie,
     * a cyfry poprzez przesunięcie o 5 pozycji.
     *
     * @param password Hasło do zaszyfrowania
     * @return Zaszyfrowane hasło
     */
    std::string encryptPassword(const std::string &password) const;

    /**
     * @brief Statyczna metoda do zapisu zaszyfrowanego hasła użytkownika do pliku.
     *
     * Hasło jest przechowywane w pliku JSON, gdzie kluczem jest ID użytkownika,
     * a wartością zaszyfrowane hasło.
     *
     * @param userID ID użytkownika
     * @param encryptedPassword Zaszyfrowane hasło do zapisania
     * @return Zwraca true, jeśli zapis się powiódł, false w przeciwnym razie
     * @throw std::runtime_error w przypadku błędu zapisu do pliku
     */
    static bool savePasswordToFile(int userID, const std::string &encryptedPassword);

    /**
     * @brief Statyczna metoda do wczytania zaszyfrowanego hasła użytkownika z pliku.
     *
     * Wczytuje zaszyfrowane hasło z pliku JSON na podstawie ID użytkownika.
     *
     * @param userID ID użytkownika
     * @param encryptedPassword Zmienna referencyjna, do której zostanie wczytane zaszyfrowane hasło
     * @return Zwraca true, jeśli wczytanie się powiodło, false w przeciwnym razie
     * @throw std::runtime_error w przypadku błędu odczytu z pliku
     */
    static bool loadPasswordFromFile(int userID, std::string &encryptedPassword);

public:
    /**
     * @brief Konstruktor do rejestracji nowego użytkownika.
     *
     * Inicjalizuje obiekt Security dla nowego użytkownika, szyfruje hasło i zapisuje je do pliku.
     *
     * @param id ID użytkownika
     * @param pass Hasło użytkownika
     * @throw std::runtime_error jeśli zapis hasła do pliku się nie powiedzie
     */
    Security(int id, const std::string &pass);

    /**
     * @brief Konstruktor do logowania istniejącego użytkownika.
     *
     * Inicjalizuje obiekt Security dla istniejącego użytkownika, wczytuje zaszyfrowane hasło z pliku.
     *
     * @param id ID użytkownika
     * @throw std::runtime_error jeśli wczytanie hasła z pliku się nie powiedzie
     */
    Security(int id);

    /**
     * @brief Waliduje próbę logowania za pomocą podanego hasła.
     *
     * Sprawdza, czy zaszyfrowane hasło podane przez użytkownika pasuje do zaszyfrowanego
     * hasła przechowywanego w pliku.
     *
     * @param inputPassword Hasło podane przez użytkownika
     * @return Zwraca true, jeśli hasło jest poprawne, false w przeciwnym razie
     */
    bool loginValidation(const std::string &inputPassword);

    /**
     * @brief Zmienia hasło użytkownika na nowe.
     *
     * Szyfruje nowe hasło i zapisuje je do pliku.
     *
     * @param newPassword Nowe hasło do ustawienia
     * @return Zwraca true, jeśli zmiana hasła się powiodła, false w przeciwnym razie
     * @throw std::runtime_error jeśli zapis hasła do pliku się nie powiedzie
     */
    bool changePassword(const std::string &newPassword);

    /**
     * @brief Wylogowuje użytkownika.
     */
    void logout();

    /**
     * @brief Sprawdza, czy użytkownik jest zalogowany.
     *
     * @return Zwraca true, jeśli użytkownik jest zalogowany, false w przeciwnym razie
     */
    bool isLoggedIn() const;
};

/**
 * @brief Alias dla klasy Security. Umożliwia używanie User zamiast Security.
 */
using User = Security;

#endif // SECURITY_H
