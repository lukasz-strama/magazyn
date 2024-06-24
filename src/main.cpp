#include "../test/Security.test.cpp"
#include "../test/BarcodeReader.test.cpp"
#include "../test/Shelft.test.cpp"
#include "../test/Order.test.cpp"
#include <iostream>

int main()
{
    runLoginTests();
    runBarcodeTests();
    shelfTest();
    std::cout << "--------------------------------" << std::endl;
    runOrderTests();

    return 0;
}
