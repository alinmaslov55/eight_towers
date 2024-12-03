#include "headers.hpp"

const int ANCHOR = 8;

void newline(){
    std::cout << "\n";
}

const std::string extract_filename(std::string line){
    int length = line.length();
    if(length < 5 || line.at(0) == '.') return "";
    std::string termination = line.substr(length - 4, length);
    if(termination ==".txt"){
        return line;
    } else {
        return line + ".txt";
    }
}