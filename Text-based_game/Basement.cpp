#include "Basement.h"
#include "ValidateUserInput.h"

#include <iostream>

Basement::Basement() {
    exitRange = 5;
    foundMonster = false;
    for(int i = 0; i < 5; i++) {
        visitedLocation[i] = false;
    }
    std::cout << "I ran down to the first floor and reluctantly unlocked the basement key, anxious about whether that thing was still down there. Immediately, I was hit with the smell of fresh blood, which is definitely not a good sign. It was incredibly dark down there, my flashlight was not able to illuminate much, which made the room very ominous. I was afraid that it was going to run out of battery, so I had to act quickly if I wanted to get out in one piece. I looked at the ceiling to find some sort of light source. Luckily, I spotted a single lightbulb hanging from the ceiling so I turned it on to illuminate 5 other doors surrounding the basement walls. Weird. I don’t remember the basement having 5 different rooms. After checking all of the doors, only the first room actually opened. Even though there wasn’t a timer, I felt like I had to rush. I suddenly felt a rush of adrenaline surge through my veins. I had to act quickly, what if there are still people alive down here? But then again, I would be risking my own life. Do I really want to do that?" << std::endl;
}

bool Basement::userInvestigates() {
    std::cout << "------------------" << std::endl;
    std::cout << "1. Investigate" << std::endl;
    std::cout << "2. Leave the house" << std::endl;
    std::cout << "------------------" << std::endl;
    int input = checkInput.getValidInput(1,2);
    if(input == 1) {
        return true;
    } else {
        std::cout << std::endl;
        std::cout << player->getName() << ": ";
        std::cout << "There was essentially a pool of blood on the ground. There was no way that anyone would still be alive at this point right? I should get out while I still can. So that was exactly what I did. I ran back up the basement stairs and bursted outside and rushed to my car. I put the keys in the ignition and drove back the way I came. The smell of blood was still stuck in my nose, reminding me of all of the horrors that I had just witnessed. What if there were still people alive down there? Could I have saved them if I just kept pursuing the source of the blood? Who knows. All I knew was that I was safe from whatever was hiding down there. I reluctantly drove back home feeling the wind once again blow against my hair, but this time, it felt a lot colder than usual. Maybe it was just the chilling feeling that started to consume my body at the possibility of it chasing me. All I could really do is just blast my music to try and forget right?" << std::endl;
        return false;
    }
}

void Basement::printLocations() {
    if(visitedLocation[2]) {
        std::cout << "------------" << std::endl;
        std::cout << "0. Inventory" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Room 1" << std::endl;
        std::cout << "2. Room 2" << std::endl;
        std::cout << "3. Room 3" << std::endl;
        std::cout << "4. Room 4" << std::endl;
        std::cout << "5. Room 5" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "------------" << std::endl;
    } else {
        std::cout << "------------" << std::endl;
        std::cout << "0. Inventory" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Room 1" << std::endl;
        std::cout << "2. Room 2" << std::endl;
        std::cout << "3. Room 3" << std::endl;
        std::cout << "4. Room 4" << std::endl;
        std::cout << "5. Room 5" << std::endl;
        std::cout << "------------" << std::endl;
    }
}

void Basement::getLocation(int input) {
    switch(input) {
        case 0:
            player->printInventory();
            break;
        case 1: 
            std::cout << "------" << std::endl;
            std::cout << "Room 1" << std::endl;
            std::cout << "------" << std::endl;
            std::cout << player->getName() << ": ";
            if(!visitedLocation[0]) {
                visitedLocation[0] = true;
                player->addToInventory("Room 5 Key", false);
                std::cout << "I stepped inside of the room. The room was mostly empty except for a body sitting directly in front of the door. There was a gaping hole through their chest. Their insides were spewing out of the hole and onto the floor. The person was holding a key. They looked liked they were gripping onto it pretty hard. I looked closely and there was a label that said 'Room 5 Key'. Looking behind the body, was a small hole in the wall which seemed to indicate that whatever had caused this busted through the wall and killed this person. It was too small to fit myself but even if I could, I don't think I would want to try and crawl through it." << std::endl;
            } else {
                std::cout << "The body was still sitting lifeless against the wall." << std::endl;
            }
            std::cout << "------" << std::endl;
            break;
        case 2:
            std::cout << "------" << std::endl;
            std::cout << "Room 2" << std::endl;
            std::cout << "------" << std::endl;
            std::cout << player->getName() << ": ";
            if(player->checkInventory("Hammer") && player->checkInventory("Room 2 Key")) {
                if(!visitedLocation[1]) {
                    visitedLocation[1] = true;
                    foundMonster = true;    
                    std::cout << "I slowly opened the door and was confronted with the monster. It had mulitple arrows sticking out of it already, it looked furious, like it was going to pounce at me at any second. As I tried to take the crossbow from my cousin, it pounced at me, crushing me against the wall, making a huge dent. It felt like my back was broken into a million pieces. I skiwky crawled back up as the monster turned back to retaliate. I quickly pounced on top of it trying to hold its head still, preventing it from sinking its teeth into my body. I took a quick glance at the door and saw my cousin crouching and crying as he watched me struggling to survive against the monster. I shouted and told him to shoot at it while I still had a firm grasp on its head. He slowly pulled the crossbow up, aimed, and took a few shots and hit the monster directly inside of its mouth and its eyes. A stray arrow had also hit my shoulder, knocking me off of the monster's back and on the floor once again. This time both me and the monster were lying on the floor. I didn't have the energy to look at the monster or my cousin. All the injuries had weakened me dramatically and caused me to go unconscious. I finally had woken up to the sight of my cousin attempting to drag me away from the room. I slowly got back up to my feet and walked out the room with him, leaving the monster on the floor. It laid still on the ground, not moving a muscle. It made me doubt whether we had actually killed him or not. We had no energy nor the strength to do anything. So I just thanked him for saving both of our lives and we slowly exited the room." << std::endl;
                } else {
                    std::cout << "I think we're done here." << std::endl;
                }
            } else {
                std::cout << "The door to the second room was locked and also boarded up for some reason. I would need the key to the room as well as something to break the boards down, probably something like a hammer would do." << std::endl;
            }
            std::cout << "------" << std::endl;
            break;
        case 3:
            std::cout << "------" << std::endl;
            std::cout << "Room 3" << std::endl;
            std::cout << "------" << std::endl;
            std::cout << player->getName() << ": ";
            if(player->checkInventory("Room 3 Key")) {
                if(!visitedLocation[2]) {
                    visitedLocation[2] = true;
                    player->addToInventory("Room 4 Key", false);
                    exitRange = 6;
                    std::cout << "I entered the room and was immediately greeted with the sight of numerous bodies being hung in body bags from the ceiling. Each bag had a couple of claw marks slashing through them as well as arrows for some reason. There was another small hole at the end of the room and there were a few arrows tipped with black goo, presumably from the monster, lying at the entrance. There was also a locker in one of the corners of the room. I pressed my ear onto the locker and I could hear breathing and shaking. I spoke aloud to figure out who or what was in there. I heard a faint voice say, 'it's me'. I opened the door to find my little cousin cowering inside holding a crossbow. He must've been the one to shoot at the monster. That also explained why there were random arrows poking from some of the bodies. I tried talking to him asking if he was okay but he stayed silent. Instead, he handed me another key labeled 'Room 4 Key'. I really don't think we should keep exploring, especially with the monster still roaming the basement walls. It would've probably been a good idea to leave to keep my cousin safe. But on the other hand, we have a weapon now, we might be able to kill the monster ourselves." << std::endl;
                } else {
                    std::cout << "The hanging bodies remained. I picked up any leftover arrows sticking out from the bodies and on the floor." << std::endl;
                }
            } else {
                std::cout << "The door to the third room was still locked." << std::endl;
            }
            std::cout << "------" << std::endl;
            break;
        case 4:
            std::cout << "------" << std::endl;
            std::cout << "Room 4" << std::endl;
            std::cout << "------" << std::endl;
            std::cout << player->getName() << ": ";
            if(player->checkInventory("Room 4 Key")) {
                if(!visitedLocation[3]) {
                    visitedLocation[3] = true;
                    player->addToInventory("Room 2 Key", false);
                    std::cout << "There was a table along the left wall of this room as well as another small hole in the wall. There was another key on the table, this time labeled 'Room 2 Key' so I picked it up and continued to search the room. There was black goo everywhere, covering almost the entire wall and floor. It was almost as if the monster had exploded or maybe had been badly injured. There was a couple more arrows near the hole. My cousin probably had a couple good shots on the monster, critically injuring it." << std::endl;
                } else {
                    std::cout << "There was nothing else inside the room besides all of the black goo." << std::endl;
                }
            } else {
                std::cout << "The door to the fourth room was still locked." << std::endl;
            }
            std::cout << "------" << std::endl;
            break;
        case 5:
            std::cout << "------" << std::endl;
            std::cout << "Room 5" << std::endl;
            std::cout << "------" << std::endl;
            std::cout << player->getName() << ": ";
            if(player->checkInventory("Room 5 Key")) {
                if(!visitedLocation[4]) {
                    visitedLocation[4] = true;
                    player->addToInventory("Room 3 Key", false);
                    std::cout << "This room was similar to the first room as it barely had anything in it besides blood and bodies. This time, there was a couple more bodies scattered around the corners of the room. I glanced at the wall directly in front of the door and saw that there was another small hole. Unlike the first room, I had seen something that I wish I could've unseen. I had caught a small glimpse of a long, spindly arm with giant claws--each claw the length of a medium-sized stick. I was afraid to step forward as I was terrified that it might come back to get me next. As I scanned the room, I noticed there was another key that another body had in their hand. I sprinted towards the body to pick up the key and ran back to the doorway. I read the label on the key, which said 'Room 3 Key' and walked out of the room." << std::endl;
                } else {
                    std::cout << "I'm terrified to even go into that room again." << std::endl;
                }
            } else {
                std::cout << "The door to the fifth room was still locked." << std::endl;
            }
            std::cout << "------" << std::endl;
            break;
        default:
            break;
    }
}

void Basement::setUser(User& username) {
    player = &username;
}

int Basement::getExitRange() {
    return exitRange;
}

void Basement::printPage() {
    std::cout << std::endl;
    std::cout << "Insert page contents here" << std::endl;
}

bool Basement::getMonsterStatus() {
    return foundMonster;
}

bool Basement::printLighterDecision() {
    std::cout << std::endl;
    std::cout << player->getName() << ": ";
    std::cout << "As I left the house I realized that I still had my lighter, should I light it?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    int input = checkInput.getValidInput(1,2);
    if(input == 1) return true;
    return false;
}