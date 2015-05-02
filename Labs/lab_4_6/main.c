#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

//Организовано через общую память

int main()
{
    int size;
    scanf ("%d",&size);
    int buf_[size],counter=0,counter_2=0,counter_3=0,count_real=0,swi_real=0,swi_r_main=0;
    int *buf=buf_,*swi=&swi_real,*swi_2=&swi_r_main,*count=&count_real,cycle_count=0,counter_r_main=0;
    srand(time(NULL));
    //Процесс 1
    while (counter<100)
    {
        *swi_2=0;
        for (cycle_count=size/50;cycle_count<100;++cycle_count)
        {
            buf[*count]=rand()%10;
            if (*count<size)
            ++(*count);
            else
            *count=0;
        }
        *swi_2=1;
        Sleep(1);
        *swi=1;
        while(*swi!=0);
        ++counter;
    }
    //Процесс 2
    while (counter_2<100)
    {
        *swi_2=0;
        for (cycle_count=size/50;cycle_count<100;++cycle_count)
        {
            buf[*count]=rand()%10;
            if (*count<size)
            ++(*count);
            else
            *count=0;
        }
        *swi_2=1;
        Sleep(1);
        *swi=0;
        ++counter_2;
    }
    //Главный процесс
    while(counter_3<100)
    {
        while (*swi_2==0)
        for (cycle_count=size/50;cycle_count<100;++cycle_count)
        {
            printf("%d\n",buf[counter_r_main]);
            if (counter_r_main<size)
            ++counter_r_main;
            else
            counter_r_main=0;
            if (*swi_2==0)
            cycle_count=100;
        }
        ++counter_3;
    }
    return 0;
}
