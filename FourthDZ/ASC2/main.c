#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int counter;
   int line=0;
   printf ("table ASC2\n");
   for (counter=0;counter<128;++counter)
   {
    line+=1;
    if (line==17)
    {
    line=0;
    printf ("\n");
    printf ("%c\t",counter);
    }
    else
    {
    printf ("%c\t",counter);
    }
   }

return(0);
}
