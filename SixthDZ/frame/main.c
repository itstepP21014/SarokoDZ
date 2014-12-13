#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h,counter,c=35;
    printf("Please enter width of the rectangle:\n");
    scanf ("%d",&w);
    printf("Please enter height of the rectangle:\n");
    scanf ("%d",&h);
    h=h-2;
    if (w<2 && h<2)
    {
     printf("%c\n",c);
    }
    else
    {
    for (counter=w;counter>0;--counter)
     {
         printf("%c",c);
     }
     printf ("\n");


    while (h>0)
    {
        printf("%c",c);
      for (counter=w-2;counter>0;--counter)
      {
        printf(" ");
      }
        printf("%c\n",c);
        h-=1;

    }
    for (counter=w;counter>0;--counter)
     {
        printf("%c",c);
     }
     printf("\n");
    }

    printf ("Ready");
    return (0);
}
