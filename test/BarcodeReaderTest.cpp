#include "../include/BarcodeReader.h"
#include <iostream>

void runBarcodeTests()
{
    try
    {
        BarcodeReader b;

        b.generateBarcode('1', "23456", "78901");
        std::string generatedBarcode = b.getBarcode();
        std::cout << "Generated Barcode: " << generatedBarcode << std::endl;

        if (b.validateBarcode(generatedBarcode))
        {
            std::cout << "The barcode " << generatedBarcode << " is valid." << std::endl;
        }
        else
        {
            std::cout << "The barcode " << generatedBarcode << " is invalid." << std::endl;
        }

        std::string invalidBarcode = generatedBarcode;
        invalidBarcode[0] = (invalidBarcode[0] == '0') ? '1' : '0';
        if (b.validateBarcode(invalidBarcode))
        {
            std::cout << "The barcode " << invalidBarcode << " is valid." << std::endl;
        }
        else
        {
            std::cout << "The barcode " << invalidBarcode << " is invalid." << std::endl;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
