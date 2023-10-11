#ifndef FIRST_GUEST_BEDROOM_H
#define FIRST_GUEST_BEDROOM_H

#include "ValidateUserInput.h"
#include <vector>
#include <string>

class FirstGuestBedroom {
    private:
        ValidateUserInput checkInput;
        bool visited;
        bool visitedLocation[4];
        bool openedSafe;
        std::vector<std::string> items;
        std::string name;
    public:
        FirstGuestBedroom();
        void printInitialDialogue();
        void printInteractables();
        void getInput();
        std::vector<std::string> getItems();
        void clearItems();
        void setName(std::string user);
};

#endif