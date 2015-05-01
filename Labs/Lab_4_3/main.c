#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct variables
{
    int var;
    int lock;
}var_;

void controller(var_*,int*,int*counter);
void eating(int,int,var_*);

int main()
{
    srand(time(NULL));
    int counter,count=0,number;
    scanf("%d",&counter);
    var_ *array=malloc(sizeof(var_)*counter);
    while (count<counter)
    {
        array[count].lock=0;
        ++count;
    }
    count=100;

    //Генерация запросов от философов
    while (count>0)
    {
        number=rand()%5;
        controller(array,&number,&counter);
        --count;
    }
    free (array);
    return 0;
}

//Контроллер
void controller(var_*array,int*number,int*counter)
{
    int second;
    if (number+1>=counter)
    second=0;
    else
    second=*counter+1;
    if (array[*number].lock==0 && array[second].lock==0)
    {
        array[*number].lock=1;//Lock
        array[second].lock=1;
        eating(*number,second,array);
        array[*number].lock=0;//Unlock
        array[second].lock=0;
    }
}

//Процесс (философ) выполняет некоторые действия над переменными (ест).
void eating(int left,int right,var_* array)
{
    array[left].var+=6;
    array[right].var-=3;
}
