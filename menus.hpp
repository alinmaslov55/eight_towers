#ifndef MENU
#define MENU

#include "headers.hpp"
#include "solution.hpp"

class Menu {
    int current_option;
    Solution *problem;
    public:
    Menu();
    void printMenu() const;
    int getOption();
    void executeOption();
    ~Menu();
};


#endif