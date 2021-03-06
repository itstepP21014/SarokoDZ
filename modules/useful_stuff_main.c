#include "useful_stuff.h"

void maze_generator(char*maze,int y_size,int x_size)
{

    srand(time(NULL));
    int first=0,second=0,x_enter,y_enter,right_left,y_move,x_move,counter_maze=0,counter,swi=0,check=0,count;

    while (first<y_size)
    {
        while (second<x_size)
        {
            maze[x_size*first+second]='#';
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
    maze[x_size*y_enter+x_enter]=' ';

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
    maze[x_size*y_move+x_move]=' ';
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
        maze[x_size*y_move+x_move]=' ';
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
}

void graf_deep(int *matrix,int vertices,int *tops)
{
    int swi=1,second=0,first=0,counter=0;
        while (swi)
        {
            while (swi)
            {
                while (matrix[first*vertices+second]!=1)
                {
                    ++second;
                }
                if (tops[second]==1)
                {
                    printf("%d ",second+1);
                    tops[second]=0;
                    swi=0;
                }
                else
                ++second;
            }
            swi=1;
            first=second;
            second=0;
            while (counter<vertices)
            {
                if (tops[counter]==1)
                swi=2;
                ++counter;
            }
            counter=0;
            if (swi==1)
            swi=0;
        }
}

void graf_width(int *matrix,int vertices,int *result)
{
    int swi=1,second=0,first=0,counter=0,begin=0,end=1,counter_2=0,v_copy=vertices-1;
        while (swi)
        {
            while (second<vertices)
            {
                while (matrix[first*vertices+second]!=1)
                {
                    ++second;
                }
                while (counter<vertices)
                {
                    if (result[counter]==second+1)
                    swi=2;
                    ++counter;
                }
                counter=0;
                if (matrix[first*vertices+second]==1 && swi==1)
                {
                    result[counter_2]=second+1;
                    ++end;
                    printf("%d ",second+1);
                    ++counter_2;
                    --v_copy;
                }
                else
                ++second;
                swi=1;
            }
            first=result[begin];
            ++begin;
            second=0;
            if (v_copy==0)
            swi=0;
        }
}

int UTF8_count_symbols(char*UTF8)
{
  int counter=0,result,counter_symbols=0;

    while (UTF8[counter]!='\0')
    {
        result=return_symbol_number(UTF8,counter);
        if (result<8 && result>-1)
        {
            ++counter_symbols;
            result=-1;
            counter+=2;
        }
        if (result==12 || result==13)
        {
            ++counter_symbols;
            result=-1;
            counter+=4;
        }
        if (result==14)
        {
            ++counter_symbols;
            result=-1;
            counter+=8;
        }
        if (result==15)
        {
            ++counter_symbols;
            ++counter;
            result=return_symbol_number(UTF8,counter);
            if (result<8)
            {
                counter+=10;
            }
            if (result>7 && result<12)
            {
                counter+=13;
            }
            if (result>11)
            {
                counter+=16;
            }
        }
        if (UTF8[counter]!='\0')
            ++counter;
    }
    return counter_symbols;
}

void UTF8_codes_of_symbols(char*UTF8)
{
  int counter=0,result,code_int=0;
  char code[10];

    while (UTF8[counter]!='\0')
    {
        code_int=0;
        result=return_symbol_number(UTF8,counter);
        if (result<8 && result>-1)
        {
            code[0]=UTF8[counter];
            code[1]=UTF8[counter+1];
            printf("U+%c%c ",code[0],code[1]);
            result=-1;
            counter+=3;
        }
        if (result==12 || result==13)
        {
            result-=12;
            code_int=pow(16,3);
            ++counter;
            result=return_symbol_number(UTF8,counter);
            code_int+=result*pow(16,2);
            counter+=2;
            result=return_symbol_number(UTF8,counter);
            result-=8;
            code_int+=result*pow(16,1);
            ++counter;
            result=return_symbol_number(UTF8,counter);
            code_int+=result*pow(16,0);
            printf("U+%X ",code_int);
            result=-1;
            counter+=2;
        }
        if (result==14)
        {
            ++counter;
            result=return_symbol_number(UTF8,counter);
            code_int+=result*pow(16,4);
            counter+=2;
            result=return_symbol_number(UTF8,counter);
            result-=8;
            code_int+=result*pow(16,3);
            ++counter;
            result=return_symbol_number(UTF8,counter);
            code_int+=result*pow(16,2);
            counter+=2;
            result=return_symbol_number(UTF8,counter);
            result-=8;
            code_int+=result*pow(16,1);
            ++counter;
            result=return_symbol_number(UTF8,counter);
            code_int+=result*pow(16,0);
            printf("U+%X ",code_int);
            result=-1;
            counter+=2;
        }
        if (result==15)
        {
            ++counter;
            result=return_symbol_number(UTF8,counter);
            if (result<8)
            {
                code_int+=result*pow(16,6);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,5);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,4);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,3);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,2);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,1);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,0);
                printf("U+%X ",code_int);
                result=-1;
                counter+=2;
            }
            if (result>7 && result<12)
            {
                result-=8;
                code_int+=result*pow(16,8);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,7);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,6);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,5);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,4);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,3);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,2);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,1);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,0);
                printf("U+%X ",code_int);
                result=-1;
                counter+=2;
            }
            if (result>11)
            {
                result-=12;
                code_int+=result*pow(16,10);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,9);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,8);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,7);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,6);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,5);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,4);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,3);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,2);
                counter+=2;
                result=return_symbol_number(UTF8,counter);
                result-=8;
                code_int+=result*pow(16,1);
                ++counter;
                result=return_symbol_number(UTF8,counter);
                code_int+=result*pow(16,0);
                printf("U+%X ",code_int);
                result=-1;
                counter+=2;
            }
        }
    }
}

int return_symbol_number(char*UTF8,int counter)
{
             switch (UTF8[counter])
            {
                case '0':
                return 0;
                break;
                case '1':
                return 1;
                break;
                case '2':
                return 2;
                break;
                case '3':
                return 3;
                break;
                case '4':
                return 4;
                break;
                case '5':
                return 5;
                break;
                case '6':
                return 6;
                break;
                case '7':
                return 7;
                break;
                case '8':
                return 8;
                break;
                case '9':
                return 9;
                break;
                case 'A':
                return 10;
                break;
                case 'B':
                return 11;
                break;
                case 'C':
                return 12;
                break;
                case 'D':
                return 13;
                break;
                case 'E':
                return 14;
                break;
                case 'F':
                return 15;
                break;
                default:
                return -1;
                break;
            }
}
