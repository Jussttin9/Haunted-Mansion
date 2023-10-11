#include "Kitchen.h"
#include "ValidateUserInput.h"
#include "RippedPages.h"

#include <iostream>
#include <string>

Kitchen::Kitchen() {
    visited = false;
    name = "";
    stoveStatus = false;
    for(int i = 0; i < 6; i++) {
        visitedLocation[i] = false;
    }
}

void Kitchen::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "I took one step into the kitchen and instantly started to smell of the rotten food that was probably stored here for what it seemed like months. I could see flies everywhere. I was a little hesistant to go in but I just put my hoodie on, pulled and tied the hoodstrings and walked in to investigate." << std::endl;
        visited = true;
    }
}

void Kitchen::printInteractables() {
    std::cout << "---------------" << std::endl;
    std::cout << "1. Stove" << std::endl;
    std::cout << "2. Refrigerator" << std::endl;
    std::cout << "3. Bar" << std::endl;
    std::cout << "4. Freezer" << std::endl;
    std::cout << "5. Drawers" << std::endl;
    std::cout << "6. Sink" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "---------------" << std::endl;
}

void Kitchen::getInput() {
    std::cout << "Where should I look? ";
    int input = checkInput.getValidInput(1, 7);
    RippedPages page;

    while(input != 7) {
        switch (input)
        {
            case 1:
                std::cout << "-----" << std::endl;
                std::cout << "Stove" << std::endl;
                std::cout << "-----" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "The stove looked rusted and burnt. There were small pieces of food particles underneath the stovetop. I glanced at the knobs and noticed that they were all set to ‘OFF’. I turned it on to see if it was still working. There was no fire, but it seemed like gas was still leaking out so I turned it back off." << std::endl;
                    printStoveDecision();
                } else {
                    printStoveDecision();
                }
                std::cout << "-----" << std::endl;
                break;
            case 2:
                std::cout << "------------" << std::endl;
                std::cout << "Refrigerator" << std::endl;
                std::cout << "------------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    std::cout << "I opened the refrigerator and as expected, it was filled with rotten food and various critters chipping at all the food. Some seemed to be lying dead, probably indicating they were probably stuck in there for a while." << std::endl;
                } else {
                    std::cout << "Still filled with rotten food and critters." << std::endl;
                }
                std::cout << "------------" << std::endl;
                break;
            case 3:
                std::cout << "---" << std::endl;
                std::cout << "Bar" << std::endl;
                std::cout << "---" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[2]) {
                    visitedLocation[2] = true;
                    std::cout << "I took a seat on the bar stool and looked around at the bar to see if there was anything. I scanned the dirty marble top and all I noticed were some rotten food and some random crayons scattered around." << std::endl;
                } else {
                    std::cout << "Everything was the same as I had left it." << std::endl;
                }
                std::cout << "---" << std::endl;
                break;
            case 4:
                std::cout << "-------" << std::endl;
                std::cout << "Freezer" << std::endl;
                std::cout << "-------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[3]) {
                    visitedLocation[3] = true;
                    std::cout << "I opened the freezer and saw a bunch of frozen packaged meats. There was something abnormal about them though. They didn’t seem like your typical beef or pork or chicken. This was something else. I couldn’t put my mind on it. I closed it and pondered about what it could be." << std::endl;
                } else {
                    std::cout << "I wondered what that mystery meat was." << std::endl;
                }
                std::cout << "-------" << std::endl;
                break;
            case 5:
                std::cout << "-------" << std::endl;
                std::cout << "Drawers" << std::endl;
                std::cout << "-------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[4]) {
                    visitedLocation[4] = true;
                    std::cout << "I opened up all the drawers and found mostly utensils and cooking tools. Most were dirty, some were broken. In one of the drawers however, I found a ripped page. It was an unusual place to place a ripped page but I picked it up and read it anyway." << std::endl;
                    page.printRippedPageContents(4, 34);
                    items.push_back("Ripped Page 34");
                } else {
                    std::cout << "Nothing out of the ordinary." << std::endl;
                }
                std::cout << "-------" << std::endl;
                break;
            case 6:
                std::cout << "----" << std::endl;
                std::cout << "Sink" << std::endl;
                std::cout << "----" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[5]) {
                    visitedLocation[5] = true;
                    std::cout << "The sink was filled with dirty dishes. There were many roaches that were scavenging for any extra food on the plates. I hated bugs so I didn’t want to go anywhere near there, but I did anyway as my gut was telling me that I should. I tip-toed to get a bird’s eye view of the sink and at the very bottom corner, against the metal grating, I could see a small green digit, ‘8’. Why would anyone even reach their hand in there to write that? Unless they did it before the house turned into a trash dump." << std::endl;
                } else {
                    std::cout << "The green '8' was still barely visible at the bottom of the sink." << std::endl;
                }
                std::cout << "----" << std::endl;
                break;
            default:
                break;
        }
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1, 7);
    }
}

bool Kitchen::getStoveStatus() {
    return stoveStatus;
}

std::vector<std::string> Kitchen::getItems() {
    return items;
}

void Kitchen::clearItems() {
    items.clear();
}

void Kitchen::printStoveDecision() {
    std::string oppStatus;
    if(getStoveStatus()) {
        oppStatus = "off";
    } else {
        oppStatus = "on";
    }

    std::cout << "Should I turn the stove " << oppStatus << "?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    int input = checkInput.getValidInput(1,2);
    if(input == 1) {
        stoveStatus = !stoveStatus;
        std::cout << "I turned the stove " << oppStatus << "." << std::endl;
    }
}

void Kitchen::setName(std::string user) {
    name = user;
}