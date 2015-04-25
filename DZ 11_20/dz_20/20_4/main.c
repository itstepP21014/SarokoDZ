#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../modules/useful_stuff.h"


int main()
{
    int first=0,second=0;
    int x_size,y_size;
    printf("Please enter the size of the maze:\nY:");
    scanf("%d",&y_size);
    fflush(stdin);
    printf("\nX:");
    scanf("%d",&x_size);
    fflush(stdin);
    printf("\n");
    char maze[y_size][x_size];

//creating a maze
//*********************************
maze_generator(&maze[0][0],x_size,y_size);
//***************************


    second=0;
    first=0;
    while (first<y_size)
    {
        while (second<x_size)
        {
            printf("%c",maze[first][second]);
            ++second;
        }
        second=0;
        printf("\n");
        ++first;

    }
    printf("\n");
    return 0;
}
