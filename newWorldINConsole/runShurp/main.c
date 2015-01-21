#include <stdio.h>
#include <stdlib.h>
#include "../../modules/compatibility.h"

int main()
{
    int n=1000,position=0,adding=1;
    while (n)
    {
       for (int i=0;i<position; ++i)
       {
           printf(" ");
       }
       printf ("#\n");
       universalSleep(0.4);
       universalClear();

       if (position<0 || position>=40)
       {
           adding=-adding;
       }
       position+=adding;
       --n;
    }
    return 0;
}
