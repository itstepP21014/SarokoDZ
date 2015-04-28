#include <stdio.h>
#include <stdlib.h>
#include "../../modules/Arrayss.h"
#include "../../modules/funcRand.h"
#include "../../modules/compatibility.h"

#define size_max 1000
#define mas_col 30
#define mas_str 30

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
    two_dimensional_array_sdvig_column (&array_1[0][0],str,col,number);
    printf ("New array, sdvig:%d\n",number);
    two_dimensional_array_output_int (array_1,str,col);
    }
    int sCount=0,cCount=0;
    while (sCount<str)
    {
       switch (array_1[sCount][cCount])
       {
       case 12:
       case 11:
       case 10:
       array_1[sCount][cCount]=5;
       break;
       case 9:
       case 8:
       case 7:
       array_1[sCount][cCount]=4;
       break;
       case 6:
       case 5:
       case 4:
       array_1[sCount][cCount]=3;
       break;
       case 3:
       case 2:
       case 1:
       array_1[sCount][cCount]=2;
       break;
       default:
       printf("error!");
       exit (1);
       }
      if (cCount<=(col-1))
      ++cCount;
      else
      {
          cCount=0;
          ++sCount;
      }

    }
    printf ("Array with system 2-5:");
    two_dimensional_array_output_int (array_1,str,col);
    return 0;
}
