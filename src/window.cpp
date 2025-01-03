#include "window.hpp"


Window::Window(){
    this->my_board = new Board();
    this->button = new Button(Rectangle{BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT});
    // se initializeaza matricea cu toate valorile false pentru a arata tabla goala
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
        // are loc generarea unei noi solutii, doar in cazul in care butonul este apasat
        // solutia este data complet random de clasa Solution
        // current_table este un vector cu toate celulele unei table
        // false - semnifica celula este libera
        // true semnifica celula este ocupata de un turn
        current_table = Solution::getRandomSolution();
        button->Update();
    }
    // solutia este transmisa mai departe pentru modificari vizuale
    my_board->Update(current_table);
}