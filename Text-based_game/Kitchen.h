#ifndef KITCHEN_H
#define KITCHEN_H

#include "ValidateUserInput.h"

#include <vector>
#include <string>

class Kitchen {
    private:
        ValidateUserInput checkInput;
        bool visited;
        bool visitedLocation[6];
        bool stoveStatus;
        std::vector<std::string> items;
        std::string name;
        
        void printStoveDecision();
    public:
        Kitchen();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        bool getStoveStatus();
        std::vector<std::string> getItems();
        void clearItems();
        void setName(std::string user);
};

#endif