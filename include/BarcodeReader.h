#ifndef BARCODEREADER_H
#define BARCODEREADER_H

#include <string>

class BarcodeReader
{
private:
    std::string barcode;

    int calculateChecksum(const std::string &barcode) const;

public:
    BarcodeReader();

    bool generateBarcode(char countryCode, const std::string &manufacturerCode, const std::string &productCode);
    bool validateBarcode(const std::string &barcode) const;
    std::string getBarcode() const;
};
;

#endif // BARCODEREADER_H
