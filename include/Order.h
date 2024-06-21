// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "../lib/json.hpp"

class Order
{
public:
    enum class Type
    {
        Incoming,
        Outgoing
    };

    Order(int id, const std::string &customer, Type type, const std::string &details);

    int getId() const;
    std::string getCustomer() const;
    Type getType() const;
    std::string getDetails() const;

    // JSON serialization
    nlohmann::json toJson() const;
    static Order fromJson(const nlohmann::json &j);

private:
    int id;
    std::string customer;
    Type type;
    std::string details;
};

#endif // ORDER_H
