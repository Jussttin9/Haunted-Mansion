#ifndef SECOND_GUEST_BATHROOM_H
#define SECOND_GUEST_BATHROOM_H

#include "ValidateUserInput.h"

#include <vector>
#include <string>

class SecondGuestBathroom {
    private:
        ValidateUserInput checkInput;
        bool visited;
        bool visitedLocation[4];
        std::vector<std::string> items;
        std::string name;
    public:
        SecondGuestBathroom();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        std::vector<std::string> getItems();
        void clearItems();
        void setName(std::string user);
};

#endif