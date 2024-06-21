#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
#include "Order.h"

class Shipment
{
public:
    Shipment(const std::string &barcode, const Order &order);

    std::string getBarcode() const;
    Order getOrder() const;

private:
    std::string barcode;
    Order order;
};

#endif // SHIPMENT_H
