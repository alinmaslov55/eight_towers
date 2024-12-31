#ifndef SOLUTION
#define SOLUTION

#include "headers.hpp"
#include "random"


class Solution {
public:
    static const int ANCHOR = 8;

    static std::vector<std::vector<bool>> getRandomSolution();

private:
    // functie apelata recursiv in getRandomSolution()
    static void getOneSolution(std::vector<std::vector<bool>>& table, int n);
    // functie care verifica daca un rand este sau nu este ocupat de un turn
    static bool rowIsFalse(const std::vector<std::vector<bool>>& vec, int row);
};


#endif