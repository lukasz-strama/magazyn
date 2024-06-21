#include "../include/Order.h"
#include "../include/Shipment.h"
#include "../include/OrderHistory.h"
#include <iostream>

void runOrderTests()
{
    try
    {
        Order order1(1, "John Doe", Order::Type::Incoming, "Order details");
        Order order2(2, "Jane Doe", Order::Type::Outgoing, "Order details");

        Shipment shipment1("12345", order1);
        Shipment shipment2("67890", order2);

        OrderHistory history;
        history.addOrder(order1);
        history.addOrder(order2);

        history.saveToFile("orders.json");

        OrderHistory newHistory;
        newHistory.loadFromFile("orders.json");

        std::vector<Order> orders = newHistory.getAllOrders();
        for (const Order &order : orders)
        {
            std::cout << "Order ID: " << order.getId() << std::endl;
            std::cout << "Customer: " << order.getCustomer() << std::endl;
            std::cout << "Type: " << (order.getType() == Order::Type::Incoming ? "Incoming" : "Outgoing") << std::endl;
            std::cout << "Details: " << order.getDetails() << std::endl;
            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}