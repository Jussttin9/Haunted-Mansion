#ifndef RIPPED_PAGES_H
#define RIPPED_PAGES_H

#include <string>

class RippedPages {
    public:
        void printRippedPageContents(int locationNum, int pageNum);
        std::string getRippedPageContents(int pageNum);
};

#endif