#include <conio.h>
#include "includes/all_arrays.h"
#include "../../modules/compatibility.h"
#include <SDL.h>

int main(int argc,char* argv[])
{
    int first=0,second=0,counter=20,swi=1;
    int y_size_of_map=0,x_size_of_map=0;
    char direction,key_=0;
    coordinates start_end_location;

    system("chcp 1251");
    system("cls");
    printf("¬ведите размеры карты:\n");
    printf("\nY:");
    scanf("%d",&y_size_of_map);
    fflush(stdin);
    printf("\nX:");
    scanf("%d",&x_size_of_map);
    fflush(stdin);

    int events[y_size_of_map][x_size_of_map];
    maze dungeon[y_size_of_map][x_size_of_map];

    while (first<y_size_of_map)
    {
        while (second<x_size_of_map)
        {
            dungeon[first][second].visibility=0;
            ++second;
        }
        second=0;
        printf("\n");
        ++first;

    }

    start_end_location=maze_generator(&dungeon[0][0],y_size_of_map,x_size_of_map,start_end_location);



    while (counter!=0)
    {
        dungeon[start_end_location.y_begin][start_end_location.x_begin].visibility=2;
        dungeon[start_end_location.y_begin-1][start_end_location.x_begin-1].visibility=1;
        dungeon[start_end_location.y_begin-1][start_end_location.x_begin].visibility=1;
        dungeon[start_end_location.y_begin-1][start_end_location.x_begin+1].visibility=1;
        dungeon[start_end_location.y_begin][start_end_location.x_begin+1].visibility=1;
        dungeon[start_end_location.y_begin+1][start_end_location.x_begin+1].visibility=1;
        dungeon[start_end_location.y_begin+1][start_end_location.x_begin].visibility=1;
        dungeon[start_end_location.y_begin+1][start_end_location.x_begin-1].visibility=1;
        dungeon[start_end_location.y_begin][start_end_location.x_begin-1].visibility=1;

        universalClear();

        second=0;
        first=0;
        while (first<y_size_of_map)
        {
            while (second<x_size_of_map)
            {
                if (first==start_end_location.y_begin && second==start_end_location.x_begin)
                    printf("@");
                else
                {
                    if (dungeon[first][second].visibility==1)
                        printf("%c",dungeon[first][second].square);
                    else
                        printf(" ");
                }
                ++second;
            }
            second=0;
            printf("\n");
            ++first;
        }
        --counter;

        while(swi==1)
        {
            if(kbhit())//buffer keyboard not empty?
            {
                key_=getch();
                switch (key_)
                {
                case 72:
                    if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square!='#'&& dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square!='_' && dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square!='|')
                        start_end_location.y_begin-=1;
                        swi=0;
                    break;
                case 75:
                    if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square!='#'&& dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square!='_' && dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square!='|')
                        start_end_location.x_begin-=1;
                        swi=0;
                    break;
                case 80:
                    if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square!='#'&& dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square!='_' && dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square!='|')
                        start_end_location.y_begin+=1;
                        swi=0;
                    break;
                case 77:
                    if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square!='#' && dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square!='_' && dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square!='|')
                        start_end_location.x_begin+=1;
                        swi=0;
                }
            }
        }
        swi=1;
    }

    return 0;
}
