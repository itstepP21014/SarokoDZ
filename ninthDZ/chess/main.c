#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,w1,h,counter=1,count;
    count=counter;
    printf("Please enter width and height:\n");
    scanf("%d %d",&w,&h);
    w1=w;
    while (h)
    {
        while (w)
        {
          if (counter%2>0)
          {
             printf ("*");
             ++counter;
          }
          else
          {
              printf (" ");
              ++counter;
          }
          --w;
        }
        w=w1;
        --h;
        ++count;
        counter=count;
        printf ("\n");
    }
    system ("pause");
    return 0;
}
