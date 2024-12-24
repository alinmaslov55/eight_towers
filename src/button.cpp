#include "button.hpp"

Button::Button(Rectangle rect){
    this->rect = rect;
    font_size = 20;
    textWidth = MeasureText("Click Me for new Solution", font_size);
    if(textWidth == 0){
        textWidth = 260;
    }
    textHeight = font_size;
    textX = rect.x + (rect.width/2 - (textWidth / 2));
    textY = rect.y + (rect.height - textHeight)/2;
}
void Button::Update(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), this->rect)){
        this->is_pressed = true;
    }
    else{
        this->is_pressed = false;
    }
}
void Button::Draw(){
    if(CheckCollisionPointRec(GetMousePosition(), this->rect)){
        DrawRectangleRec(this->rect, GRAY);
        DrawText("Click Me for new Solution", textX, textY, font_size, WHITE);
    } else {
        DrawRectangleRec(this->rect, WHITE);
        DrawText("Click Me for new Solution", textX, textY, font_size, GRAY);
    }
}
bool Button::WasPressed() {
    return this->is_pressed;
}