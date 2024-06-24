#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "../lib/json.hpp"

/** @class Order 
 * @brief Reprezentująca zamówienia towarów.
 * 
 * Klasa Order pozwala na zarządzanie zamówieniami.
 * Każde zamówienie identyfikowane jest za pomocą: 
 * ID, nazwy klienta, typu zamówienia (czy jest ono przychodzące czy wychodzące), szczegółów.
 * 
 * Klasa obsługuje:
 * -tworzenie zamówienia,
 * - zbieranie informacji dotyczących paczki (ID, nazwa klienta, typ, szczegóły),
 * - pobieranie/ dodawanie informacji w formacie JSON.
 * 
 * 
 * Przykład użycia:
 *  
 * try{
 * Order order1(id, customer, type, details);
 * order1.setDetails(details);
 * nlohmann::json jsonOrder = order1.toJson();
 * 
 * Order order2 = Order::fromJson(jsonOrder);
 * 
 * }catch{
 * catch (const std::exception &e) {
 *       std::cerr << "Error: " << e.what() << std::endl;
 * }
*/

class Order
{
public:

/** @brief Typ wyliczeniowy reprezentujący typ zamówienia. */
    enum class Type
    {
        Incoming, //zamówienie przychodzące
        Outgoing //zamówienie wychodzące
    };

/** @brief Konstruktor klasy Order
    */

    Order(int id, const std::string &customer, Type type, const std::string &details);

/** @brief Metoda publiczna zwracająca ID zamówienia.
 *  @param id Identyfikator zamówienia.
 *  @return Zwraca ID zamówienia.
 */
    int getId() const;

    /** 
 *  @brief Metoda publiczna zwracająca dane klienta.
 *  @param customer Klient.
 *  @return Zwraca dane klienta.
 */
    std::string getCustomer() const;

    /** 
 *  @brief Metoda publiczna zwracająca typ zamówienia.
 *  @param type Typ zamówienia (przychodzące/ wychodzące).
 *  @return Zwraca typ paczki.
 */
    Type getType() const;

     /** 
 *  @brief Metoda publiczna zwracająca szczegóły zamówienia.
 *  @param details Dane szczegółowe paczki.
 *  @return Zwraca szczegóły paczki.
 */
    std::string getDetails() const;

 /** 
 *  @brief Metoda publiczna ustawiająca szczegóły zamówienia.
 *  @param details Dane szczegółowe paczki.
 */
    void setDetails(const std::string &details);

    /**
     * @brief Deserializuje obiekt Order z formatu JSON.
     * 
     * @param j Obiekt JSON.
     * @return zwraca obiekt Order utworzony na podstawie danych JSON.
     */
    nlohmann::json toJson() const;
    static Order fromJson(const nlohmann::json &j);

private:
    int id; /**<ID zamówienia */
    std::string customer; /**<dane klienta */
    Type type; /**<typ zamówienia */
    std::string details; /**<szczegóły zamówienia */
};

#endif // ORDER_H
