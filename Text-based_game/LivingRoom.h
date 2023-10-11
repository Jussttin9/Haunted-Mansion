#ifndef LIVING_ROOM_H
#define LIVING_ROOM_H

#include "ValidateUserInput.h"

#include <vector>
#include <string>

class LivingRoom {
    private:
        ValidateUserInput checkInput;
        bool visited;
        bool visitedLocation[4];
        bool openedFireplace;
        std::vector<std::string> items;
        std::string name;
    public:
        LivingRoom();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        bool fireplaceStatus();
        std::vector<std::string> getItems();
        void clearItems();
        void setName(std::string user);
};

#endif