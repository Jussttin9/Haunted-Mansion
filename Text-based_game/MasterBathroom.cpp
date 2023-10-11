#include "MasterBathroom.h"
#include "ValidateUserInput.h"

#include <iostream>
#include <vector>
#include <string>

MasterBathroom::MasterBathroom() {
    visited = false;
    name = "";
    for(int i = 0; i < 3; i++) {
        visitedLocation[i] = false;
    }
}

void MasterBathroom::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "The entire bathroom was broken into pieces. All of the items such as shampoo, conditioner, hand soap, and other bathroom essentials were scattered and broken across the floor. It was hard not to step on any of them. Maybe there could be something useful hidden in here." << std::endl;
        visited = true;
    }
}

void MasterBathroom::printInteractables() {
    std::cout << "----------------" << std::endl;
    std::cout << "1. Broken Toilet" << std::endl;
    std::cout << "2. Broken Sink" << std::endl;
    std::cout << "3. Broken Shower" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "----------------" << std::endl;
}

void MasterBathroom::getInput() {
    int input = checkInput.getValidInput(1,4);
    while(input != 4) {
        switch(input) {
            case 1:
                std::cout << "-------------" << std::endl;
                std::cout << "Broken Toilet" << std::endl;
                std::cout << "-------------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "I took a look inside the broken toilet bowl and saw something metal at the bottom of the bowl. It looked like a key. I was relieved that the toilet was nothing like the one downstairs or else there would be no way I would be sticking my hand down here. I took the key from the toilet bowl and put it in my pocket. I'm guessing this could've opened the basement door downstairs since that was the only locked door that I haven't unlocked yet." << std::endl;
                    items.push_back("Basement Key");
                } else {
                    std::cout << "I think I've looked at enough toilets for today." << std::endl;
                }
                std::cout << "-------------" << std::endl;
                break;
            case 2:
                std::cout << "-----------" << std::endl;
                std::cout << "Broken Sink" << std::endl;
                std::cout << "-----------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    std::cout << "The sink bowl had been completely torn off from the wall and its small, shattered pieces made walking around a lot harder than it should've been." << std::endl;
                } else {
                    std::cout << "This sink is now unusable." << std::endl;
                }
                std::cout << "-----------" << std::endl;
                break;
            case 3:
                std::cout << "-------------" << std::endl;
                std::cout << "Broken Shower" << std::endl;
                std::cout << "-------------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[2]) {
                    visitedLocation[2] = true;
                    std::cout << "The bathtub had been smashed. The shower curtains were torn off from the hanger. There was nothing left here except for small spots of blood." << std::endl;
                } else {
                    std::cout << "Was someone hiding here?" << std::endl;
                }
                std::cout << "-------------" << std::endl;
                break;
            default:
                break;
        }
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1,4);
    }
}

std::vector<std::string> MasterBathroom::getItems() {
    return items;
}

void MasterBathroom::clearItems() {
    items.clear();
}

void MasterBathroom::setName(std::string user) {
    name = user;
}