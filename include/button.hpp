#ifndef BUTTON
#define BUTTON

#include "headers.hpp"
#include "raylib.h"

class Button{
    Rectangle rect;
    bool is_pressed;
    public:
    Button(Rectangle rect);
    void Update();
    void Draw();
    bool WasPressed();
};


#endif