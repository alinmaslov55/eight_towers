#ifndef MENU
#define MENU

#include "headers.hpp"
#include "solution.hpp"

class Menu {
    int current_option;
    Solution *problem;

    public:
    std::string getFileName(){
        std::string filename;
        std::ofstream file;

        do{
            std::cout << "Enter the name of the output file: ";
            std::cin >> filename;
            file.open(filename);
        } while(!file.is_open());

        file.close();

        return filename;
    } 

    Menu();
    void printMenu() const;
    int getOption();
    void executeOption();
    void giveDockerTip();
    ~Menu();
};


#endif