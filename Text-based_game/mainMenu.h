#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <string>


class mainMenu {
    private:
        int getValidInput();
    public:
        mainMenu();
        std::string getInput();
};

#endif