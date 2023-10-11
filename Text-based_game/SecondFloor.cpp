#include "SecondFloor.h"
#include "User.h"

#include <iostream>
#include <vector>
#include <string>

SecondFloor::SecondFloor() {
    std::cout << "I steadily climbed up the ladder that was hidden behind the fireplace. The sound of the creaking wood steps increased as I elevated to the top floor of the house. The tight passageway made it very hard to breathe, let alone move my limbs. It felt as if it was sucking the air right out of my lungs. I was never a claustrophobic person, but this passageway did not seem reasonable for any human being to climb through. As I begrudgingly climbed past all the cobwebs and slimy residue that was residing along the walls, I finally reached the top. I looked around but could not see anything. All I could sense was some kind of metallic scent that filled the room. I turned on my flashlight to reveal multiple patches of recently dried blood along the floors and walls. I was terrified. What could have happened? Did something happen to my grandparents? I decided to closely analyze the room only to discover additional spots of blood on the ceiling paired with giant claw marks. What kind of monster would do this? After getting my bearings straight, I took a glance around the room. I was in my little cousin’s room. My grandparents routinely babysat him as his parents were consistently busy with their jobs. Suddenly, my heart began to throb just thinking of what could possibly have happened to him? I mean, he’s just a child." << std::endl;
}

void SecondFloor::setUser(User& username) {
    player = &username;
    std::string name = player->getName();
    bed.setName(name);
    guestBed.setName(name);
    guestBath.setName(name);
    masterBed.setName(name);
}

void SecondFloor::printLocations() {
    std::cout << "------------------------------" << std::endl;
    std::cout << "0. Inventory" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Cousin's Bedroom" << std::endl;
    std::cout << "2. Second Floor Guest Bedroom" << std::endl;
    std::cout << "3. Second Floor Guest Bathroom" << std::endl;
    std::cout << "4. Master Bedroom" << std::endl;
    std::cout << "------------------------------" << std::endl;
}

void SecondFloor::getLocation(int input) {
    if(!masterBed.getUnlockedStatus() && player->checkInventory("Bolt Cutters") && player->checkInventory("Lockpick")) masterBed.setUnlockedStatus(true);
    switch(input) {
        case 0:
            player->printInventory();
            break;
        case 1:
            std::cout << "----------------" << std::endl;
            std::cout << "Cousin's Bedroom" << std::endl;
            std::cout << "----------------" << std::endl;
            bed.printInitialDialogue();
            std::cout << std::endl;
            bed.printInteractables();
            bed.getInput();

            addItems(bed.getItems());
            bed.clearItems();
            break;
        case 2:
            std::cout << "--------------------------" << std::endl;
            std::cout << "Second Floor Guest Bedroom" << std::endl;
            std::cout << "--------------------------" << std::endl;
            guestBed.printInitialDialogue();
            std::cout << std::endl;
            guestBed.printInteractables();
            guestBed.getInput();

            addItems(guestBed.getItems());
            guestBed.clearItems();
            break;
        case 3:
            std::cout << "---------------------------" << std::endl;
            std::cout << "Second Floor Guest Bathroom" << std::endl;
            std::cout << "---------------------------" << std::endl;
            guestBath.printInitialDialogue();
            std::cout << std::endl;
            guestBath.printInteractables();
            guestBath.getInput();

            addItems(guestBath.getItems());
            guestBath.clearItems();
            break;
        case 4:
            std::cout << "--------------" << std::endl;
            std::cout << "Master Bedroom" << std::endl;
            std::cout << "--------------" << std::endl;
            if(masterBed.getUnlockedStatus()) {
                masterBed.printInitialDialogue();
                std::cout << std::endl;
                masterBed.printInteractables();
                masterBed.getInput();

                addItems(masterBed.getItems());
                masterBed.clearItems();
            } else {
                std::cout << "The bedroom door was blocked by a whole bunch of chains. The door also seemed to be locked from the inside. Maybe I could've found some items around here." << std::endl;
            }
            break;
        default:
            break;
    }
}

void SecondFloor::addItems(std::vector<std::string> items) {
    for(std::string item : items) player->addToInventory(item, false);
}