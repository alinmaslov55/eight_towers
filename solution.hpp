#ifndef SOLUTION
#define SOLUTION

#include "headers.hpp"

class Solution {
    std::vector<std::vector<bool>> ChessTable;
    int counter_of_solutions;

    void increase(){
        counter_of_solutions++;
    }
    void reset(){
        counter_of_solutions = 0;
    }
    bool rowIsFalse(int row){
        for(int i = 0; i < ANCHOR; i++){
            if(ChessTable[row][i] == true) return false;
        }
        return true;
    }
    public:
    Solution();

    void printChessTable();

    const int& getCounter() const;

    void iterateOverSolution(int columnNumber);

    ~Solution();
};

#endif