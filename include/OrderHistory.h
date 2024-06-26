#ifndef ORDERHISTORY_H
#define ORDERHISTORY_H

#include <vector>
#include "Order.h"
#include "../lib/json.hpp"

/** @class OrderHistory
 *
 * @brief Klasa służąca do przechowywania historii zamówienia.
 *
 * Klasa OrderHistory służy do przechowywania i zarządzania historią zamówień.
 * Umożliwia dodawanie nowych zamówień, pobieranie zamówień na podstawie identyfikatora oraz pobieranie wszystkich zamówień.
 * Klasa obsługuje także pobieranie i przechowywanie danych w formacie JSON,
 * co umożliwia zapisywanie historii zamówień do pliku oraz wczytywanie jej z pliku
 *
 * Klasa obsługuje:
 * - dodawanie nowych zamówień,
 * - pobieranie zamówienia na podstawie ID, wszystkich zamówień,
 * - zapisywanie obiektów Order do pliku JSON,
 * - odczytywanie obiektów Order z pliku JSON.
 *
 * Przykład użycia:
 *
 * try{
 *  OrderHistory history;
 *  history.addOrder(Order(id, customer, type, details));
 * Order order = history.getOrder(id);
 * history.saveToFile(filename);
 * history.loadFromFile(filename);
 * }catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;}
 */

class OrderHistory
{
public:
    /** @brief Publiczna metoda pozwalająca na dodawanie zamówienia do historii.
     * @param order Zamówienie do dodania.
     */
    void addOrder(const Order &order);

    /**
     * @brief Publiczna metoda zwracająca zamówienie.
     * @param id Identyfikator zamówienia.
     */
    Order getOrder(int id) const;

    /** @brief Publiczna metoda zwracająca wszystkie zamówienia.
     * @return zwraca wektor zawierający wszystkie zamówienia.
     */
    std::vector<Order> getAllOrders() const;

    // JSON serialization
    /**
     * @brief Pozwala na zapis histori zamówień do pliku JSON.
     *
     * @param filename Nazwa pliku do zapisu.
     */
    void saveToFile(const std::string &filename) const;

    /**
     * @brief Pozwala na odczyt histori zamówień z pliku JSON.
     *
     * @param filename Nazwa pliku do odczytu.
     */
    void loadFromFile(const std::string &filename);

    void showAllHistory() const;

private:
    std::vector<Order> orders; /**< Wektor przechowujący zamówienia. */
};

#endif // ORDERHISTORY_H
