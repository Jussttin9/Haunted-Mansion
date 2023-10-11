#include "User.h"
#include "ValidateUserInput.h"
#include <iostream>
#include <string>

User::User() {
    // Initializes all available item descriptions
    itemDescript.insert(std::pair<std::string, std::string>("Basement Key", "A small, golden key. It looked like it had been submerged in blood."));
    itemDescript.insert(std::pair<std::string, std::string>("Bolt Cutters", "It was pretty big. Definitely able to get through the strongest chains."));
    itemDescript.insert(std::pair<std::string, std::string>("Crowbar", "A rusted, metal crowbar."));
    itemDescript.insert(std::pair<std::string, std::string>("Flashlight", "This has been very helpful illuminating this dark, eerie house."));
    itemDescript.insert(std::pair<std::string, std::string>("Hammer", "A surprisingly new hammer. I wonder if I could use this for anything."));
    itemDescript.insert(std::pair<std::string, std::string>("Keys", "These keys helped me get through the front door."));
    itemDescript.insert(std::pair<std::string, std::string>("Lighter", "I found this lighter in my cousin's play corner. Why was it left here? Why was it even here in the first place?"));
    itemDescript.insert(std::pair<std::string, std::string>("Lockpick", "A tiny lockpick made from a paperclip."));
    itemDescript.insert(std::pair<std::string, std::string>("Ripped Page 1", pageInfo.getRippedPageContents(1)));
    itemDescript.insert(std::pair<std::string, std::string>("Ripped Page 16", pageInfo.getRippedPageContents(16)));
    itemDescript.insert(std::pair<std::string, std::string>("Ripped Page 26", pageInfo.getRippedPageContents(26)));
    itemDescript.insert(std::pair<std::string, std::string>("Ripped Page 30", pageInfo.getRippedPageContents(30)));
    itemDescript.insert(std::pair<std::string, std::string>("Ripped Page 34", pageInfo.getRippedPageContents(34)));
    itemDescript.insert(std::pair<std::string, std::string>("Room 2 Key", "I can use this key to unlock the second room in the basement."));
    itemDescript.insert(std::pair<std::string, std::string>("Room 3 Key", "I can use this key to unlock the third room in the basement."));
    itemDescript.insert(std::pair<std::string, std::string>("Room 4 Key", "I can use this key to unlock the fourth room in the basement."));
    itemDescript.insert(std::pair<std::string, std::string>("Room 5 Key", "I can use this key to unlock the fifth room in the basement."));
}

void User::setName() {
    bool confirmed = false;
    int input;
    std::string username;
    while(!confirmed) {
        std::cout << "Please enter your name: ";
        std::cin >> username;
        std::cout << "Your name is " << username << ". Correct?" << std::endl;
        std::cout << "1. Yes" << std::endl << "2. No" << std::endl;
        input = checkInput.getValidInput(1, 2);
        if(input == 1) confirmed = true;
    }
    name = username;
}

std::string User::getName() {
    return name;
}

bool User::checkInventory(std::string item) {
    return inventory.count(item);
}

void User::printInventory() {
    int count = 0;

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "              Inventory            " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Item Name\t\tItem Count" << std::endl;
    for(std::map<std::string, int>::iterator iter = inventory.begin(); iter != inventory.end(); ++iter) {
        count++;
        std::cout << count << ". " << iter->first << "\t\t" << iter->second << std::endl;
        itemList.push_back(iter->first);
    }
    count++;
    std::cout << std::endl;
    std::cout << count << ". Exit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    getItemDescription();
}

void User::addToInventory(std::string item, bool stackable) {
    if(!inventory.count(item)) {
        inventory.insert(std::pair<std::string, int>(item, 1));
    } else if(stackable) {
        std::map<std::string, int>::iterator iter = inventory.find(item);
        iter->second = iter->second + 1;
    }
}

void User::addToInventory(std::string item, int count) {
    if(!inventory.count(item)) {
        inventory.insert(std::pair<std::string, int>(item, count));
    } else {
        std::map<std::string, int>::iterator iter = inventory.find(item);
        iter->second = iter->second + count;
    }
}

void User::getItemDescription() {
    if(itemList.size() == 0) return;
    std::cout << "What should I inspect? ";
    int input = checkInput.getValidInput(1, itemList.size()+1);
    int count = 1;
    while(input != itemList.size()+1) {
        for(std::string item : itemList) {
            if(count == input) {
                std::cout << "--------------" << std::endl;
                std::cout << item << std::endl;
                std::cout << "--------------" << std::endl;
                std::cout << itemDescript[item] << std::endl;
                std::cout << "--------------" << std::endl;
                break;
            }
            count++;
        }
        count = 1;
        std::cout << "What should I inspect? ";
        input = checkInput.getValidInput(1, itemList.size()+1);
    }
    itemList.clear();
}