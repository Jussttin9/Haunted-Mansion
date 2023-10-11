#include "MasterBedroom.h"
#include "ValidateUserInput.h"

#include <iostream>
#include <vector>
#include <string>

MasterBedroom::MasterBedroom() {
    visited = false;
    unlocked = false;
    name = "";
    for(int i = 0; i < 2; i++) {
        visitedLocation[i] = false;
    }
}

void MasterBedroom::printInitialDialogue() {
    if(!visited) {
        visited = true;
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "Even though I had unlocked the door, I still had to force the door open. When I did, however, I heard a sudden screech, followed by loud thumping coming from the right. I glanced over at the right and saw a long, black tail slither through between the broken cracks between the walls. I couldn't step forward. It was like my feet were glued to the ground, forcing me to stick into place. It felt like it took a great amount of lift just one foot off the ground. I persisted though, and started looking around the room." << std::endl;
    }
}

void MasterBedroom::printInteractables() {
    std::cout << "----------------------" << std::endl;
    std::cout << "1. Blood-stained Floor" << std::endl;
    std::cout << "2. Dead Body" << std::endl;
    std::cout << "3. Master Bathroom" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "----------------------" << std::endl;
}

void MasterBedroom::getInput() {
    int input = checkInput.getValidInput(1,4);
    while(input != 4) {
        switch(input) {
            case 1:
                std::cout << "-------------------" << std::endl;
                std::cout << "Blood-stained Floor" << std::endl;
                std::cout << "-------------------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "At this point, seeing the huge blood-stained floor was nothing new to me, but there was no way that I could've gotten used to the sight of it. It didn't seem recent as it hadn't left any stains of my shoes as I walked around and over it." << std::endl;
                } else {
                    std::cout << "Whoever's blood this was, they must've died a terrible death for them to splurt out this much blood." << std::endl;
                }
                std::cout << "-------------------" << std::endl;
                break;
            case 2:
                std::cout << "---------" << std::endl;
                std::cout << "Dead Body" << std::endl;
                std::cout << "---------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    std::cout << "As the light continued to flicker, briefly illuminating the room, I could visualize something beside the bed. It was sitting at the corner, motionless, I couldn't really tell. But as I walked closer, I saw a body. Their eyes were gouged out from their skull, their jaw was broken in half, to the point where it was just barely hanging on from their face. All four limbs had been missing and their stomach looked like it had been eaten by something. There were no signs of any fresh blood so there's no way that this person could've been killed recently. It must've been here for a while. The shape and size of the body made me believe that this was an adult's body, not a child. It was a little relieving to know that my cousin could still be out there, but who is this person exactly? There's no way this is any of my grandparents." << std::endl;
                } else {
                    std::cout << "I wonder who that body could be?" << std::endl;
                }
                std::cout << "---------" << std::endl;
                break;
            case 3:
                std::cout << "---------------" << std::endl;
                std::cout << "Master Bathroom" << std::endl;
                std::cout << "---------------" << std::endl;
                masterBath.printInitialDialogue();
                std::cout << std::endl;
                masterBath.printInteractables();
                masterBath.getInput();

                addItems(masterBath.getItems());
                masterBath.clearItems();
                break;
            default:
                break;
        }
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1,4);
    }
}

void MasterBedroom::addItems(std::vector<std::string> items) {
    for(std::string item : items) itemsBed.push_back(item);
}

std::vector<std::string> MasterBedroom::getItems() {
    return itemsBed;
}

void MasterBedroom::clearItems() {
    itemsBed.clear();
}

bool MasterBedroom::getUnlockedStatus() {
    return unlocked;
}

void MasterBedroom::setUnlockedStatus(bool status) {
    unlocked = status;
}

void MasterBedroom::setName(std::string user) {
    name = user;
    masterBath.setName(name);
}