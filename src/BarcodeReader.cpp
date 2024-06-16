#include "BarcodeReader.h"
#include <string>
#include <cctype>
#include <algorithm>

/** @file */

int BarcodeReader::calculateChecksum(const std::string &barcode) const
{
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < 11; ++i)
    {
        int digit = barcode[i] - '0';
        if (i % 2 == 0)
        {
            sumOdd += digit;
        }
        else
        {
            sumEven += digit;
        }
    }
    int total = sumOdd * 3 + sumEven;
    int checksum = (10 - (total % 10)) % 10;
    return checksum;
}

BarcodeReader::BarcodeReader() : barcode("") {}

bool BarcodeReader::generateBarcode(char countryCode, const std::string &manufacturerCode, const std::string &productCode)
{
    if (!std::isdigit(countryCode) || manufacturerCode.length() != 5 || productCode.length() != 5 ||
        !std::all_of(manufacturerCode.begin(), manufacturerCode.end(), ::isdigit) ||
        !std::all_of(productCode.begin(), productCode.end(), ::isdigit))
    {
        return false;
    }

    std::string code = countryCode + manufacturerCode + productCode;
    int checksum = calculateChecksum(code);
    barcode = code + std::to_string(checksum);

    return true;
}

bool BarcodeReader::validateBarcode(const std::string &barcode) const
{
    if (barcode.length() != 12)
    {
        return false;
    }
    for (char c : barcode)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    int providedChecksum = barcode[11] - '0';
    int calculatedChecksum = calculateChecksum(barcode.substr(0, 11));
    return providedChecksum == calculatedChecksum;
}

std::string BarcodeReader::getBarcode() const
{
    return barcode;
}