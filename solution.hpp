#ifndef SOLUTION
#define SOLUTION

#include "headers.hpp"
#include <algorithm>
#include <random>

class Solution {
    std::vector<std::vector<bool>> ChessTable;
    int counter_of_solutions;

    void increase(){
        counter_of_solutions++;
    }
    bool rowIsFalse(int row){
        for(int i = 0; i < ANCHOR; i++){
            if(ChessTable[row][i] == true) return false;
        }
        return true;
    }
    public:
    void reset(){
        counter_of_solutions = 0;
    }
    Solution();

    void printChessTable();
    void printChessTable(std::ofstream& file);

    const int& getCounter() const;

    void iterateOverSolution(int columnNumber);
    void iterateOverSolution(int columnNumber, int nSolutions);
    void iterateOverSolutionRandom(int columnNumber, int nSolutions);
    void iterateOverSolution(int columnNumber, std::ofstream& file);

    ~Solution();
};

#endif