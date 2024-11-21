#ifndef SOLUTION
#define SOLUTION

#include "headers.hpp"

class Solution {
    std::vector<std::vector<bool>> ChessTable;
    

    bool rowIsFalse(int row){
        for(int i = 0; i < ANCHOR; i++){
            if(ChessTable[row][i] == true) return false;
        }
        return true;
    }
    public:
    Solution();

    void printChessTable() const;

    void iterateOverSolution(int columnNumber);

    ~Solution();
};

#endif