#ifndef BARCODEREADER_H
#define BARCODEREADER_H

#include <string>

/** @file */

/** @class BarcodeReader
 * @brief Służy do generowania kodu towaru, sprawdzania jego poprawności
 * 
 * Klasa BarcodeReader pozwala na utworzenie kodu towaru, w celu ułatwienia zarządzania towarami na magazynie. 
 * Kod towaru składa się z ciągu 12 znaków i jest tworzony na podstawie schematu, wykorzystującego m.in. sumę kontrolną.
 * 
 * Klasa obsługuje:
 * - zliczanie sumy kontrolnej, umożliwiającej stworzenie kodu
 * - generowanie kodu towaru
 * - sprawdzanie poprawności wytworzonego kodu 
 * 
 * 
 * Przykład użycia: 
 * 
 * TO DO
 * 
 */
class BarcodeReader
{
private:
    std::string barcode; /**< ciąg znaków kodu towaru */

    int calculateChecksum(const std::string &barcode) const; /**<zliczanie sumy kontrolnej */

    /**
     * @brief Suma kontrolna zliczana jest w następujący sposób:
     * @param sumEven liczona jest suma cyfr na parzystych pozycjach,
     * @param sumOdd liczona jest suma cyfr na nieparzystych pozycjach,
     * @param total obliczana jest wartość sumy liczb: sumEven oraz potrojonej sumOdd,
     * @param checkSum to (10- reszta z dzielenia total przez 10), a następnie brana jest reszta z dzielenia przez 10 podanej różnicy,
     * @return Suma kontrolna (zwrócona wartość jest cyfrą). 
     */

public:
    BarcodeReader(); /**Konstruktor ustawiający wartość początkową kodu towaru */

    bool generateBarcode(char countryCode, const std::string &manufacturerCode, const std::string &productCode);
    /** @brief 
     * Publiczna metoda pozwalająca na tworzenie kodu towaru, 
     * zwracająca false, jeżeli podany warunek nie zostanie spełniony, true w przeciwnym wypadku.
     * 
     * Warunek składa się z:
     * @param countryCode znak reprezentujący kod kraju,
     * @param manufacturerCode pięciocyfrowy kod producenta,
     * @param productCode pięciocyfrowy kod produktu.
     * 
     * Warunek sprawdza, czy:
     * - countryCode jest cyfrą,
     * - manufacturerCode oraz productCode są ciągami 5 cyfr.
     * 
     * W sytuacji zwrócenia true, generowany jest kod, następujący sposób:
     * - tworzy ciąg cyfr łącząc countryCode, manufacturerCode, productCode,
     * - po obliczeniu checkSum dodaje ją na koniec ciągu cyfr, tworząc kod towaru.
     */

    bool validateBarcode(const std::string &barcode) const;
    /** @brief
     * Publiczna metoda sprawdzająca poprawność utworzonego kodu,
     * zwracająca false, jeżeli podany warunek nie zostanie spełniony, true w przeciwnym wypadku.
     * 
     * Warunek składa się z:
     * @param barcode ciąg znaków tworzący kod towaru.
     * 
     * Warunek sprawdza, czy:
     * - ciąg składa się z 12 znaków,
     * - czy znaki tworzące kod są cyframi.
     * 
     * Jeżeli została zwróona wartość true, sprawdzana jest poprawność ostatniej cyfry,
     * reprezentującej checkSum. 
     * Jeżeli obliczona checkSum z 11 pierwszych cyfr kodu pokrywa się z checkSum, 
     * zwrócony zostaje poprawny kod towaru.
     */

    std::string getBarcode() const;
    /** @brief 
     * Metoda zwracająca aktualną wartość kodu towaru. 
     * Jeśli wartość nie została ustawiona zostanie zwrócony pusty ciąg znaków.
     */
};

#endif // BARCODEREADER_H
