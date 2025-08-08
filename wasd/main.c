#include <raylib.h>
#include <stdio.h>
#include "player.c"

// USE SNAKE_CASE

int main(void){

    const int screen_height = 600;
    const int screen_width = 800;
    const float center_x = screen_width / 2;
    const float center_y = screen_height / 2;
    const char* title = "WASD";
    SetTargetFPS(60);
    InitWindow(screen_width, screen_height, title);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        // Drawings here
        
        Move();
        DrawText("MOVE THE BALL WITH WASD", center_x - 150, 10, 20, WHITE);
        player_y = checkBorderY(player_y, screen_height);
        player_x = checkBorderX(player_x, screen_width);
        DrawCircle(player_x, player_y, 10, WHITE);
        printf("Players position %i, %i\n", player_x, player_y);
        EndDrawing();
    }
    CloseWindow();
    return 0;
 
    
}

