#include "Shipment.h"

Shipment::Shipment(const std::string &barcode, const Order &order)
    : barcode(barcode), order(order) {}

std::string Shipment::getBarcode() const
{
    return barcode;
}

Order Shipment::getOrder() const
{
    return order;
}
