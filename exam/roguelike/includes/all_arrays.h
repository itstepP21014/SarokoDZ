#ifndef ALL_ARRAYS_H_INCLUDED
#define ALL_ARRAYS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct coordinates
{
    int y_begin;
    int x_begin;
    int y_end;
    int x_end;
}coordinates;

typedef struct maze
{
    char square;
    int visibility;
    int event_search;
    int event_enter;
    int enemy_enter;
}maze;

coordinates maze_generator(maze*,int,int,coordinates);
void event_generator(int*,int,int);

#endif // ALL_ARRAYS_H_INCLUDED
