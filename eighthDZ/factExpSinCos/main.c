#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x=-2.0,x1b,error=100.0,x1=0.0,dif,m,m1,factorial1,count,eps1=0.001,d;
    int counter,n1=1,counter1,factorial,n=1,c,c1;
    printf("Please enter integer (the factorial):\n");
    scanf ("%d",&factorial);
    counter=factorial;
    printf("%d!=1",factorial);
    factorial=1;
    while (counter>1)
    {
       n1=(n1+1);
       printf("*%d",n1);
       factorial*=n1;
       --counter;
    }
    printf("=%d\n",factorial);
    //....................................
    printf("calculate exponential with eps 0,001:\n");
    d=eps1;
    printf("Number\t\tOur\t\tLibrary\t\tThe Difference\n");
    factorial1=1.0;
    n=0.0;
    m1=1.0;
    counter=2;
    for (counter1=41;counter1>0;--counter1)
    {
     x1=0.0;
     factorial=1.0;
     printf("%lf\t",x);
     x1b=exp(x);
     n=0;
     d=eps1;
     while (d>=eps1)
     {
       m=pow(x,n);
       m1=m/factorial;
       d=fabs(m1);
       x1+=m1;
     while (counter>1)
     {
       n+=1;
       factorial*=n;
       --counter;
     }
       counter=2;
     }
     if (x1<0.0)
     {
         x1=-1.0/x1;
     }
       printf("%lf\t",x1);
       printf("%lf\t",x1b);
       dif=fabs(x1-x1b);
       printf("%lf\n",dif);
       x+=0.1;
    }
    //......................
    printf("calculate sine with eps 0,001:\n");
    printf("Number\t\tOur\t\tLibrary\t\tThe Difference\n");
    x=-2.0;
    m1=1.0;
    for (counter1=41;counter1>0;--counter1)
    {
     x1=0.0;
     factorial=1.0;
     printf("%lf\t",x);
     x1b=sin(x);
     n=0;
     c1=1;
     d=eps1;
     counter=3;
     while (d>=eps1)
     {
       c=(2*n)+1;
       m=pow(-1,n)*pow(x,c);
       m1=m/factorial;
       d=fabs(m1);
       x1+=m1;
     while (counter>1)
     {
       c1+=1;
       factorial*=c1;
       --counter;
     }
       n+=1;
       counter+=2;
     }
       printf("%lf\t",x1);
       printf("%lf\t",x1b);
       dif=fabs(x1-x1b);
       printf("%lf\n",dif);
       x+=0.1;
    }
    //.............................
    printf("calculate cosine with eps 0,001:\n");
    printf("Number\t\tOur\t\tLibrary\t\tThe Difference\n");
    x=-2.0;
    m1=1.0;
    for (counter1=41;counter1>0;--counter1)
    {
     x1=0.0;
     factorial=1.0;
     printf("%lf\t",x);
     x1b=cos(x);
     n=0;
     c1=1;
     d=eps1;
     counter=2;
     while (d>=eps1)
     {
       c=2*n;
       m=pow(-1,n)*pow(x,c);
       m1=m/factorial;
       d=fabs(m1);
       x1+=m1;
     while (counter>1)
     {
       c1+=1;
       factorial*=c1;
       --counter;
     }
       n+=1;
       counter=3;
     }
       printf("%lf\t",x1);
       printf("%lf\t",x1b);
       dif=fabs(x1-x1b);
       printf("%lf\n",dif);
       x+=0.1;
    }
    system("pause");
    return 0;
}
