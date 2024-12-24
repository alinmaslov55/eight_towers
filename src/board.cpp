#include "board.hpp"


// BOARD functions
Board::Board(){
    // Initialize board with cells
    float x = BOARD_X + BIG_GAP_SIZE;
    float y = BOARD_Y + BIG_GAP_SIZE;

    Color starting_color = WHITE;
    for(int i = 0; i < ANCHOR; i++){
        std::vector<Cell> row;
        Color color = starting_color;
        for(int j = 0; j < ANCHOR; j++){
            Cell cell(x + j * (CELL_SIZE + GAP_SIZE), 
                    y + i * (CELL_SIZE + GAP_SIZE), 
                    (color == WHITE) ? false : true);
            row.push_back(cell);
            if(color == WHITE){
                color = BLACK;
            } else {
                color = WHITE;
            }
        }

        if(starting_color == WHITE){
            starting_color = BLACK;
        } else if(starting_color == BLACK){
            starting_color = WHITE;
        }
        cells.push_back(row);
    }
    cells.shrink_to_fit();
}

void Board::Draw(){
    DrawRectangleRec(Rectangle{BOARD_X, BOARD_Y, BOARD_SIZE, BOARD_SIZE}, BROWN);

    // Draw each cell in the board
    for(int i = 0; i < ANCHOR; i++){
        for(int j = 0; j < ANCHOR; j++){
            cells[i][j].Draw();
        }
    }
}

void Board::Update(const std::vector<std::vector<bool>>& vec){
    for(int i = 0; i < ANCHOR; i++){
        for(int j = 0; j < ANCHOR; j++){
            cells[i][j].Update(vec[i][j]);
        }
    }
}


// CELL Functions 
Cell::Cell(float x, float y, bool is_black){
    this->is_black = is_black;
    this->is_occupied = false;
    this->x = x;
    this->y = y;

    for(int i = 0; i < PARTS; i++){
        std::vector<Rectangle> row;
        for(int j = 0; j < PARTS; j++){
            Rectangle part = {
                x + (j * 10),
                y + (i * 10),
                10,
                10
            };
            row.push_back(part);   
        }
        this->parts.push_back(row);
    }
}
bool Cell::verify(int i, int j){
/*
    _____
    _***_
    __*__
    __*__
    _____
*/
    if(i == 1){
        if(j == 1 || j == 2 || j == 3) return true;
    }
    if(i == 2 || i == 3){
        if(j == 2) return true;
    }

    return true;
}
void Cell::Update(bool status){
    this->is_occupied = status;
}
void Cell::Draw(){
    // Draw the cell
    for(int i = 0; i < PARTS; i++){
        for(int j = 0; j < PARTS; j++){
            if(this->is_occupied && verify(i, j)){
                DrawRectangleRec(parts[i][j], GREEN);
            } else {
                DrawRectangleRec(parts[i][j], (is_black)? BLACK : WHITE);                
            }
        }
    }
}