#include <raylib.h>

int player_x = 200;
int player_y = 200;

void Move(){
    if(IsKeyDown(KEY_D)){
        player_x += 5;
    }
    if(IsKeyDown(KEY_A)){
        player_x -= 5;
    }
    if(IsKeyDown(KEY_W)){
        player_y -= 5;
    }
    if(IsKeyDown(KEY_S)){
        player_y += 5;
    }
}

int checkBorderY(int y, int height){
    float border_bottom = height;

    if(y >= border_bottom){
        y = border_bottom;
    }

    if(y <= 0 ){
        y = 0;
    }
    return y;

}

int checkBorderX(int x, int width){
    float border_bottom = width;

    if(x >= border_bottom){
        x = border_bottom;
    }

    if(x <= 0 ){
        x = 0;
    }
    return x;

}