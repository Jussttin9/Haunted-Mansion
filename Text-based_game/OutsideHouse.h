#ifndef OUTSIDE_HOUSE_H
#define OUTSIDE_HOUSE_H

#include "ValidateUserInput.h"
#include "User.h"

#include <string>

class OutsideHouse {
    private:
        ValidateUserInput checkInput;
        User* player;
    public:
        OutsideHouse();
        void printLocations();
        void getInput();
        void setUser(User &username);
        void printCarLocations();
};

#endif