
#ifndef WINDOW
#define WINDOW
#include "headers.hpp"
#include "raylib.h"
#include "board.hpp"
#include "button.hpp"

class Window {
    Board* my_board;
    std::vector<std::vector<bool>> current_table;
    Button* button;
    public:
    Window();
    void Draw();
    void Update();

    ~Window();
};

#endif
