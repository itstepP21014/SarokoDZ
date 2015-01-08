#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int cash1=1000,c1Copy,cash2=1000,months=0,rem1,rem2;
    c1Copy=cash1;
    printf("%d\t\t%d\n",cash1,cash2);
    while (cash2<=cash1)
    {
       rem1=(c1Copy*106)%100;
       cash1+=(c1Copy/100)*6;
       printf("%d$ %2d cent\t",cash1,rem1);
       rem2=(cash2*104)%100;
       cash2+=(cash2/100)*4;
       printf("%d$ %2d cent\n",cash2,rem2);
       months+=3;
    }
    printf("%d months\n",months);
    system("pause");
    return 0;
}
