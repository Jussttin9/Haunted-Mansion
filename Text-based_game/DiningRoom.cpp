#include "DiningRoom.h"
#include "ValidateUserInput.h"
#include "RippedPages.h"

#include <iostream>

DiningRoom::DiningRoom() {
    visited = false;
    name = "";
    for(int i = 0; i < 2; i++) {
        visitedLocation[i] = false;
    }
}

void DiningRoom::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "There wasn't much to see here. I remember the times where I would see all of my extended family members here during Thanksgiving and Christmas breaks. I missed those days. I wish I could've relived those moments. Ahh. I shouldm't get sidetracked. I should probably just check this area just in case." << std::endl;
        visited = true;
    }
}

void DiningRoom::printInteractables() {
    std::cout << "---------------" << std::endl;
    std::cout << "1. Dining Table" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "---------------" << std::endl;
}

void DiningRoom::getInput() {
    std::cout << "Where should I look? ";
    int input = checkInput.getValidInput(1, 2);
    RippedPages page;

    while(input != 2) {
        std::cout << "------------" << std::endl;
        std::cout << "Dining Table" << std::endl;
        std::cout << "------------" << std::endl;
        std::cout << name << ": ";
        if(!visitedLocation[0]) {
            visitedLocation[0] = true;
            std::cout << "There wasn’t much on the dining table. Thankfully there weren’t any dishes or food on the table. I think I’ve seen enough rotten food and dirty dishes for like a lifetime by now. The only thing that was on there was a ripped page sitting at the head of the table. At first glance, I noticed there was a yellow digit at the top right corner of the page, ‘2’. I started to read the page." << std::endl;
            page.printRippedPageContents(5, 1);
            items.push_back("Ripped Page 1");
        } else {
            std::cout << "I still remember the yellow '2' that was on the ripped page that I picked up." << std::endl;
        }
        std::cout << "------------" << std::endl;
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1, 3);
    }
}

std::vector<std::string> DiningRoom::getItems() {
    return items;
}

void DiningRoom::clearItems() {
    items.clear();
}

void DiningRoom::setName(std::string user) {
    name = user;
}