#include "raylib/src/raylib.h"
#include <stdio.h>
#include <stdlib.h>

int orb_x = 0;

int spawn_orb(){

    int spawn_location = rand()%4;
   // printf("Random direction is %i\n", spawn_location); ---> This Is Debugging For The Randomization Of Spawn Points.
    return spawn_location;
}

int move_orb(int orb_speed){

    orb_x += orb_speed;

    return orb_x;
}

