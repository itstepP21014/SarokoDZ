#include <stdio.h>
#include <stdlib.h>
#include "../../modules/Arrayss.h"
#include "../../modules/funcRand.h"
#include "../../modules/compatibility.h"

#define size_max 1000
#define mas_col 10
#define mas_str 10

int main()
{
    int array_1[mas_str][mas_col],number,str=2,col=6;
    printf ("Please enter some number:");
    scanf ("%d",&number);
    number%=col;
    two_dimensional_array_input (array_1,str,col);
    printf ("Original array:\n");
    two_dimensional_array_output_int (array_1,str,col);
    two_dimensional_array_sdvig (array_1,str,col,number);
    printf ("New array, sdvig:%d\n",number);
    two_dimensional_array_output_int (array_1,str,col);
    return 0;
}
