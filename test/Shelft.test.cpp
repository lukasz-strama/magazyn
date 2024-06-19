#include "../include/Shelf.h"
#include "../include/Item.h"
#include "../include/Palette.h"

#include <iostream>

void shelfTest()
{

        Shelf shelf(std::make_tuple(10, 10, 10), 1);
        std::cout << "Wymiary półki: " << std::get<0>(shelf.getDimensions()) << "x" << std::get<1>(shelf.getDimensions()) << "x" << std::get<2>(shelf.getDimensions()) << std::endl;
    
        Item item(1, 1, 1233232, "Daniel", "drewno");
        std::cout << item.getItemDetails() << std::endl;
        item.updateQuantity(2);

        shelf.addPackage(item);
        shelf.setLocation("Magazyn 1");
        std::cout <<"Lokalizacja polki: " << shelf.getLocation()  << std::endl;

        Palette palette;
        palette.setType("drewniana");
        std::cout << "Typ palety: " << palette.getType() << std::endl;
        palette.addPackage(item);
        std::cout << "Czy paleta jest pełna: " << palette.isSlotFull() << std::endl;
        
   
}