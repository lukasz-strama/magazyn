#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
#include "Order.h"
#include <chrono>

/** @class Shipment
 * @brief Klasa zarządzająca wysyłką zamówień.
 * Klasa Shipment przechowuje informacje o przesyłce(kod kreskowy, powiązane zamówienie).
 * 
 * Klasa obsługuje:
 * - przypisanie informacji o przesyłce,
 * - stworzenie zamówienia,
 * - stworzenie przesyłki.
 * 
 * 
 * 
 * Przykład użycia:
 * 
 * @code
 * try{
 * Order order(id, customer, type, details);
 * Shipment shipment(barcode, order);
 * Order aorder = shipment.getOrder();
 * }
 * catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
 * }
 * @endcode
 */

class Shipment
{
public:
/**
     * @brief Konstruktor klasy Shipment inicjujący przesyłkę.
     * 
     * @param barcode Kod kreskowy zamówienia do wysyłki.
     * @param order Zamówienie, obiekt klasy Order.
     */
    Shipment(const std::string &barcode, const Order &order);

/** @brief Publiczna metoda pozwalająca na zebranie informacji o kodzie kreskowym. 
 * 
 * @return zwraca kod kreskowy przesyłki jako string.
*/
    std::string getBarcode() const;

    /**
     * @brief Publiczna metoda zwracająca zamówienie, obiekt klasy Order.
     * 
     * @return zwraca zamówienie do wysyłki.
     */
    Order getOrder() const;

private:
    std::string barcode; /**<Kod kreskowy przesyłki */
    Order order; /**Zamówienie, obiekt klasy Order. */
};

#endif // SHIPMENT_H
