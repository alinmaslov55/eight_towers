#include "headers.hpp"
#include "solution.hpp"
#include "menus.hpp"
#include <memory>

int main(){

    std::unique_ptr<Menu> menu_of_program(new Menu());

    int option;
    std::cout << "Welcome to the Eight Towers Problem Solver!" << std::endl;

    do{
        menu_of_program->printMenu();
        option = menu_of_program->getOption();
        menu_of_program->executeOption();
    }while(option);

    return 0;
}
