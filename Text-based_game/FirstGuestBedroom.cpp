#include "FirstGuestBedroom.h"
#include "ValidateUserInput.h"
#include "RippedPages.h"

#include <iostream>
#include <string>

FirstGuestBedroom::FirstGuestBedroom() {
    visited = false;
    name = "";
    openedSafe = false;
    for(int i = 0; i < 4; i++) {
        visitedLocation[i] = false;
    }
}

void FirstGuestBedroom::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "I carefully opened the bedroom door. The loud creaking sound echoed around the entire floor. I peeked my head in and scanned the room. The bed looked dull and worn as if someone had been using it quite often. The drawers were so full of dust that it changed it's polished brown color into an ominous gray. I relunctantly tip-toed into the room as the wooden floors alerted every living being in the house. I decided to take a quick look around the room." << std::endl;
        visited = true;
    }
}

void FirstGuestBedroom::printInteractables() {
    std::cout << "-------------" << std::endl;
    std::cout << "1. Bed" << std::endl;
    std::cout << "2. Drawer" << std::endl;
    std::cout << "3. Closet" << std::endl;
    std::cout << "4. Nightstand" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "-------------" << std::endl;
}

void FirstGuestBedroom::getInput() {
    std::cout << "Where should I go? ";
    int input = checkInput.getValidInput(1, 5);
    RippedPages page;

    while(input != 5) {
        switch (input)
        {
            case 1:
                std::cout << "---" << std::endl;
                std::cout << "Bed" << std::endl;
                std::cout << "---" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "I took a look around the bed, the dust was so abundant that it looked like another blanket. I was pretty exhausted from the drive here but even I wouldn’t want to lie on this bed. ";
                }
                std::cout << "I couldn’t really see anything of use on the bed. Maybe I should try looking somewhere else." << std::endl;     
                std::cout << "---" << std::endl;
                break;
            case 2:
                std::cout << "------" << std::endl;
                std::cout << "Drawer" << std::endl;
                std::cout << "------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    std::cout << "I looked inside the drawers. There were piles of clothes folded neatly in each drawer. I looks like it hasn't been touched in a while. Some of the articles of clothing reminded me of my uncle's clothes. He used to come over a lot because of my cousin. He always loved to visit our grandparents. He loved hunting animals and practicing his aim with a crossbow that my grandpa let him use." << std::endl;
                    std::cout << "I continued to look through the drawers and I ended up finding a ripped page. It looked like it came from someone's diary or journal of some sort. I started reading it." << std::endl;
                    page.printRippedPageContents(1, 26);
                    items.push_back("Ripped Page 26");
                } else {
                    std::cout << "It's just clothes in there now." << std::endl;
                }  
                std::cout << "------" << std::endl;
                break;
            case 3:
                std::cout << "------" << std::endl;
                std::cout << "Closet" << std::endl;
                std::cout << "------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[2]) {
                    visitedLocation[2] = true;
                    std::cout << "I opened the closet and saw some suits and jackets hung up on a bar. The suits had felt very silky, smooth, almost as if they have never been worn for a very long time. Underneath all of the hung up clothes was a decently sized metal safe. Unlike everything else in this room, this safe seemed allergic to dust as it seemed almost brand new, like it was just placed here not too long ago. I bent down and looked at the front of the safe. It seemed like it took a 5-digit code. I wondered if there was a code anywhere in this house." << std::endl;
                } else if(!openedSafe) {
                    std::cout << "I bent down at the safe and tried entering a code." << std::endl;
                    if(!checkInput.getCorrectCode(96870, 5)) {
                        std::cout << name << ": ";
                        std::cout << "I tried pulling on the safe to no avail. I tried looking around for the correct code." <<  std::endl;
                    } else {
                        std::cout << name << ": ";
                        openedSafe = true;
                        items.push_back("Hammer");
                        std::cout << "The code worked! I slowly opened the safe to reveal a single hammer, placed in the center. I took and stored the hammer into my backpack just in case. I expected something a little more valueable to be kept in the safe, something like cash or weapons. Who would need to store a hammer in a strong, metal safe?" << std::endl;
                    }
                } else {
                    std::cout << "There was nothing left to see here, other than the empty safe." << std::endl;
                }
                std::cout << "------" << std::endl;
                break;
            case 4:   
                std::cout << "----------" << std::endl;
                std::cout << "Nightstand" << std::endl;
                std::cout << "----------" << std::endl;   
                std::cout << name << ": ";          
                if(!visitedLocation[3]) {
                    visitedLocation[3] = true;
                    std::cout << "There wasn't much to see on the nightstand. It looked really old, something similar to an antique. There was a small lamp on one nightstand and a book on the other. There was nothing noticeable at first glance but there was something that caught my attention. There was a small red digit, '5'. That's weird. Why would someone draw something like this on their nightstand?" << std::endl;
                } else {
                    std::cout << "The red '5' was still on the nightstand. That's the only thing noticeable so far." << std::endl;
                } 
                std::cout << "----------" << std::endl; 
                break;
            default:
                break;
        }
        std::cout << std::endl;
        printInteractables();
        std::cout << "Where should I go? ";
        input = checkInput.getValidInput(1, 5);
    }
}

std::vector<std::string> FirstGuestBedroom::getItems() {
    return items;
}

void FirstGuestBedroom::clearItems() {
    items.clear();
}

void FirstGuestBedroom::setName(std::string user) {
    name = user;
}