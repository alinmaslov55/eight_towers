#ifndef BUTTON
#define BUTTON

#include "headers.hpp"
#include "raylib.h"

class Button{
    Rectangle rect;
    bool is_pressed;
    int font_size;
    int textWidth, textHeight;
    float textX, textY;
    public:
    Button(Rectangle rect);
    void Update();
    void Draw();
    bool WasPressed();
};


#endif