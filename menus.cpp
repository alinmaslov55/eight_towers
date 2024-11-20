#include "menus.hpp"

Menu::Menu(){
    current_option = 0;
    problem = new Solution();
}

Menu::~Menu(){
    delete problem;
}

void Menu::printMenu() const {
    std::cout << "Welcome to the Eight Towers Problem Solver!" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Solve the problem" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int Menu::getOption(){
    std::cout << "Choose an option:" << std::endl;
    std::cin >> current_option;
    return current_option;
}

void Menu::executeOption(){
    switch(current_option){
        case 1:
            problem->printChessTable();
            break;
        case 0:
            std::cout << "Exiting the program..." << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please choose again." << std::endl;
            break;
    }
}