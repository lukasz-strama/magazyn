#ifndef SECURITY_H
#define SECURITY_H

#include <string>
#include <unordered_map>

/**
 * @brief Klasa Security odpowiedzialna za zarządzanie bezpieczeństwem użytkowników.
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

    /**
     * @brief Metoda statyczna do zapisu hasła użytkownika do pliku.
     *
     * @param sec Obiekt Security do którego należy zapis hasła
     * @param password Hasło do zapisania
     * @return true jeśli zapis się powiódł, false w przeciwnym razie
     */
    static bool savePasswordToFile(const Security &sec, const std::string &password);

    /**
     * @brief Metoda statyczna do wczytania hasła użytkownika z pliku.
     *
     * @param sec Obiekt Security do którego należy wczytać hasło
     * @param password Zmienna referencyjna, do której zostanie wczytane hasło
     * @return true jeśli wczytanie się powiodło, false w przeciwnym razie
     */
    static bool loadPasswordFromFile(const Security &sec, std::string &password);
};

#endif // SECURITY_H