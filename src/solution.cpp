#include "solution.hpp"

std::vector<std::vector<bool>> Solution::getRandomSolution() {
    std::vector<std::vector<bool>> vec(ANCHOR, std::vector<bool>(ANCHOR, false));
    getOneSolution(vec, 0);
    return vec;
}

// table este transmis prin referinta pentru a asigura modificarile asupra acestuia
void Solution::getOneSolution(std::vector<std::vector<bool>>& table, int n) {
    // cazul de stop in care suntem inafara tablei
    if (n == ANCHOR) {
        return;
    }

    std::vector<int> rows(ANCHOR);
    for(int i = 0; i < ANCHOR; i++) {
        rows[i] = i;
    }

    // are loc interschimbarea intre toate valorile ce csemnifica randuri libere
    // pentru a pastra idea de generare aleatoare a solutiei
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rows.begin(), rows.end(), g);

    for (int i : rows) {
        if (rowIsFalse(table, i)) {
            // ocuparea celulei de un turn
            table[i][n] = true;
            // selectarea recursiva a urmatoarelor pozitii
            getOneSolution(table, n + 1);
            // se apeleaza return si se omite 'table[i][n] = false', intrucat este nevoie doar de o singura solutie
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
