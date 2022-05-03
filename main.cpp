#include <iostream>
#include "Menu/MainMenu/MainMenu.h"
#include "DataTypes/PrintHelper.h"


int main() {
//        MainMenu *menu = new MainMenu();
//        menu->mainMenuMode();
    RBTree *tree = new RBTree("/Users/lukamitrovic/Desktop/testdatafile.txt");
    PrintHelper *p = new PrintHelper(tree);
    p->test();

        return 0;
}
