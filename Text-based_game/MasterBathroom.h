#ifndef MASTER_BATHROOM_H
#define MASTER_BATHROOM_H

#include "ValidateUserInput.h"

#include <vector>
#include <string>

class MasterBathroom {
    private:
        ValidateUserInput checkInput;
        bool visited;
        bool visitedLocation[3];
        std::vector<std::string> items;
        std::string name;
    public:
        MasterBathroom();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        std::vector<std::string> getItems();
        void clearItems();
        void setName(std::string user);
};

#endif