#include "SecondGuestBathroom.h"
#include "ValidateUserInput.h"

#include <iostream>
#include <vector>
#include <string>

SecondGuestBathroom::SecondGuestBathroom() {
    visited = false;
    name = "";
    for(int i = 0; i < 4; i++) {
        visitedLocation[i] = false;
    }
}

void SecondGuestBathroom::printInitialDialogue() {
    if(!visited) {
        std::cout << std::endl;
        std::cout << name << ": ";
        std::cout << "I looked inside the guest bathroom and was immediately bombarded with the images of numerous monster drawings along the walls. These depictions seemed more explicit than the ones I saw before. Its mouth was filled with sharp teeth that looked like it could crush a human skull to piece. Its body had many tentacle-like limbs that could probably suck the life out of any living thing. The one by the shower curtain was the most peculiar. It illustrated a man getting pulled into the monster's stomach; the blood splurting out from both his mouth and his body. Just looking at these images brings a shiver down my spine." << std::endl;
        visited = true;
    }
}

void SecondGuestBathroom::printInteractables() {
    std::cout << "---------" << std::endl;
    std::cout << "1. Sink" << std::endl;
    std::cout << "2. Mirror" << std::endl;
    std::cout << "3. Shower" << std::endl;
    std::cout << "4. Toilet" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "---------" << std::endl;
}

void SecondGuestBathroom::getInput() {
    int input = checkInput.getValidInput(1,5);
    while(input != 5) {
        switch(input) {
            case 1:
                std::cout << "----" << std::endl;
                std::cout << "Sink" << std::endl;
                std::cout << "----" << std::endl;
                std::cout << name << ": ";
                if(!visitedLocation[0]) {
                    visitedLocation[0] = true;
                    std::cout << "The sink was surprisingly cleaner than the one downstairs. The bar soap looked like it had been used extensively, to the point where a baby could hold it. It was still a little wet." << std::endl;
                } else {
                    std::cout << "Nothing notable in the sink." << std::endl;
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
                    std::cout << "I stared through the mirror. I could actually see myself, unlike the other bathroom. I stared at my reflection for a bit, losing myself in my own thoughts. I was afraid for my family. I didn't know where they were. I didn't know how to help. I felt useless. I couldn't move for a while. I suddenly shook my head, snapping out from the crushing feeling that was my thoughts." << std::endl;
                } else {
                    std::cout << "I don't think I wanna look there again." << std::endl;
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
                    std::cout << "I quickly opened the shower curtains. I immediately saw some bolt cutters on the shower floor. This was an odd place for some bolt cutters. There was some black goo at the tip. When I picked it up, the black goo started to drip onto the floor. It seemed to have a high viscosity, similar to honey or maple syrup. I was afraid to touch it. I just avoided it all together." << std::endl;
                    items.push_back("Bolt Cutters");
                } else {
                    std::cout << "There was nothing left besides the black residue that came from the bolt cutters." << std::endl;
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
                    std::cout << "I lifted up the toilet seat slowly, hoping that this wasn't going to be like the one downstairs. To my surprise, it was pretty clean. Actaully, the toilet bowl was surprisingly clean. I could use this toilet right now with no problem. Other than noticing the cleanliness of the toilet, there was nothing else of note." << std::endl;
                } else {
                    std::cout << "I would've loved to use the bathroom now but it was not the time." << std::endl;
                }
                std::cout << "------" << std::endl;
                break;
            default:
                break;
        }
        printInteractables();
        std::cout << "Where should I look? ";
        input = checkInput.getValidInput(1,5);
    }
}

std::vector<std::string> SecondGuestBathroom::getItems() {
    return items;
}

void SecondGuestBathroom::clearItems() {
    items.clear();
}

void SecondGuestBathroom::setName(std::string user) {
    name = user;
}