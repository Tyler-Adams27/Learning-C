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
    srand(time(NULL)); // Rerolls Seed.
    const int screen_height = 600;
    const int screen_width = 800;

    const float center_x = screen_width / 2; // Middle Of The Screen.
    const char* title = "WASD"; // Name Of The Created Window.
    int orb_speed = 10; // The Speed Of The "Enemy".

    SetTargetFPS(60); // I Don't Need To Explain This...

    InitWindow(screen_width, screen_height, title); // INITs The Window With The Set Parameters.

    float spacing = screen_height / 5; // The Space Between The "Enemy's" Different Spawn Locations.

    int spawn_pod[4] = {spacing, spacing * 2, spacing * 3, spacing * 4}; // Sets A List Of Different "Enemy" Spawn Points.

    int orb_loc = spawn_orb(); // Randomises The Next "Enemy" Spawn Location.

   /* for(int i = 0; i <= 3; i++){ 
        printf("%i\n", spawn_pod[i]); --->  This Is Debugging Stuff.
       }    
    */
    
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        if(orb_x >= screen_width){
            orb_x = 0;
            score ++;
            sprintf(buff_score, "Score: %d", score);
            orb_loc = spawn_orb();
        }

        // Drawings START Here

        /*
        DrawLine(0,spawn_pod[0], screen_width, spawn_pod[0], GREEN);
        DrawLine(0,spawn_pod[1], screen_width, spawn_pod[1], GREEN);
        DrawLine(0,spawn_pod[2], screen_width, spawn_pod[2], GREEN); -----> Debugging For "Enemy" Locations.
        DrawLine(0,spawn_pod[3], screen_width, spawn_pod[3], GREEN);
        */

        player_move();

        DrawText("MOVE THE BALL WITH WASD", center_x - 150, 10, 20, WHITE);

        player_y = check_border_y(player_y, screen_height);
        player_x = check_border_x(player_x, screen_width);

        DrawCircle(player_x, player_y, 10, WHITE); // Draws Player.
        DrawText(buff_score, 10, 10, 20, WHITE); // Display Score.
        move_orb(orb_speed); // Moves "Enemy".
        DrawCircle(orb_x,spawn_pod[orb_loc],20,RED); // Draws "Enemy".

        // Drawings END Here.
        EndDrawing();
    }
    CloseWindow();
    return 0;
 
    
}

