#include "mainMenu.h"
#include "User.h"
#include "OutsideHouse.h"
#include "FirstFloor.h"
#include "ValidateUserInput.h"
#include "SecondFloor.h"
#include "Basement.h"

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ios>
#include <limits>

// HELPER METHODS
void playIntro(std::string name);

// STARTS MAIN GAME
int main()
{
    std::string input;
    ValidateUserInput checkInput;

    // Start Menu
    mainMenu startMenu;
    std::cout << "Please enter the selected number: ";
    input = startMenu.getInput();

    if(input == "Exit") exit(0);

    // GATHERS USER INFORMATION
    User player;
    player.setName();
    playIntro(player.getName());
    const std::string name = player.getName();

    // BEGINS FIRST SCENE OUTSIDE OF HOUSE
    std::cout << name << ": ";
    OutsideHouse firstScene;
    firstScene.setUser(player);

    firstScene.getInput();

    std::cout << name << ": ";
    std::cout << "I used the crowbar I found to break down the boards as well as my keys to unlock the front door and I walked inside." << std::endl;

    // BEGINS SECOND SCENE ON THE FIRST FLOOR
    std::cout << name << ": ";
    FirstFloor secondScene;
    secondScene.setUser(player);

    while(!secondScene.getFireplaceStatus()) {
        secondScene.printLocations();
        secondScene.getLocation(checkInput.getValidInput(0,6));     // FIX INVENTORY POSITION LATER
    }

    // BEGINS THIRD SCENE ON THE SECOND FLOOR
    std::cout << name << ": ";
    SecondFloor thirdScene;
    thirdScene.setUser(player);
    
    thirdScene.getLocation(1);

    while(!player.checkInventory("Basement Key")) {
        thirdScene.printLocations();
        thirdScene.getLocation(checkInput.getValidInput(0,4));
    }

    // BEGINS LAST SCENE IN THE BASEMENT
    Basement finalScene;
    finalScene.setUser(player);

    // ASKS USER IF THEY WANT TO CONTINUE STORY OR NOT
    if(finalScene.userInvestigates()) {
        // continue story
        finalScene.printLocations();
        std::cout << "Where should I look? " << std::endl;
        int input = checkInput.getValidInput(0, finalScene.getExitRange());
        while(input != 6) {
            finalScene.getLocation(input);
            finalScene.printLocations();
            std::cout << "Where should I look? " << std::endl;
            input = checkInput.getValidInput(0, finalScene.getExitRange());
        }
        
        // User chooses ending
        if(player.checkInventory("Lighter") && finalScene.printLighterDecision()) {
            if(secondScene.getStoveStatus()) {
                // house blows up, including you and cousin
                std::cout << "I lit the lighter. But the second I flicked my finger, I suddenly remembered that I had turned on the stove. Before I could lift your finger back up from the lighter, I saw a whole bunch of fire and explosions around the house. I tried to take your cousin and run out of the house as fast as possible but I wasn't fast enough. We were quickly engulfed by the flames and blown to pieces." << std::endl;
                checkInput.printEndCard(2);
            } else {
                // house is set on fire
                if(finalScene.getMonsterStatus()) {
                    std::cout << "I lit the lighter and the flames quickly illuminated the first floor. I figured that since the house was made of wood, we could get rid of that monster once and for all, just in case it was still alive down there. I placed the lighter near some of the walls and on the floor and it quickly caught fire, eventually spreading throughout the whole house. My cousin and I quickly ran out of the house and turned back to see the house engulfed in flames. The fire was so big that it lit up the trees in a 2 mile radius. We then ran back to the car and drove off to the hospital to recover from our wounds and hopefully look for our grandparents after." << std::endl;
                    checkInput.printEndCard(3);
                } else {
                    std::cout << "I lit the lighter and the flames quickly illuminated the first floor. I figured that since the house was made of wood, we could get rid of whatever monster was lurking in that house. I placed the lighter near some of the walls and on the floor and it quickly caught fire, eventually spreading throughout the whole house. My cousin and I quickly ran out of the house and turned back to see the house engulfed in flames. The fire was so big that it lit up the trees in a 2 mile radius. We then ran back to the car and drove off to the hospital to recover from our wounds. As we drove off, we heard a loud roar in the distance, followed by a quick black and firey figure racing through the trees and into the woods. I quickly slammed onto the gas pedal and zoomed down the highway, and got away as far from the monster as possible. I thought we could've killed it but I guess it had smelled the smoke and quickly escaped from the house. If only we could've found and killed the monster, my mind wouldn't have been filled with all of these guilty afterthoughts. Now the monster was roaming freely in the woods, probably searching for its next victims." << std::endl;
                    checkInput.printEndCard(5);
                } 
            }
        } else {
            // you leave the house intact
            if(finalScene.getMonsterStatus()) {
                std::cout << "I put the lighter back into my pocket, figuring that I didn't have a use for it right now. My cousin and I limped out the door and quietly drove off to somewhere we could rest and recover from our wounds. As I was driving back, I couldn't help but think about whether we actually killed the monster or not. I was afraid it would just recover and start killing more people again. But my cousin had shot it in the mouth and eyes. Hopefully we killed it, but worst case scenario, it figured it was going to be a long while before it starts killing again." << std::endl;
                checkInput.printEndCard(4);
            } else {
                std::cout << "I put the lighter back into my pocket, figuring that I didn't have a use for it right now. My cousin and I limped out the door and quietly drove off to somewhere we could rest and recover from our wounds. As I was driving back, I noticed a black, shadowy figure behind the car. The engine probably had made so much noise that it had attracted the monster. I slammed my foot on the gas pedal and pushed 120 but it wasn't fast enough. The monster quickly caught up as it leaped towards us at what looked to be at light speed. It jumped in front of our car, instantly causing us to crash the car against its rigid body. I closed my eyes for a few seconds during the crash but as I opened them, I noticed the monster standing on top of our car. Then suddenly, it broke through the windshield and started to tear both me and my cousin to pieces until there was nothing left of us. When the monster had fled, the only thing left was a crashed, empty car sitting alone on the highway." << std::endl;
                checkInput.printEndCard(6);
            }
        }

    } else { // else END the game
        checkInput.printEndCard(1);
    }

    // prints ending credits
    std::cout << std::endl;
    std::cout << "Thank you so much for playing!" << std::endl;
    std::cout << "Game by Justin Tran" << std::endl;
    std::cout << std::endl;

}

void playIntro(std::string name) {
    std::stack<std::string> dialogue;
    std::string placeholder;

    dialogue.push(
        "I always loved driving down there because there were barely any other cars on the road. I got to blast my music without a care in the world. I could feel the gusts of wind blast my hair back, showing my unusually large forehead. But it didn’t matter to me. Who was going to see? There was nothing special along the road, just me, my music, and the trees. I felt relaxed. Except today was a little weirder than others."
    );
    dialogue.push(
        "I was on my way to visit my grandparents for the holidays. It seemed a bit weird to me that they had lived so far out in the woods. But then again, I’ve always been a quiet person, and living out in the woods does seem to give me a sense of serenity, so who am I to complain."
    );
    
    while(!dialogue.empty()) {
        std::cout << std::endl;
        std::cout << name << ": " << dialogue.top() << std::endl;
        std::cout << std::endl;
        dialogue.pop();
        std::cout << "Enter anything to continue. ";
        std::cin >> placeholder;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
}