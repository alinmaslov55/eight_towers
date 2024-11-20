#include "solution.hpp"

Solution::Solution(){
    // Initializeaza matricea ce Reprezinta Tabla de Sah
    // prin resize() i se aloca execat 8 randuri si coloane
    // celulele sunt initializate cu false
    ChessTable.resize(ANCHOR, std::vector<bool>(ANCHOR, false));
}

Solution::~Solution(){
    // Nu necisita cod intrucat nu avem alocari de memorie
}


void Solution::printChessTable() const {
    // Afisarea matricii
    /*

    T*******
    *T******
    **T*****
    ***T****
    ****T***
    *****T**
    ******T*
    *******T
    
    */

    for(auto row : ChessTable){
        for(auto cell : row){
            std::cout << (cell ? "T" : "*") << " ";
        }
        std::cout << std::endl;
    }


}