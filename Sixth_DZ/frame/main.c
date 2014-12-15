#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h,counter,c=35,k;
    printf("Please enter width of the rectangle:\n");
    scanf ("%d",&w);
    printf("Please enter height of the rectangle:\n");
    scanf ("%d",&h);
    k=w*h;
    if (k==1)
    {
     printf("%c\n",c);
    }
    else if (k==w)
    {
     for (counter=w;counter>0;--counter)
     {
       printf("%c",c);
     }
      printf ("\n");
    }
    else if (k==h)
    {
     for (counter=h;counter>0;--counter)
     {
       printf("%c",c);
       printf ("\n");
     }
    }
    else
    {
    for (counter=w;counter>0;--counter)
     {
         printf("%c",c);
     }
     printf ("\n");
    h=h-2;

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
