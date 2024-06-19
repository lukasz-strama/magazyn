#include "../test/Security.test.cpp"
#include "../test/BarcodeReader.test.cpp"
#include "../test/Shelft.test.cpp"

int main()
{
    runLoginTests();
    runBarcodeTests();
    shelfTest();

    return 0;
}
