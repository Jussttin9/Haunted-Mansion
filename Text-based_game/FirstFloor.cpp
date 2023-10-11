#include "FirstFloor.h"
#include <iostream>
#include <string>

FirstFloor::FirstFloor() {
    std::cout << "As I walked into the front door, the scent of rotten food and mold was sent straight into my nostrils, almost physically pushing me out of the house entirely. I turned on my flashlight and decided to head upstairs to investigate that flickering light. As I approached the stairs, I noticed that there was a huge pile of random furniture and other appliances. I could see my grandparents’ old cabinet and their piano that they kept in the living room. What was the piano doing blocking the second floor stairs? It’s like someone intentionally moved it here. There was no way I was going to move that, let alone all of the other things piled up, so I had to find another way to get up there." << std::endl;
}

void FirstFloor::printLocations() {
    std::cout << "-----------------" << std::endl;
    std::cout << "0. Inventory" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Guest Bedroom" << std::endl;
    std::cout << "2. Guest Bathroom" << std::endl;
    std::cout << "3. Living Room" << std::endl;
    std::cout << "4. Kitchen" << std::endl;
    std::cout << "5. Dining Room" << std::endl;
    std::cout << "6. Basement Door" << std::endl;
    std::cout << "-----------------" << std::endl;
}

void FirstFloor::getLocation(int input) {
    switch(input) {
        case 0:
            player->printInventory();
            break;
        case 1: 
            std::cout << "-------------" << std::endl;
            std::cout << "Guest Bedroom" << std::endl;
            std::cout << "-------------" << std::endl;
            guestBed.printInitialDialogue();
            std::cout << std::endl;
            guestBed.printInteractables();
            guestBed.getInput();

            addItems(guestBed.getItems());
            guestBed.clearItems();
            break;
        case 2:
            std::cout << "--------------" << std::endl;
            std::cout << "Guest Bathroom" << std::endl;
            std::cout << "--------------" << std::endl;
            guestBath.printInitialDialogue();
            std::cout << std::endl;
            guestBath.printInteractables();
            guestBath.getInput();

            addItems(guestBath.getItems());
            guestBath.clearItems();
            break;
        case 3:
            std::cout << "-----------" << std::endl;
            std::cout << "Living Room" << std::endl;
            std::cout << "-----------" << std::endl;
            livingRoom.printInitialDialogue();
            std::cout << std::endl;
            livingRoom.getInput();

            addItems(livingRoom.getItems());
            livingRoom.clearItems();
            break;
        case 4:
            std::cout << "-------" << std::endl;
            std::cout << "Kitchen" << std::endl;
            std::cout << "-------" << std::endl;
            kitchen.printInitialDialogue();
            std::cout << std::endl;
            kitchen.printInteractables();
            kitchen.getInput();

            addItems(kitchen.getItems());
            kitchen.clearItems();
            break;
        case 5:
            std::cout << "-----------" << std::endl;
            std::cout << "Dining Room" << std::endl;
            std::cout << "-----------" << std::endl;
            diningRoom.printInitialDialogue();
            std::cout << std::endl;
            diningRoom.printInteractables();
            diningRoom.getInput();

            addItems(diningRoom.getItems());
            diningRoom.clearItems();
            break;
        default:    // user chose to go to the basement
            std::cout << "--------" << std::endl;
            std::cout << "Basement" << std::endl;
            std::cout << "--------" << std::endl;
            std::cout << player->getName() << ": It's locked." << std::endl;
            std::cout << "--------" << std::endl;
            break;
    }
}

bool FirstFloor::getFireplaceStatus() {
    return livingRoom.fireplaceStatus();
}

void FirstFloor::setUser(User& username) {
    player = &username;
    std::string name = player->getName();
    guestBed.setName(name);
    guestBath.setName(name);
    livingRoom.setName(name);
    kitchen.setName(name);
    diningRoom.setName(name);
}

void FirstFloor::addItems(std::vector<std::string> items) {
    for(std::string item : items) player->addToInventory(item, false);
}

bool FirstFloor::getStoveStatus() {
    return kitchen.getStoveStatus();
}