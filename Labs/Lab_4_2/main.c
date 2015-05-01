#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Реализовано через очередь.
typedef struct task
{
    int number;
    int time;
    int result;
}task;
void controller(task*);
void server(task*);

int main()
{
    task proc[5];
    srand(time(NULL));
    int counter=0,choise;
    counter=0;
    //Читатели
    while(counter<100)
    {
        choise=rand()%5;
        proc[choise].time=rand()%10;
        controller(&proc[choise]);
        ++counter;
    }
    return 0;
}

//Контроллер
void controller(task*proc)
{
    static task *array[100];
    static int counter=0,busy=0;
    array[counter]=proc;
    ++counter;
    if (busy==0)
    {
        busy=1;//Lock
        server(array[counter-1]);
        --counter;
        busy=0;//Unlock
    }
    else
    {
        printf ("\nPlease wait...\n");
    }
}
//Писатель
void server(task* proc)
{
    int arr[5],counter=0;
    while (counter<5)
    {
        proc->result+=arr[counter];
        ++counter;
    }
}
