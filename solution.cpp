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
    std::cout << "\n|-----------------|";
    for(auto row : ChessTable){
        std::cout << "\n| ";
        for(auto cell : row){
            std::cout << (cell ? "T" : "*") << " ";
        }
        std::cout << "|";
    }
    std::cout << "\n|-----------------|\n";


}
void Solution::iterateOverSolution(int columnNumber){
    if(columnNumber == ANCHOR){
        // inregistrare Solutie
        printChessTable();
        return;
    }
    for(int i = 0; i < ANCHOR; i++){
        if(rowIsFalse(i)){

            ChessTable[i][columnNumber] = true;
            iterateOverSolution(columnNumber + 1);
            
            ChessTable[i][columnNumber] = false;

        }
    }
}