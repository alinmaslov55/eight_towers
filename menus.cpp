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
    std::cout << "1. Show all the solutions in the terminal" << std::endl;
    std::cout << "2. Print all the solutions in a txt file" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int Menu::getOption(){
    std::cout << "Choose an option:" << std::endl;
    while (true) {

        std::cin >> current_option;

        // Check if cin is in a fail state
        if (std::cin.fail()) {
            std::cout << "\nPlease enter a valid input type" << std::endl;
            std::cin.clear();               // Clear the fail state
            std::cin.ignore(1000, '\n');    // Discard invalid input
        } else {
            break; // Input is valid, exit the loop
        }
    }


    return current_option;
}

void Menu::executeOption(){

    std::ofstream file;

    switch(current_option){
        case 1:
            problem->iterateOverSolution(0);
            std::cout << "\nNumber of total solutions:" << problem->getCounter() << std::endl;
            break;
        case 2:
            file.open(getFileName());
            problem->iterateOverSolution(0, file);
            break;
        case 0:
            std::cout << "Exiting the program..." << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please choose again." << std::endl;
            break;
    }
}