#include "CousinBedroom.h"

#include <iostream>
#include <vector>
#include <string>

CousinBedroom::CousinBedroom() {
    visited = false;
    name = "";
    for(int i = 0; i < 3; i++) {
        visitedLocation[i] = false;
    }
}

void CousinBedroom::printInitialDialogue() {
    if(!visited) {
        visited = true;
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "In addition to the blood on the walls I also noticed several drawings of a weird black monster. It kind of looked like one of those stick bugs but black and 10 times bigger. The legs were replaced with giant, spider-like claws that seemed to be exagerrated in the drawings. It gave an unsettling aura to the room. I started to sweat and shake. Is that thing in this house right now? Where would it be hiding though? I better hurry and search the place before it gets me." << std::endl;
    }
}

void CousinBedroom::printInteractables() {
    std::cout << "---------------" << std::endl;
    std::cout << "1. Bed" << std::endl;
    std::cout << "2. Nightstand" << std::endl;
    std::cout << "3. Play Corner" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "---------------" << std::endl;
}

void CousinBedroom::getInput() {
    int input = checkInput.getValidInput(1,4);
    while(input != 4) {
        switch(input) {
            case 1:
                std::cout << "---" << std::endl;
                std::cout << "Bed" << std::endl;
                std::cout << "---" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "The design of my cousin's Power Rangers bedsheet had been entirely covered with blood. At this point, it just looks like a solid, red bedsheet. Why is there so much blood? This can't be from just one person." << std::endl;
                } else {
                    std::cout << "There's nothing to see here." << std::endl;
                }
                std::cout << "---" << std::endl;
                break;
            case 2:
                std::cout << "----------" << std::endl;
                std::cout << "Nightstand" << std::endl;
                std::cout << "----------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    std::cout << "I opened the drawers on his small nightstand. In one, I could see his colored pencils and markers. The other, I found his artbook. I scanned through it to discover that it was filled with a whole bunch of his own Power Ranger desgins. It wasn't very surprising. He used to really love them." << std::endl;
                } else {
                    std::cout << "Nothing new or out of the ordinary here." << std::endl;
                }
                std::cout << "----------" << std::endl;
                break;
            case 3:
                std::cout << "-----------" << std::endl;
                std::cout << "Play Corner" << std::endl;
                std::cout << "-----------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[2]) {
                    visitedLocation[2] = true;
                    std::cout << "In the corner of his room, there was a whole bunch of random toys stored in clear containers and some were scattered around the floor. In the center of his play corner, I noticed there was a blood-stained rug with a small lighter in the middle. What was a lighter doing here? I picked it up just in case I might need it in the future." << std::endl;
                    items.push_back("Lighter");
                } else {
                    std::cout << "I don't think I need to take any of those toys with me." << std::endl;
                }
                std::cout << "-----------" << std::endl;
                break;
            default:
                break;
        }
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1,4);
    }
}

std::vector<std::string> CousinBedroom::getItems() {
    return items;
}

void CousinBedroom::clearItems() {
    items.clear();
}

void CousinBedroom::setName(std::string user) {
    name = user;
}