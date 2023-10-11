#ifndef USER_H
#define USER_H

#include "ValidateUserInput.h"
#include "RippedPages.h"

#include <string>
#include <map>
#include <vector>

class User {
    private:
        ValidateUserInput checkInput;
        RippedPages pageInfo;
        std::string name;
        std::map <std::string, int> inventory;
        std::map <std::string, std::string> itemDescript;
        std::vector<std::string> itemList;

        void getItemDescription();

    public:
        User();
        std::string getName();
        void setName();
        bool checkInventory(std::string item);
        void printInventory();
        void addToInventory(std::string item, bool stackable);
        void addToInventory(std::string item, int count);
};

#endif