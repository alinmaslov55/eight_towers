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

    file << "\nSolution nr. " << this->getCounter();
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
    increase();

    std::cout << "\nSolution nr. " << this->getCounter();
    std::cout << "\n-------------------";
    for(auto row : ChessTable){
        std::cout << "\n| ";
        for(auto cell : row){
            std::cout << (cell ? "T" : "*") << " ";
        }
        std::cout << "|";
    }
    std::cout << "\n-------------------\n";

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
void Solution::iterateOverSolution(int columnNumber, int nSolutions){
    if(nSolutions <= getCounter()) return;

    if(columnNumber == ANCHOR){
        // inregistrare Solutie
        printChessTable();
        return;
    }
    for(int i = 0; i < ANCHOR; i++){
        if(rowIsFalse(i)){

            ChessTable[i][columnNumber] = true;
            iterateOverSolution(columnNumber + 1, nSolutions);

            ChessTable[i][columnNumber] = false;

        }
    }
}
void Solution::iterateOverSolutionRandom(int columnNumber, int nSolutions){
    if(nSolutions <= getCounter()) return;

    if(columnNumber == ANCHOR){
        // inregistrare Solutie
        printChessTable();
        return;
    }

    std::vector<int> variants;
    
    for(int i = 0; i < ANCHOR; i++){
        if(rowIsFalse(i)) variants.push_back(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd()); // Random number generator

    std::shuffle(variants.begin(), variants.end(), gen);

    for(int i : variants){
        ChessTable[i][columnNumber] = true;
        iterateOverSolution(columnNumber + 1, nSolutions);

        ChessTable[i][columnNumber] = false;
    }
}

int Solution::getNumSolutions(){
    int numSolutions{0};
    
    do{
        std::cout << "How many solutions(1 - 40320): ";
        std::cin >> numSolutions;
    }while(!(numSolutions > 0 && numSolutions <= 40320));
    
    return numSolutions;
}