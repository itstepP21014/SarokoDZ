#include <stdio.h>
#include <stdlib.h>
//По неизвестной мне причине всегда выдает ноль, как результат.

int main()
{
    int number,degree,counter;
    double result;
    printf ("Please enter integer:");
    scanf ("%d",&number);
    printf ("Please enter integer degree:");
    scanf ("%d",&degree);
    if (number==0)
    {
     result=0;
    }
    else
    {
    if (degree==0)
    {
     result=1;
    }
    else
    {
     result=number;
     for (counter=degree-1;counter>0;--counter)
     {
      result*=result;
     }
;   }
    }
    if (degree<0)
    {
     printf ("Number %d v in degree %d is equal to: %lf",number,degree,1/result);
    }
    else
    {
     printf ("Number %d v in degree %d is equal to: %d",number,degree,result);
    }
    return 0;
}
