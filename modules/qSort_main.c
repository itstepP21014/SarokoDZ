#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int reverse_sort(const void *a, const void *b)
{
     return *(int*)b - *(int*)a;
}


int sum_of_digits (const void*a,const void*b)
{
    int p_1=0,p_2=0;
    int *x=&p_1,*y=&p_2,sum_1=0,sum_2=0;
    *x=*(int*)a;
    *y=*(int*)b;
while (*x>0)
{
    sum_1+=(*x%10);
    *x/=10;
}
while (*y>0)
{
    sum_2+=(*y%10);
    *y/=10;
}
if (sum_1==sum_2)
return 0;
if (sum_1>sum_2)
return 1;
if (sum_1<sum_2)
return -1;
}


int number_of_divisors (const void*a,const void*b)
{
    int p_1=0,p_2=0,counter=0;
    int *x=&p_1,*y=&p_2,sum_1=0,sum_2=0;
    *x=*(int*)a;
    *y=*(int*)b;
    counter=sqrt(*x);
    while (counter>0)
    {
        if (*x%counter==0)
        ++sum_1;
        --counter;
    }
    counter=sqrt(*y);
    while (counter>0)
    {
        if (*x%counter==0)
        ++sum_2;
        --counter;
    }
if (sum_1==sum_2)
return 0;
if (sum_1>sum_2)
return 1;
if (sum_1<sum_2)
return -1;
}
