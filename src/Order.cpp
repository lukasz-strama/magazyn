#include "Order.h"

Order::Order(int id, const std::string &customer, Type type, const std::string &details)
    : id(id), customer(customer), type(type), details(details) {}

int Order::getId() const
{
    return id;
}

std::string Order::getCustomer() const
{
    return customer;
}

Order::Type Order::getType() const
{
    return type;
}

std::string Order::getDetails() const
{
    return details;
}

nlohmann::json Order::toJson() const
{
    return nlohmann::json{{"id", id}, {"customer", customer}, {"type", type == Type::Incoming ? "Incoming" : "Outgoing"}, {"details", details}};
}

Order Order::fromJson(const nlohmann::json &j)
{
    int id = j.at("id").get<int>();
    std::string customer = j.at("customer").get<std::string>();
    std::string typeStr = j.at("type").get<std::string>();
    Type type = (typeStr == "Incoming") ? Type::Incoming : Type::Outgoing;
    std::string details = j.at("details").get<std::string>();
    return Order(id, customer, type, details);
}
