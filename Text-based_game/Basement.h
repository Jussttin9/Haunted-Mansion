#ifndef BASEMENT_H
#define BASEMENT_H

#include "User.h"
#include "ValidateUserInput.h"

class Basement {
    private:
        User* player;
        ValidateUserInput checkInput;
        bool visitedLocation[5];
        int exitRange;
        bool foundMonster;
        void printPage();
    public:
        Basement();
        bool userInvestigates();
        bool printLighterDecision();

        void printLocations();
        void getLocation(int input);
        void setUser(User& username);
        int getExitRange();
        bool getMonsterStatus();
};

#endif