#include "all_arrays.h"


coordinates maze_generator(maze*maze_,int y_size,int x_size,coordinates start_end_loc)
{

    srand(time(NULL));
    int first=0,second=0,x_enter,y_enter,right_left,y_move,x_move,counter_maze=0,counter,swi=0,check=0,count;
    int door_chance;
    while (first<y_size)
    {
        while (second<x_size)
        {
            maze_[x_size*first+second].square='#';
            ++second;
        }
        second=0;
        ++first;
    }

    second=0;
    first=0;
    printf("\n");
    y_enter=rand()%y_size;
    if (y_enter==0 || y_enter==69)
        x_enter=rand()%x_size;
    else
    {
        right_left=rand()%2;
        if (right_left==0)
            x_enter=0;
        else
            x_enter=x_size-1;
    }
    maze_[x_size*y_enter+x_enter].square=' ';

    start_end_loc.y_end=y_enter;
    start_end_loc.x_end=x_enter;

    printf ("\ny_enter:%d\n",y_enter);
    if (y_enter==0)
    {
        y_move=y_enter+1;
        x_move=x_enter;
    }
    else if (y_enter==y_size-1)
    {
        y_move=y_enter-1;
        x_move=x_enter;
    }
    else
    {
        y_move=y_enter;
        if (right_left==0)
            x_move=1;
        else
            x_move=x_size-2;
    }
    maze_[x_size*y_move+x_move].square=' ';
    count=x_size*y_size;

    counter=(rand()%151)+count/20;
    while (counter_maze<counter)
    {
        first=rand()%4;
        if (first==0)
        {
            if (x_move-3>0)
            {
                swi=1;
                --x_move;
            }
        }
        if (first==1)
        {
            if (x_move+3<x_size-1)
            {
                swi=1;
                ++x_move;
            }
        }
        if (first==2)
        {
            if (y_move-3>0)
            {
                swi=1;
                --y_move;
            }
        }
        if (first==3)
        {
            if (y_move+3<y_size-1)
            {
                swi=1;
                ++y_move;
            }
        }
        while(check<3 && swi==1)
        {
            if (check==1)
            {
                door_chance=rand()%10;
                if (door_chance==9)
                {
                    if (first==0 || first==1)
                        maze_[x_size*y_move+x_move].square='|';
                    if (first==2 || first==3)
                        maze_[x_size*y_move+x_move].square='_';
                }
                else
                    maze_[x_size*y_move+x_move].square=' ';
            }
            else
            maze_[x_size*y_move+x_move].square=' ';
            start_end_loc.y_begin=y_move;
            start_end_loc.x_begin=x_move;
            ++check;
            if (check<3)
            {
                if (first==0)
                {
                    --x_move;
                }
                if (first==1)
                {
                    ++x_move;
                }
                if (first==2)
                {
                    --y_move;
                }
                if (first==3)
                {
                    ++y_move;
                }
            }
        }
        check=0;

        if (swi==1)
        {
            swi=0;
            ++counter_maze;
        }
    }
    return start_end_loc;
}
