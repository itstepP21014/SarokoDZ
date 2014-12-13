#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=40,counter;
    float goldenSection1,goldenSection2,a,b,c;
    printf ("Column Fibonacci numbers:\n");
    printf("For follow-up to the previous\t");
    printf("Attitude previous to next\n");
     a=1.0;
     b=0.0;
    for (counter=n-1;counter>0;--counter)
    {
     c=a+b;
     goldenSection1=c/a;
     goldenSection2=a/c;
     printf("%f\t\t\t\t",goldenSection1);
     printf("%f\n",goldenSection2);
     b=a;
     a=c;
    }
    return 0;
}
