#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct process
{
    int number;
    int ask;
    int a;
    int b;
}proc;
void controller(int*,int*,int*,proc*);

int main()
{
    proc p_1,p_2,p_3;
    p_1.number=1;
    p_2.number=2;
    p_3.number=3;
    int buf_1[10],buf_2[10],check[3]/*Это массив переменных ограничителей*/,counter=0,counter_2=0,counter_3=0;
    while (counter<3)
    {
        check[counter]=0;
        ++counter;
    }
    counter=0;
    srand(time(NULL));
    //Потол_1
    while (counter<100)
    {
        p_1.a=rand()%10;
        p_1.b=rand()%10;
        p_1.ask=0;
        controller(buf_1,buf_2,check,&p_1);
        p_1.ask=1;
        controller(buf_1,buf_2,check,&p_1);
        p_1.ask=2;
        controller(buf_1,buf_2,check,&p_1);
        ++counter;
    }

    //Поток_2
    while (counter_2<100)
    {
        p_2.a=rand()%10;
        p_2.b=rand()%10;
        controller(buf_1,buf_2,check,&p_2);
        ++counter_2;
    }

    //Поток_3
    while (counter_3<100)
    {
        controller(buf_1,buf_2,check,&p_3);
        if (p_3.ask==3)
        printf ("\n%d %d\n",p_3.a,p_3.b);
        ++counter_3;
    }

    return 0;
}

//Контроллер
void controller(int*buf_1,int*buf_2,int*check,proc*task)
{
    int counter=0;
    if (task->ask==0 && task->number==1)
    {
        while (check[2]!=0)//Ожидание
        check[2]=1;
        buf_1[counter]=task->a;
        ++counter;
        buf_1[counter]=task->b;
        counter=0;
    }
    if (task->ask==1 && task->number==1)
    {
        while (check[1]!=1)//Ожидание
        task->a+=buf_2[counter];
        ++counter;
        task->b+=buf_2[counter];
        counter=0;
        check[1]=0;
    }
    if (task->ask==2 && task->number==1)
    {
        while (check[0]!=0)//Ожидание
        counter=2;
        buf_1[counter]=task->a;
        ++counter;
        buf_1[counter]=task->b;
        counter=0;
        check[0]=1;
    }
    if (task->number==2)
    {
        while (check[1]!=0)//Ожидание
        buf_2[counter]=task->a;
        ++counter;
        buf_2[counter]=task->b;
        counter=0;
        check[1]=1;
    }
    if (task->number==3)
    {
        while (check[0]!=1)//Ожидание
        counter=3;
        task->a=buf_1[counter]+buf_1[counter-1];
        counter-=2;
        task->b=buf_1[counter]+buf_1[counter-1];
        counter=0;
        task->ask=3;
        check[0]=0;
        check[2]=0;
    }
}
