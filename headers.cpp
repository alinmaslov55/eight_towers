#include "headers.hpp"

const int ANCHOR = 8;
extern const float BOARD_X = 100.0f;
extern const float BOARD_Y = 200.0f;
extern const float BOARD_SIZE = 441.0f;
extern const float CELL_SIZE = 50.0f;
extern const int WINDOW_WIDTH = 600;
extern const int WINDOW_HEIGHT = 700;

extern std::vector<std::vector<bool>> vector_for_testing = {
    {false, false, false, false, false, false, false, false},
    {false, true, false, false, false, false, false, false},
    {false, false, true, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
};