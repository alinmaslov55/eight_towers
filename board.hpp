#ifndef BOARD
#define BOARD
#include "headers.hpp"
#include "raylib.h"

class Cell {
    float x, y;
    bool is_black;
    bool is_occupied;
    std::vector<std::vector<Rectangle>> parts;
    public:
    Cell(float x, float y, bool is_black);
    void Update(bool status);
    void Draw();
    bool verify(int i, int j);
};
class Board{
    std::vector<std::vector<Cell>> cells;
    public:
    Board();
    void Draw();
    void Update(std::vector<std::vector<bool>>& vec);
};


#endif
