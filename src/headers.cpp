#include "headers.hpp"

const int ANCHOR = 8;
extern const float BOARD_X = 100.0f;
extern const float BOARD_Y = 200.0f;
extern const float BOARD_SIZE = 441.0f;
extern const float CELL_SIZE = 50.0f;
extern const int WINDOW_WIDTH = 600;
extern const int WINDOW_HEIGHT = 700;
extern const int PARTS = 5;
extern const float GAP_SIZE = 3.0f;
extern const float BIG_GAP_SIZE = 10.0f;
extern const float BUTTON_WIDTH = 200.0f;
extern const float BUTTON_HEIGHT = 100.0f;
extern const float BUTTON_X = 100.0f;
extern const float BUTTON_Y = 100.0f;

extern const std::vector<std::vector<bool>> vector_for_testing = {
    {false, false, false, false, false, false, false, false},
    {false, true, false, false, false, false, false, false},
    {false, false, true, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false},
};


bool operator==(const Color& lhs, const Color& rhs){
    return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a;
}