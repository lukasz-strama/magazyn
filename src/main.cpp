#include "../test/SecurityTest.cpp"
#include "../test/BarcodeReaderTest.cpp"
#include "../test/Shelft.test.cpp"

#include "../include/Item.h"
#include "../include/Slot.h"
#include "../include/Palette.h"
#include "../include/Shelf.h"


int main()
{
    runLoginTests();
    runBarcodeTests();
    shelfTest();
    
    return 0;
}
