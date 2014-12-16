#include <stdio.h>
#include <stdlib.h>

int main()
{
   double x,x1,result=1.0;
   int n,n1;
   printf("Please enter double:\n");
   scanf("%lf",&x);
   x1=x;
   printf("Please enter integer degree:\n");
   scanf("%d",&n);
   n1=n;
    while (n!=0)
    {
       if (n%2!=0)
       {
        result*=x;
        n-=1;
       }
        x*=x;
        n/=2;
    }
    printf("Number %lf in degree %d:\n%lf\n",x1,n1,result);
	system ("pause");
    return (0);
}
