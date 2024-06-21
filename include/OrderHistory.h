#ifndef ORDERHISTORY_H
#define ORDERHISTORY_H

#include <vector>
#include "Order.h"
#include "../lib/json.hpp"

class OrderHistory
{
public:
    void addOrder(const Order &order);
    Order getOrder(int id) const;
    std::vector<Order> getAllOrders() const;

    // JSON serialization
    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);

private:
    std::vector<Order> orders;
};

#endif // ORDERHISTORY_H
