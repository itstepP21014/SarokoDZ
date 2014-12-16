#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Diagonal,n,n1,a,b,c,counter,d;
    printf ("Please enter diagonal (diagonal%%2 must be !=0):\n");
    scanf ("%d",&Diagonal);
    d=Diagonal;
    n=(Diagonal-1)/2;
    n1=Diagonal-(2*n);
    for(counter=(d/2)+1;counter>0;--counter)
    {
        a=n;
        b=n;
        c=n1;
     while (a!=0)
     {
         printf(" ");
         a-=1;
     }
     while (c!=0)
     {
         printf("#");
         c-=1;
     }
     while (b!=0)
     {
         printf(" ");
         b-=1;
     }
     printf ("\n");
     n-=1;
     n1=Diagonal-(2*n);
    }
     n=1;
     n1=Diagonal-(2*n);
    //................................................
    for(counter=d/2;counter>0;--counter)
    {
     a=n;
     b=n;
     c=n1;
     while (a!=0)
     {
         printf(" ");
         a-=1;
     }
     while (c!=0)
     {
         printf("#");
         c-=1;
     }
     while (b!=0)
     {
         printf(" ");
         b-=1;
     }
     printf ("\n");
     n+=1;
     n1=Diagonal-(2*n);
    }
    printf ("Ready..........\n");
    system ("pause");
    return 0;
}
