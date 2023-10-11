#ifndef MASTER_BEDROOM_H
#define MASTER_BEDROOM_H

#include "ValidateUserInput.h"
#include "MasterBathroom.h"

#include <vector>
#include <string>

class MasterBedroom {
    private:
        ValidateUserInput checkInput;
        MasterBathroom masterBath;
        bool visited;
        bool unlocked;
        bool visitedLocation[2];
        std::vector<std::string> itemsBed;
        std::string name;

        void addItems(std::vector<std::string> items);
    public:
        MasterBedroom();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        std::vector<std::string> getItems();
        void clearItems();
        bool getUnlockedStatus();
        void setUnlockedStatus(bool status);
        void setName(std::string user);
};

#endif