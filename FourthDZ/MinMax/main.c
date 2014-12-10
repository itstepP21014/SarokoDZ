#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,nNumber,counter,result,a,b;
    printf("Please enter integer:\n");
    scanf ("%d",&n);
    printf("Please enter %d integers:\n",n);
    scanf("%d",&nNumber);
    if (n==1)
    {
     result=nNumber;
    }
    else
    {
     a=nNumber;
     scanf("%d",&nNumber);
     b=nNumber;
     result=(a>b)?a:b;
    }
    for (counter=n-2;counter>0;--counter)
    {
     scanf("%d",&nNumber);
     a=nNumber;
     result=(result>a)?result:a;
    }
     printf("Max=%d",result);

    return 0;
}
