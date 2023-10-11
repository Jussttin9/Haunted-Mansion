#include "mainMenu.h"
#include <iostream>
#include <string>
#include <limits>
#include <ios>

mainMenu::mainMenu() {
    std::cout << "---------------" << std::endl;
    std::cout << "Haunted Mansion" << std::endl;
    std::cout << "1. Start" << std::endl;
    std::cout << "2. Exit" << std::endl;   
    std::cout << "---------------" << std::endl; 
}

std::string mainMenu::getInput() {
    int input = getValidInput();

    switch (input)
    {
        case 1:
            return "Start";
            break;
        case 2:
            return "Exit";
            break;
        default:
        return "";
            break;
    }
}

int mainMenu::getValidInput() {
    char userInput;
    int input;
    std::cin >> userInput;
    input = (int)(userInput - '0');
    while(input < 1 || input > 2) {

        std::cout << "Please enter a valid number: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> userInput;
        input = (int)(userInput - '0');
    }
    return input;
}