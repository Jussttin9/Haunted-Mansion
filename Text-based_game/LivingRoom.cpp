#include "LivingRoom.h"
#include "ValidateUserInput.h"
#include "RippedPages.h"

#include <iostream>

LivingRoom::LivingRoom() {
    visited = false;
    name = "";
    openedFireplace = false;
    for(int i = 0; i < 4; i++) {
        visitedLocation[i] = false;
    }
}

void LivingRoom::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "I stepped into the living room and I could tell that the atmosphere had changed drastically compared to the times where I would come visit. It used to be full of joy and happy memories, I could just remember sitting on the couch by the fireplace, enjoying a nice cup of hot chocolate on a winter day, chatting and catching up with my grandparents. But now, this area just seems so gloomy, so depressing. I barely even recognized it. What even happened to this place? Is this really my grandparents' house? I should take a look around." << std::endl;
        visited = true;
    }
}

void LivingRoom::printInteractables() {
    std::cout << "---------------------" << std::endl;
    std::cout << "1. Missing Piano Spot" << std::endl;
    std::cout << "2. Coffee Table" << std::endl;
    std::cout << "3. Couch" << std::endl;
    std::cout << "4. Fireplace" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "---------------------" << std::endl;
}

void LivingRoom::getInput() {
    int input = -1;
    RippedPages page;

    while(input != 5 && !openedFireplace) {
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1, 5);
        switch (input)
        {
            case 1:
                std::cout << "------------------" << std::endl;
                std::cout << "Missing Piano Spot" << std::endl;
                std::cout << "------------------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "This is where the piano used to be. You could see the scratches on the old hardwood floor, probably from the piano legs being moved around too much. It still seemed so bizarre that the piano had moved from the living room all the way to the second floor stairs. Why would someone do that? Mainly, how did anyone do that? The only thing that was left in the spot was a ripped page. I picked it up and read it." << std::endl;
                    page.printRippedPageContents(3, 16);
                    items.push_back("Ripped Page 16");
                } else {
                    std::cout << "There is nothing left besides the scratched hardwood floor." << std::endl;
                }
                std::cout << "------------------" << std::endl;
                break;
            case 2:
                std::cout << "------------" << std::endl;
                std::cout << "Coffee Table" << std::endl;
                std::cout << "------------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    std::cout << "There wasn’t much to see here. It was a small coffee table that sat between the couch and the fireplace. There were still cups that were previously filled with coffee. Now, they’re just filled with some unknown residue. I don’t even want to think about what that could be." << std::endl;
                } else {
                    std::cout << "It was just a regular, old coffee table." << std::endl;                    
                }
                std::cout << "------------" << std::endl;
                break;
            case 3:
                std::cout << "-----" << std::endl;
                std::cout << "Couch" << std::endl;
                std::cout << "-----" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[2]) {
                    visitedLocation[2] = true;
                    std::cout << "The couch cushions were filled with rips. You could see most of the foam core pop out from the cushions and armrests. It looked very crusty, I didn’t even think to sit on it. It was mostly wrecked so I doubt there was anything I could find." << std::endl;
                } else {
                    std::cout << "Do I really want to rummage through the couch?" << std::endl;
                }
                std::cout << "-----" << std::endl;
                break;
            case 4:
                std::cout << "---------" << std::endl;
                std::cout << "Fireplace" << std::endl;
                std::cout << "---------" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[3]) {
                    visitedLocation[3] = true;
                    std::cout << "The logs of the fireplace looked charred, as if they had been burning for quite a long time now. I looked for some sort of switch to see if the fire would still light. Luckily, there was a switch right next to the fireplace. I flicked it and suddenly a flame had been born within the charred logs. Seems like the gas is still on for some reason. As I warmed up, I looked around the fireplace and found something quite peculiar. It was a keypad on the side frame of the fireplace. It looks like it takes a 4-digit code. I wondered where it could’ve led to." << std::endl;
                } else {
                    std::cout << "I turned to the keypad and stared at the numbers." << std::endl;
                    if(!openedFireplace && !checkInput.getCorrectCode(4852, 4)) {
                        std::cout << name << ": ";
                        std::cout << "The code didn't work. Let me try another one." << std::endl;
                    } else {
                        std::cout << name << ": ";
                        std::cout << "I entered the code and suddenly the fireplace opened up, revealing an old, wooden ladder. I looked up and it seemed to lead to the second floor. It looked very tight and I was very hesitant to even step foot into the small passageway but I did nonetheless." << std::endl;
                        openedFireplace = true;
                    }
                }
                std::cout << "---------" << std::endl;
                break;
            default:
                break;
        }
    }
}

bool LivingRoom::fireplaceStatus() {
    return openedFireplace;
}

std::vector<std::string> LivingRoom::getItems() {
    return items;
}

void LivingRoom::clearItems() {
    items.clear();
}

void LivingRoom::setName(std::string user) {
    name = user;
}