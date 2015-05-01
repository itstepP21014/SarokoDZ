#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task
{
    int a;
    int b;
    int counter;
    int ask;
}task;
typedef struct buf
{
    int a;
    int b;
    int counter;
    int empty;
}buf;
void controller(task*,buf*,buf*);

int main()
{
    srand(time(NULL));
    task proc_1,proc_2,proc_3;
    buf buf_1,buf_2;
    int counter=0;
    buf_1.empty=1;
    buf_2.empty=1;
    proc_1.counter=1;
    proc_2.counter=2;
    proc_3.counter=3;
    //
    while (counter<100)
    {
        //Поток 1
        proc_1.a=rand()%10;
        proc_1.b=rand()%10;
        controller(&proc_1,&buf_1,&buf_2);
        //Поток 2
        proc_2.ask=0;
        controller(&proc_2,&buf_1,&buf_2);
        proc_2.ask=1;
        proc_2.a+=rand()%5;
        proc_2.b+=rand()%5;
        controller(&proc_2,&buf_1,&buf_2);
        //Поток 3
        controller(&proc_3,&buf_1,&buf_2);
        ++counter;
    }
    return 0;
}


//Контроллер

void controller (task*proc,buf*buf_1,buf*buf_2)
{
    if (proc->counter==1 && buf_1->empty==1)
    {
        buf_1->empty=0;
        buf_1->a=proc->a;
        buf_1->b=proc->b;
    }
    if (proc->counter==2 && proc->ask==0 && buf_1->empty==0)
    {
        proc->a=buf_1->a;
        proc->b=buf_1->b;
        buf_1->empty=1;
    }
    if (proc->counter==2 && proc->ask==1 && buf_2->empty==1)
    {
        buf_2->empty=0;
        buf_2->a=proc->a;
        buf_2->b=proc->b;
    }
    if (proc->counter==3 && buf_2->empty==0)
    {
        proc->a=buf_2->a;
        proc->b=buf_2->b;
        buf_2->empty=1;
    }
}
