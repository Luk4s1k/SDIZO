#include <iostream>
#include "DataTypes/Array.h"
#include "Menu.h"

int main() {
    Menu* menu = new Menu();
    menu->arrayCreationMenuMode();
    menu->arrayOperationsMenuMode();

    return 0;
}
