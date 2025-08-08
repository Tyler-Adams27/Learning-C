#include "raylib/src/raylib.h"
#include <stdio.h>
#include "player.c"
#include "random_orb.c"
#include <time.h>
#include <string.h>
// USE SNAKE_CASE
int score = 0;
char buff_score[20];
char* score_text[50];


int main(void){
    srand(time(NULL));
    const int screen_height = 600;
    const int screen_width = 800;
    const float center_x = screen_width / 2;;
    const char* title = "WASD";
    int orb_speed = 10;

    SetTargetFPS(60);
    InitWindow(screen_width, screen_height, title);
    float spacing = screen_height / 5;
    int spawn_pod[4] = {spacing, spacing * 2, spacing * 3, spacing * 4};
    int test_orb = spawn_orb();
    for(int i = 0; i <= 3; i++){
        printf("%i\n", spawn_pod[i]);
       }

    
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        if(orb_x >= screen_width){
            orb_x = 0;
            score ++;
            
            sprintf(buff_score, "Score: %d", score);
            test_orb = spawn_orb();
        }
        // Drawings here
        DrawLine(0,spawn_pod[0], screen_width, spawn_pod[0], GREEN);
        DrawLine(0,spawn_pod[1], screen_width, spawn_pod[1], GREEN);
        DrawLine(0,spawn_pod[2], screen_width, spawn_pod[2], GREEN);
        DrawLine(0,spawn_pod[3], screen_width, spawn_pod[3], GREEN);
        Move();
        DrawText("MOVE THE BALL WITH WASD", center_x - 150, 10, 20, WHITE);
        player_y = checkBorderY(player_y, screen_height);
        player_x = checkBorderX(player_x, screen_width);
        DrawCircle(player_x, player_y, 10, WHITE);
        DrawText(buff_score, 0, 10, 20, WHITE);
        
        move_orb(orb_speed);
        DrawCircle(orb_x,spawn_pod[test_orb],50,RED);
       // printf("Players position %i, %i\n", player_x, player_y);
        EndDrawing();
    }
    CloseWindow();
    return 0;
 
    
}

