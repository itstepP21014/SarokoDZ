#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,counter,a,b,c;
    printf("Please enter integer:\n");
    scanf ("%d",&n);
    printf ("Column Fibonacci numbers:\n");
    if (n==0)
    {
     printf("............");
    }
    else
    {
     a=1;
     printf("%d\n",a);
     b=0;

    for (counter=n-1;counter>0;--counter)
    {
     c=a+b;
     printf("%d\n",c);
     b=a;
     a=c;
    }
    }
    return 0;
}
