#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,result,residue;
    printf("Please enter two integers:\n");
    scanf ("%d",&a);
    scanf ("%d",&b);
    if (a>b)
    {
        c=a;
        while (residue!=0)
        {
         result=a;
         residue=a%b;
         a+=c;
        }

    }
    else
    {if (a<b)
    {
        c=b;
        while (residue!=0)
        {
         result=b;
         residue=b%a;
         b+=c;
        }
    }
    else
    {
     result=b;
    }
    }
    printf ("Least common multiple of two integers: %d",result);

    return 0;
}

