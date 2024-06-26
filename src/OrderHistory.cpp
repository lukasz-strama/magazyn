#include "OrderHistory.h"
#include <fstream>
#include <iostream>

void OrderHistory::addOrder(const Order &order)
{
    orders.push_back(order);
}

Order OrderHistory::getOrder(int id) const
{
    for (const auto &order : orders)
    {
        if (order.getId() == id)
        {
            return order;
        }
    }
    throw std::runtime_error("Order not found");
}

std::vector<Order> OrderHistory::getAllOrders() const
{
    return orders;
}

void OrderHistory::saveToFile(const std::string &filename) const
{
    nlohmann::json j;
    for (const auto &order : orders)
    {
        j.push_back(order.toJson());
    }

    std::ofstream file(filename);
    if (file.is_open())
    {
        file << j.dump(4); // Pretty print with 4 spaces
        file.close();
    }
}

void OrderHistory::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        nlohmann::json j;
        file >> j;
        file.close();

        orders.clear();
        for (const auto &item : j)
        {
            orders.push_back(Order::fromJson(item));
        }
    }
}

bool OrderHistory::orderExists(int id) const
{
    for (const auto &order : orders)
    {
        if (order.getId() == id)
        {
            return true;
        }
    }
    return false;
}

void OrderHistory::showAllHistory() const
{
    for (const auto &order : orders)
    {
        std::cout << order.getId() << " " << order.getCustomer() << " " << order.getDetails() << std::endl;
    }
}