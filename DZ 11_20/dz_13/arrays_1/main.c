#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
int array_1[10];

int main()
{
    int size=9,number;
    printf ("Please enter array elements:\n");
    array_input(size);
    array_output(size);
    printf ("\nPlease enter some number for search:\n");
    scanf("%d",&number);
    printf ("%d",array_search_Element (size,number));
    return 0;
}


