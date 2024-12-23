#include "headers.hpp"
#include "solution.hpp"
#include "window.hpp"

int main(){
    Window my_window;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chessboard");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        my_window.Draw();
        my_window.Update();
        
    }

    CloseWindow();

    return 0;
}
