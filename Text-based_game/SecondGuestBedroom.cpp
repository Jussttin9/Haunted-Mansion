#include "SecondGuestBedroom.h"
#include "ValidateUserInput.h"

#include <iostream>

SecondGuestBedroom::SecondGuestBedroom() {
    visited = false;
    name = "";
    for(int i = 0; i < 4; i++) {
        visitedLocation[i] = false;
    }
}

void SecondGuestBedroom::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "I stepped inside the guest bedroom. My eyes widened. The room was a mess. The pillows and bedsheets ripped and on the floor. The drawer and nightstand were knocked over and looked very degraded. Also, the back of the drawer were filled with scratches that seemed to have been made by a giant claw. The mirror closet door was cracked into a million pieces. It looked like one touch and the entire mirror would shatter and fall to the ground. I have to be careful when looking around." << std::endl;
        visited = true;
    }
}

void SecondGuestBedroom::printInteractables() {
    std::cout << "-------------" << std::endl;
    std::cout << "1. Bed" << std::endl;
    std::cout << "2. Drawer" << std::endl;
    std::cout << "3. Closet" << std::endl;
    std::cout << "4. Nightstand" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "-------------" << std::endl;
}

void SecondGuestBedroom::getInput() {
    int input = checkInput.getValidInput(1,5);
    while(input != 5) {
        switch(input) {
            case 1:
                std::cout << "---" << std::endl;
                std::cout << "Bed" << std::endl;
                std::cout << "---" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    std::cout << "The bed was missing its pillows and bedsheets. All that was left was a dirty, stained white matress. There were giant claw piercings on it, tearing through the matress, exposing the springs underneath." << std::endl;
                    visitedLocation[0] = true;
                } else {
                    std::cout << "What could've done this to the bed?" << std::endl;
                }
                std::cout << "---" << std::endl;
                break;
            case 2:
                std::cout << "------" << std::endl;
                std::cout << "Drawer" << std::endl;
                std::cout << "------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    std::cout << "The drawer was knocked down to the floor. It was too heavy to lift on my own so there was no way of searching it." << std::endl;
                    visitedLocation[1] = true;
                } else {
                    std::cout << "If I was stronger I probably could lift it up." << std::endl;
                }
                std::cout << "------" << std::endl;
                break;
            case 3:
                std::cout << "------" << std::endl;
                std::cout << "Closet" << std::endl;
                std::cout << "------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[2]) {
                    std::cout << "I was almost too afraid of opening the closet due to the shattered glass but I tried anyway. I shifted the sliding door a bit and then the sound of glass breaking and crashing onto the floor blasted my eardrums. The entire mirror had fallen off of the door, making it see-through. Looking through the now shattered door, I saw a bunch of little kid's clothes, mostly filled with cartoon characters and game characters on them. They looked like they've been worn recently." << std::endl;
                    visitedLocation[2] = true;
                } else {
                    std::cout << "Nothing else there besides clothes." << std::endl;
                }
                std::cout << "------" << std::endl;
                break;
            case 4:
                std::cout << "----------" << std::endl;
                std::cout << "Nightstand" << std::endl;
                std::cout << "----------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[3]) {
                    std::cout << "The nightstand seemed to be the only piece of furniture left intact. Whatever was on it, was probably destroyed or somewhere on the floor as there was nothing sitting on top of the nightstand. I checked the compartment and found a paper clip bent in the shape of what seemed to be a lockpick. Why would he need to use a lockpick?" << std::endl;
                    visitedLocation[3] = true;
                    items.push_back("Lockpick");
                } else {
                    std::cout << "There was nothing else in or on the nightstand." << std::endl;
                }
                std::cout << "----------" << std::endl;
                break;
            default:
                break;
        }
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1,5);
    }
}

std::vector<std::string> SecondGuestBedroom::getItems() {
    return items;
}

void SecondGuestBedroom::clearItems() {
    items.clear();
}

void SecondGuestBedroom::setName(std::string user) {
    name = user;
}