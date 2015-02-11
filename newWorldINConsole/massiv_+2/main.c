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
    int array_1[mas_str][mas_col],number,str=2,col=6,check=0;
    printf ("Please enter some number:");
    scanf ("%d",&number);
    two_dimensional_array_input (array_1,str,col);
    printf ("Original array:\n");
    two_dimensional_array_output_int (array_1,str,col);
    printf("Choose: str-1,col-2\n");
    scanf("%d",&check);
    if (check==1)
    {
    number%=col;
    two_dimensional_array_sdvig_horizont (array_1,str,col,number);
    printf ("New array, sdvig:%d\n",number);
    two_dimensional_array_output_int (array_1,str,col);
    }
    else
    {
    number%=str;
    two_dimensional_array_sdvig_column (array_1,str,col,number);
    printf ("New array, sdvig:%d\n",number);
    two_dimensional_array_output_int (array_1,str,col);
    }

    return 0;
}
