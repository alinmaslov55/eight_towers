#include "window.hpp"


Window::Window(){
    this->my_board = new Board();
}

Window::~Window(){
    delete my_board;
}


void Window::Draw(){
    BeginDrawing();
    ClearBackground(PURPLE);
    my_board->Draw();
    EndDrawing();
}

void Window::Update(){
    my_board->Update(vector_for_testing);
}