#ifndef VALIDATE_USER_INPUT_H
#define VALIDATE_USER_INPUT_H

#include <string>

class ValidateUserInput {
    private:
        bool checkValidString(std::string input);
    public:
        ValidateUserInput();
        int getValidInput(int startRange, int endRange);
        bool getCorrectCode(int code, int len);
        void printEndCard(int endingNum);
};

#endif