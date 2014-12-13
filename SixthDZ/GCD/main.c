#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,result,residue;
    printf("Please enter two integers:\n");
    scanf ("%d",&a);
    scanf ("%d",&b);
    if (a>b)
    {
        while (residue!=0)
        {
         residue=a%b;
         a=b;
         result=b;
         b=residue;
        }

    }
    else
    {if (a<b)
    {
        while (residue!=0)
        {
         residue=b%a;
         b=a;
         result=a;
         a=residue;
        }
    }
    else
    {
     result=b;
    }
    }
    printf ("Greatest common divisor of two integers: %d",result);

    return 0;
}
