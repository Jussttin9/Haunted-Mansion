#ifndef SECOND_FLOOR_H
#define SECOND_FLOOR_H

#include "User.h"
#include "ValidateUserInput.h"
#include "CousinBedroom.h"
#include "SecondGuestBedroom.h"
#include "SecondGuestBathroom.h"
#include "MasterBedroom.h"

#include <vector>
#include <string>

class SecondFloor{
    private:
        User* player;
        ValidateUserInput checkInput;
        CousinBedroom bed;
        SecondGuestBedroom guestBed;
        SecondGuestBathroom guestBath;
        MasterBedroom masterBed;
        void addItems(std::vector<std::string> items);
    public:
        SecondFloor();
        void setUser(User& username);
        void printLocations();
        void getLocation(int input);
};

#endif