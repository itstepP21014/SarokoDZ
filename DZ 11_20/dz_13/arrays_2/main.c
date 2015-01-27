#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"
int array_1[20];

int main()
{
    int size;
    printf ("array has 20 elements\n");
    printf ("Please enter number of elements that will be used:\n");
    scanf("%d",&size);
    if (size>19 || size<0)
    {
        printf ("Bad size!");
        return 1;
    }
    int counter=size;
    while (counter)
    {
         array_1[counter]=randomS ();
        --counter;
    }
    printf ("Max:%d\n",array_search_Max (size));
    printf ("Min:%d\n",array_search_Min (size));
    return 0;
}
