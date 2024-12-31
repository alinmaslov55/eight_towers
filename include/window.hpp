
#ifndef WINDOW
#define WINDOW
#include "headers.hpp"
#include "raylib.h"
#include "board.hpp"
#include "button.hpp"

// clasa Window contine toate obiectele ce se afiseaza pe ecran
// buton - folosit pentru generarea unei noi solutii
// la inceput solutia este goala
// board - clasa responsabila de printarea tuturor obiectelor pe tabla
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
