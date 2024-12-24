#include "headers.hpp"
#include "window.hpp"

int main(){
    Window my_window;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chessboard");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        my_window.Update();
        
        my_window.Draw();
    }

    CloseWindow();

    return 0;
}
