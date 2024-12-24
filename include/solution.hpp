#ifndef SOLUTION
#define SOLUTION

#include "headers.hpp"
#include "random"


class Solution {
public:
    static const int ANCHOR = 8;

    static std::vector<std::vector<bool>> getRandomSolution();

private:
    static void getOneSolution(std::vector<std::vector<bool>>& table, int n);
    static bool rowIsFalse(const std::vector<std::vector<bool>>& vec, int row);
};


#endif