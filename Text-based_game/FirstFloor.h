#ifndef FIRST_FLOOR_H
#define FIRST_FLOOR_H

#include "User.h"
#include "FirstGuestBedroom.h"
#include "FirstGuestBathroom.h"
#include "LivingRoom.h"
#include "Kitchen.h"
#include "DiningRoom.h"
#include "ValidateUserInput.h"
#include <string>
#include <vector>

class FirstFloor {
    private:
        User* player;
        FirstGuestBedroom guestBed;
        FirstGuestBathroom guestBath;
        LivingRoom livingRoom;
        Kitchen kitchen;
        DiningRoom diningRoom;
        void addItems(std::vector<std::string> items);
    public:
        FirstFloor();
        void printLocations();
        void getLocation(int input);
        bool getFireplaceStatus();
        void setUser(User& username);
        bool getStoveStatus();
};

#endif