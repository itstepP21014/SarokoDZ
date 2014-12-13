#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h,counter,c=42;
    printf("Please enter width of the rectangle:\n");
    scanf ("%d",&w);
    printf("Please enter height of the rectangle:\n");
    scanf ("%d",&h);

    while (h!=0)
    {
        {
         for (counter=w;counter!=0;--counter)
     {
         printf("%c",c);
     }
         printf("\n");
         h-=1;
        }

    }
    printf ("Ready");
    return (0);
}
