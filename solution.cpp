#include "solution.hpp"

Solution::Solution(){
    // Initializeaza matricea ce Reprezinta Tabla de Sah
    // prin resize() i se aloca execat 8 randuri si coloane
    // celulele sunt initializate cu false
    ChessTable.resize(ANCHOR, std::vector<bool>(ANCHOR, false));

    counter_of_solutions = 0;
}

Solution::~Solution(){
    // Nu necisita cod intrucat nu avem alocari de memorie
}


void Solution::printChessTable(std::ofstream &file){
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
    file << "\n|-----------------|";
    for(auto row : ChessTable){
        file << "\n| ";
        for(auto cell : row){
            file << (cell ? "T" : "*") << " ";
        }
        file << "|";
    }
    file << "\n|-----------------|\n";

    increase();
}
void Solution::printChessTable(){
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

    increase();
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
void Solution::iterateOverSolution(int columnNumber, std::ofstream& file){
    if(columnNumber == ANCHOR){
        // inregistrare Solutie
        printChessTable(file);
        return;
    }
    for(int i = 0; i < ANCHOR; i++){
        if(rowIsFalse(i)){

            ChessTable[i][columnNumber] = true;
            iterateOverSolution(columnNumber + 1, file);
            
            ChessTable[i][columnNumber] = false;

        }
    }
}
const int& Solution::getCounter() const {
    return counter_of_solutions;
}