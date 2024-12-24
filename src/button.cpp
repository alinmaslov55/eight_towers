#include "button.hpp"

Button::Button(Rectangle rect){
    this->rect = rect;
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
    } else {
        DrawRectangleRec(this->rect, WHITE);
    }
}
bool Button::WasPressed() {
    return this->is_pressed;
}