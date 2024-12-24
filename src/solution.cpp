#include "solution.hpp"

std::vector<std::vector<bool>> Solution::getRandomSolution() {
    std::vector<std::vector<bool>> vec(ANCHOR, std::vector<bool>(ANCHOR, false));
    getOneSolution(vec, 0);
    return vec;
}

void Solution::getOneSolution(std::vector<std::vector<bool>>& table, int n) {
    if (n == ANCHOR) {
        return;
    }

    std::vector<int> rows(ANCHOR);
    for(int i = 0; i < ANCHOR; i++) {
        rows[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rows.begin(), rows.end(), g);

    for (int i : rows) {
        if (rowIsFalse(table, i)) {
            table[i][n] = true;
            getOneSolution(table, n + 1);
            return;
        }
    }
}

bool Solution::rowIsFalse(const std::vector<std::vector<bool>>& vec, int row) {
    for (int i = 0; i < ANCHOR; i++) {
        if (vec[row][i]) {
            return false;
        }
    }
    return true;
}
