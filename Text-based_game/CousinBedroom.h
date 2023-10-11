#ifndef COUSIN_BEDROOM_H
#define COUSIN_BEDROOM_H

#include "ValidateUserInput.h"

#include <vector>
#include <string>

class CousinBedroom {
    private:
        ValidateUserInput checkInput;
        bool visited;
        bool visitedLocation[3];
        std::vector<std::string> items;
        std::string name;
    public:
        CousinBedroom();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        std::vector<std::string> getItems();
        void clearItems();
        void setName(std::string user);
};

#endif