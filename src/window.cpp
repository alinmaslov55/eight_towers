#include "window.hpp"


Window::Window(){
    this->my_board = new Board();
    this->button = new Button(Rectangle{BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT});
    for(int i = 0; i < ANCHOR; i++){
        std::vector<bool> row;
        for(int j = 0; j < ANCHOR; j++){
            row.push_back(false);
        }
        this->current_table.push_back(row);
    }
}

Window::~Window(){
    delete my_board;
    delete button;
}


void Window::Draw(){
    BeginDrawing();
    ClearBackground(PURPLE);
    button->Draw();
    my_board->Draw();
    EndDrawing();
}

void Window::Update(){
    button->Update();
    if(button->WasPressed()){
        // update on current_table
        current_table = Solution::getRandomSolution();
        button->Update();
    }
    my_board->Update(current_table);
}