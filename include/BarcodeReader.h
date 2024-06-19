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
 * @code 
 * 
 * try {
 *  BarcodeReader newBarcode; // stworzenie nowego objektu
 *  bool isValidBarcode = newBarcode.generateBarcode(countryCode, manufacturerCode, productCode); // generowanie nowego kodu towaru
 *  if (isValidBarcode) {
        std::string completeBarcode = newBarcode.getBarcode(); // poprawny kod towaru
            } else { // niepoprawny kod towaru
            }
} catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
 *  @endcode
 */

class BarcodeReader
{
private:
    std::string barcode; /**< ciąg znaków kodu towaru */

    int calculateChecksum(const std::string &barcode) const; /**<zliczanie sumy kontrolnej */

    /**
     * @brief Metoda prywatna zliczająca sumę kontrolną,
     * W następujący sposób:
     * @param sumEven liczona jest suma cyfr na parzystych pozycjach,
     * @param sumOdd liczona jest suma cyfr na nieparzystych pozycjach,
     * @param total obliczana jest wartość sumy liczb: sumEven oraz potrojonej sumOdd,
     * @param checkSum to (10- reszta z dzielenia total przez 10), a następnie brana jest reszta z dzielenia przez 10 podanej różnicy,
     * @return Suma kontrolna (zwrócona wartość jest cyfrą). 
     */

public:
/** @brief Konstruktor ustawiający wartość początkową kodu towaru */
    BarcodeReader(); 

 /** @brief 
     * Publiczna metoda pozwalająca na tworzenie kodu towaru, 
     * 
     * @return zwracająca false, jeżeli podany warunek nie zostanie spełniony, true w przeciwnym wypadku.
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
    bool generateBarcode(char countryCode, const std::string &manufacturerCode, const std::string &productCode);
   
/** @brief
     * Publiczna metoda sprawdzająca poprawność utworzonego kodu,
     * 
     * @return zwracająca false, jeżeli podany warunek nie zostanie spełniony, true w przeciwnym wypadku.
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
    bool validateBarcode(const std::string &barcode) const;
    
/** @brief 
     * Metoda zwracająca aktualną wartość kodu towaru. 
     * Jeśli wartość nie została ustawiona zostanie zwrócony pusty ciąg znaków.
     */
    std::string getBarcode() const;
    
};

#endif // BARCODEREADER_H
