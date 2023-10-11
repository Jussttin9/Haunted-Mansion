#include "FirstGuestBathroom.h"
#include "ValidateUserInput.h"
#include "RippedPages.h"

#include <iostream>
#include <string>

FirstGuestBathroom::FirstGuestBathroom() {
    visited = false;
    name = "";
    for(int i = 0; i < 4; i++) {
        visitedLocation[i] = false;
    }
}

void FirstGuestBathroom::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "I walked inside the guest bathroom and immediately ran back out. There were numerous piles of poop on the floor and inside of the toilet. It was a horrendous smell that I couldn't just ignore. But nonetheless, I had to persist, so I held my breath as long as I could and hesitantly walked through the door to investigate." << std::endl;
        visited = true;
    }
}

void FirstGuestBathroom::printInteractables() {
    std::cout << "---------" << std::endl;
    std::cout << "1. Sink" << std::endl;
    std::cout << "2. Mirror" << std::endl;
    std::cout << "3. Shower" << std::endl;
    std::cout << "4. Toilet" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "---------" << std::endl;
}

void FirstGuestBathroom::getInput() {
    std::cout << "Where should I look? ";
    int input = checkInput.getValidInput(1, 5);
    RippedPages page;

    while(input != 5) {
        switch (input)
        {
            case 1:
                std::cout << "----" << std::endl;
                std::cout << "Sink" << std::endl;
                std::cout << "----" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "I looked down at the sink and tried to turn on the faucet. The sound of the tap water flowing out of the faucet was like music to my ears. It already felt like I’ve been in this house for an eternity. But why would the water still be on, for being an abandoned house, wouldn’t people have shut off the water by now? Taking a closer look at the sink, I noticed a little kid’s drawing of some squares. There were four squares, a blue one, a green one, then a red one, and finally a yellow one. That’s an odd place to draw." << std::endl;
                } else {
                    std::cout << "The drawing was still drawn inside the sink: a blue square, a green square, a red square, and a yellow square." << std::endl;
                }
                std::cout << "----" << std::endl;
                break;
            case 2:
                std::cout << "------" << std::endl;
                std::cout << "Mirror" << std::endl;
                std::cout << "------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    std::cout << "The mirror was filled with a lot of residue and cracks. I could barely see my own reflection. I tried to open it to see if there was a medicine cabinet behind it but with no luck. I quickly scanned the mirror and along with the residue on the mirror frame, I found a stamped blue digit, ‘4’. Weird. Why was there graffiti in this house if my grandparents were the only ones mainly living in it?" << std::endl;
                } else {
                    std::cout << "The blue '4' remained unnoticed as I scanned the mirror once again." << std::endl;
                }
                std::cout << "------" << std::endl;
                break;
            case 3:
                std::cout << "------" << std::endl;
                std::cout << "Shower" << std::endl;
                std::cout << "------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[2]) {
                    visitedLocation[2] = true;
                    std::cout << "I pulled the shower curtains open. The shower was entirely covered with vines and mold. I wondered how long it’s been since someone cleaned it. I took a look around and found a ripped page stuck in between the vines. I stuck my hand in, grabbed it, and started to read it." << std::endl;
                    page.printRippedPageContents(2, 30);
                    items.push_back("Ripped Page 30");
                } else {
                   std::cout << "There was nothing left to see in the shower." << std::endl; 
                }
                std::cout << "------" << std::endl;
                break;
            case 4:
                std::cout << "------" << std::endl;
                std::cout << "Toilet" << std::endl;
                std::cout << "------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[3]) {
                    visitedLocation[3] = true;
                    std::cout << "I didn’t even want to look inside the toilet. There’s no way there was anything useful there. I could already smell the poop as the stench was basically going through the toilet lid. I quickly lifted the lid just to find out that there was nothing in there besides, who would’ve guessed, poop. I closed the lid as quickly as I had lifted it and decided to move on." << std::endl;
                } else {
                    std::cout << "I don't want to look in there anymore." << std::endl;
                }
                std::cout << "------" << std::endl;
                break;
            default:
                break;
        }
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1, 5);
    }
}

std::vector<std::string> FirstGuestBathroom::getItems() {
    return items;
}

void FirstGuestBathroom::clearItems() {
    items.clear();
}

void FirstGuestBathroom::setName(std::string user) {
    name = user;
}