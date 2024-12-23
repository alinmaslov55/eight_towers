
#ifndef WINDOW
#define WINDOW
#include "headers.hpp"
#include "raylib.h"
#include "board.hpp"

class Window {
    Board* my_board;
    public:
    Window();
    void Draw();
    void Update();

    ~Window();
};

#endif
