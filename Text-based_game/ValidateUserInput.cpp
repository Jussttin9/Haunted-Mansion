#include "ValidateUserInput.h"

#include <limits>
#include <ios>
#include <iostream>
#include <string>

ValidateUserInput::ValidateUserInput() {

}

bool ValidateUserInput::checkValidString(std::string input) {
    for(char c : input) {
        if(!isdigit(c)) return false;
    }
    return true;
}

int ValidateUserInput::getValidInput(int startRange, int endRange) {
    std::string userInput;
    int input = -1;
    std::cin >> userInput;
    
    if(checkValidString(userInput)) {
        if(endRange > 9) {
            std::cout << userInput << std::endl;
            std::cout << stoi(userInput.substr(0,2)) << std::endl;
            input = stoi(userInput.substr(0,2));
        } else {
            input = stoi(userInput.substr(0,1));
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(input < startRange || input > endRange) {
        std::cout << "Please enter a valid number: ";
        std::cin >> userInput;
        if(checkValidString(userInput)) {
            if(endRange > 9) {
                input = stoi(userInput.substr(0,2));
            } else {
                input = stoi(userInput.substr(0,1));
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

bool ValidateUserInput::getCorrectCode(int code, int len) {
    std::string userInput;
    int input;
    std::cout << "It needs some sort of code: ";
    std::cin >> userInput;
    userInput = userInput.substr(0, len);
    input = stoi(userInput);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input == code;
}

void ValidateUserInput::printEndCard(int endingNum) {
    switch(endingNum) {
        case 1:
            std::cout << "--------------------" << std::endl;
            std::cout << "  Self Love Ending  " << std::endl;
            std::cout << "    Ending (1/6)    " << std::endl;
            std::cout << "--------------------" << std::endl;
            break;
        case 2:
            std::cout << "--------------------" << std::endl;
            std::cout << "  Explosive Ending  " << std::endl;
            std::cout << "    Ending (2/6)    " << std::endl;
            std::cout << "--------------------" << std::endl;
            break;
        case 3:
            std::cout << "--------------------" << std::endl;
            std::cout << "  Double Tap Ending " << std::endl;
            std::cout << "    Ending (3/6)    " << std::endl;
            std::cout << "--------------------" << std::endl;
            break;
        case 4:
            std::cout << "--------------------" << std::endl;
            std::cout << "   The Hero Ending  " << std::endl;
            std::cout << "    Ending (4/6)    " << std::endl;
            std::cout << "--------------------" << std::endl;
            break;
        case 5:
            std::cout << "--------------------" << std::endl;
            std::cout << "    Guilty Ending   " << std::endl;
            std::cout << "    Ending (5/6)    " << std::endl;
            std::cout << "--------------------" << std::endl;
            break;
        case 6:
            std::cout << "--------------------" << std::endl;
            std::cout << "   Devoured Ending  " << std::endl;
            std::cout << "    Ending (6/6)    " << std::endl;
            std::cout << "--------------------" << std::endl;
            break;
        default:
            break;
    }
}