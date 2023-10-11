#ifndef DINING_ROOM_H
#define DINING_ROOM_H

#include "ValidateUserInput.h"

#include <vector>
#include <string>

class DiningRoom {
    private:
        ValidateUserInput checkInput;
        bool visited;
        bool visitedLocation[2];
        std::vector<std::string> items;
        std::string name;
    public:
        DiningRoom();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        std::vector<std::string> getItems();
        void clearItems();
        void setName(std::string user);
};

#endif