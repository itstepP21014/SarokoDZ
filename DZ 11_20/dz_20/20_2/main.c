#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/numbers.h"
#include "../../../modules/string_func.h"
#include "../../../modules/structs.h"

#define SIZE_MAX 1000

int main()
{
    FILE *file;
    int counter=0,counter_1=0,counter_2=0,time=0,swi=1,proc_sum,time_min=0,mark,time_period=5,number_copy=0,proc_s_copy;
    process stack[SIZE_MAX],perfomance[SIZE_MAX];
    int time_per=0,processor=0;
    while(counter<SIZE_MAX)
    {
        perfomance[counter].time_lenght=0;
        perfomance[counter].number=0;
        perfomance[counter].time_coming=0;
        ++counter;
    }
    counter=0;
    while (counter!=1 && counter!=2)
    {
        printf ("FCFS(1) or round robin(2):\n");
        scanf ("%d",&counter);
        fflush(stdin);
    }

    if (counter==1)
    {
        counter=0;
        file=fopen("tasks.txt","r");
        if (file==0)
        {
            printf("Cant open file!\n");
            return 1;
        }
        fscanf(file,"%d",&proc_sum);
        if (proc_sum>SIZE_MAX)
        {
            printf ("Error! Too many tasks!\n");
            exit (5);
        }
        proc_s_copy=proc_sum;
        printf ("counter:%d\n",proc_sum);
        while (counter_1<=(proc_sum-1) && counter_1<11)
        {
            fscanf(file,"\r\n%d %d %d",&stack[counter_1].number,&stack[counter_1].time_coming,&stack[counter_1].time_lenght);
            printf ("p_1:%d %d %d\n",stack[counter_1].number,stack[counter_1].time_coming,stack[counter_1].time_lenght);
            ++counter_1;
        }
        counter_1=0;
        fclose(file);

        while (swi)
        {
            ++time;
            while (counter_1<proc_sum)
            {
                while (counter_1<proc_sum && stack[counter_1].time_coming!=time)
                {
                    ++counter_1;
                }
                if (stack[counter_1].time_coming==time)
                {
                    while (swi>0)
                    {
                        if (perfomance[counter].time_lenght==0)
                        {
                            swi=-1;
                            perfomance[counter]=stack[counter_1];
                        }
                        ++counter;
                    }
                    ++counter_1;
                }
            }
            swi=1;
            counter=0;
            counter_1=0;

        if (processor==0)
        {
            while(counter_2<proc_sum)
            {
                if (swi==1)
                {
                    time_min=perfomance[counter_2].time_coming;
                    mark=counter_2;
                    swi=2;
                }
                if (time_min>perfomance[counter_2].time_coming && perfomance[counter_2].time_coming!=0)
                {
                    time_min=perfomance[counter_2].time_coming;
                    mark=counter_2;
                }
                ++counter_2;
            }
            swi=1;
            counter_2=0;
            if (time_min!=0)
            {
                processor=perfomance[mark].number;
                time_per=perfomance[mark].time_lenght;
                perfomance[mark].time_coming=0;
                perfomance[mark].time_lenght=0;
                perfomance[mark].number=0;
            }
            time_min=0;
        }
        else
        {
            --time_per;
            if (time_per==0)
            {
                --proc_sum;
                processor=0;
            }
        }

        printf ("processor:%d time_perfomance_proc:%d\nstack_of_tasks:\n",processor,time_per);
        while (counter_1<proc_s_copy)
        {
            printf("%d ",perfomance[counter_1].number);
            ++counter_1;
        }
        counter_1=0;
        printf("\n");
        system("pause");

        if (processor==0 && proc_sum==0)
        {
            swi=0;
            return 1;
        }
    }
    }
    else
    {
        counter=0;
        file=fopen("tasks.txt","r");
        if (file==0)
        {
            printf("Cant open file!\n");
            return 1;
        }
        fscanf(file,"%d",&proc_sum);
        if (proc_sum>SIZE_MAX)
        {
            printf ("Error! Too many tasks!\n");
            exit (5);
        }
        proc_s_copy=proc_sum;
        printf ("counter:%d\n",proc_sum);
        while (counter_1<=(proc_sum-1) && counter_1<11)
        {
            fscanf(file,"\r\n%d %d %d",&stack[counter_1].number,&stack[counter_1].time_coming,&stack[counter_1].time_lenght);
            printf ("p_1:%d %d %d\n",stack[counter_1].number,stack[counter_1].time_coming,stack[counter_1].time_lenght);
            ++counter_1;
        }
        counter_1=0;
        fclose(file);

        while (swi)
        {
            ++time;
            while (counter_1<proc_sum)
            {
                while (counter_1<11 && stack[counter_1].time_coming!=time)
                {
                    ++counter_1;
                }
                if (stack[counter_1].time_coming==time)
                {
                    while (swi>0)
                    {
                        if (perfomance[counter].time_lenght==0)
                        {
                            swi=-1;
                            perfomance[counter]=stack[counter_1];
                        }
                        ++counter;
                    }
                    ++counter_1;
                }
            }
            swi=1;
            counter=0;
            counter_1=0;

        if (processor==0 || time_period==0)
        {
            time_period=5;
            if (processor!=0)
            {
                while(counter_2<proc_sum && perfomance[counter_2].time_lenght!=0)
                {
                    ++counter_2;
                }
                perfomance[counter_2].time_lenght=time_per;
                perfomance[counter_2].time_coming=time;
                perfomance[counter_2].number=number_copy;
                counter_2=0;
            }
            while(counter_2<proc_sum)
            {
                if (swi==1)
                {
                    time_min=perfomance[counter_2].time_coming;
                    mark=counter_2;
                    swi=2;
                }
                if (time_min>perfomance[counter_2].time_coming && perfomance[counter_2].time_coming!=0)
                {
                    time_min=perfomance[counter_2].time_coming;
                    mark=counter_2;
                }
                ++counter_2;
            }
            swi=1;
            counter_2=0;
            if (time_min!=0)
            {
                processor=perfomance[mark].number;
                time_per=perfomance[mark].time_lenght;
                number_copy=perfomance[mark].number;
                perfomance[mark].time_coming=0;
                perfomance[mark].time_lenght=0;
                perfomance[mark].number=0;
            }
            time_min=0;
        }
        else
        {
            --time_per;
            --time_period;
            if (time_per==0)
            {
                --proc_sum;
                processor=0;
            }
        }

        printf ("processor:%d time_perfomance_proc:%d time_period:%d\nstack_of_tasks:\n",processor,time_per,time_period);
        while (counter_1<proc_s_copy)
        {
            printf("%d ",perfomance[counter_1].number);
            ++counter_1;
        }
        counter_1=0;
        printf("\n");
        system("pause");

        if (processor==0 && proc_sum==0)
        {
            swi=0;
            return 1;
        }
    }
    }

    return 0;
}
