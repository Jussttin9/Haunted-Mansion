#include "OutsideHouse.h"
#include "User.h"
#include <iostream>
#include <string>

OutsideHouse::OutsideHouse() {
    std::cout << "It was almost 11:00 pm and I was eager to finally arrive. It had been a 3 hour drive after all. But as I was driving down the final roads, I was shocked to see that my grandparents’ house was now abandoned. They hadn’t told me anything about them moving out, nor did my parents. I could see the mold building up on the front porch. The windows had been partially boarded up and had large vines leaking out from inside of the house. I looked up at the second floor and I could see a faint flickering light from the master bedroom window. I walked up to the boarded up door. The planks of wood seemed fairly new compared to the rest of the house. Nonetheless, I tried to open the door anyway. But as I expected, it was locked. Why would anyone need to lock this abandoned house, let alone board the door up? What’s up with the extra defense? I looked around for any tools that I could use to help me get in." << std::endl;
}

void OutsideHouse::printLocations() {
    std::cout << "--------------" << std::endl;
    std::cout << "1. Front Porch" << std::endl;
    std::cout << "2. Car" << std::endl;
    std::cout << "3. Front Door" << std::endl;
    std::cout << "--------------" << std::endl;
}

void OutsideHouse::getInput() {
    printLocations();
    int input = checkInput.getValidInput(1,3);
    while(input != 3 || !player->checkInventory("Crowbar") || !player->checkInventory("Flashlight") || !player->checkInventory("Keys")) {
        switch(input) {
            case 1:
                std::cout << player->getName() << ": ";
                if(!player->checkInventory("Crowbar")) {
                    player->addToInventory("Crowbar", false);
                    std::cout << "I decided to look around the front porch for some loose tools that may be lying around. Most of the wooden chairs and tables were all filled with holes and mold. Luckily, on one of the chairs, there lies a worn crowbar. I placed it in my backpack for future use. Maybe I could use this to remove those boards that are blocking the front door." << std::endl;
                } else {
                    std::cout << "I decided to look around the front porch for some loose tools that may be lying around. Most of the wooden chairs and tables were all filled with holes and mold." << std::endl;
                }
                break;
            case 2:
                printCarLocations();
                std::cout << "Where should I search? " << std::endl;
                input = checkInput.getValidInput(1,3);
                while(input != 3) {
                    if(input == 1) {
                        std::cout << player->getName() << ": ";
                        if(!player->checkInventory("Keys")) {
                            player->addToInventory("Keys", false);
                            std::cout << "I sat back down in the driver's seat to take a quick look around for anything that I could deem useful. I stuck my hand in the front cupholder to feel some keys. I had my grandparents' spare keys. How could I have forgotten? Well, now I can unlock the front door now." << std::endl;
                        } else {
                            std::cout << "I sat back down in the driver's seat to take a quick look around for anything that I could deem useful." << std::endl;
                        }
                    } else if(input == 2) {
                        std::cout << player->getName() << ": ";
                        if(!player->checkInventory("Flashlight")) {
                            player->addToInventory("Flashlight", false);
                            std::cout << "I took a look in the trunk to see if I had any emergency tools that I could use. I looked in the back of the trunk to see a fairly big flashlight. That could prove useful as it is pretty late at night. I need to be able to see what's in front of me right?" << std::endl;
                        } else {
                            std::cout << "I took a look in the trunk to see if I had any emergency tools that I could use." << std::endl;
                        }
                    }   
                    printCarLocations();
                    std::cout << "Where should I search? " << std::endl;
                    input = checkInput.getValidInput(1,3); 
                }
                break;
            default:
                break;
        }
        printLocations();
        std::cout << "Where should I look? " << std::endl;
        input = checkInput.getValidInput(1,3);
    }
}

void OutsideHouse::setUser(User &username) {
    player = &username;
}

void OutsideHouse::printCarLocations() {
    std::cout << "-------------" << std::endl;
    std::cout << "1. Front Seat" << std::endl;
    std::cout << "2. Trunk" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "-------------" << std::endl;
}