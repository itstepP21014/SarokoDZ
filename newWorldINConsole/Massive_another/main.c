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
    int first[mas_str][mas_col];
    int size=12;
    int str=4, col=3;
    two_dimensional_array_input (first,str,col);
    printf("Original array:\n");
    two_dimensional_array_output_int (first,str,col);
    int sCount=0,cCount=0,sCopy=0,cCopy=0,element;
    str-=1;
    col-=1;
    while (sCopy<=str)
    {
        element=first[sCopy][cCopy];
        sCount=sCopy;
        cCount=cCopy;
         while (sCount<=str)
         {
            if (first[sCount][cCount]<element)
          {
            first[sCopy][cCopy]=first[sCount][cCount];
            first[sCount][cCount]=element;
            element=first[sCopy][cCopy];
          }
          if (cCount<col)
                {
                    ++cCount;
                }
                else
                {
                    cCount=0;
                    ++sCount;
                }
          }
         if (cCopy<col)
        {
         ++cCopy;
        }
        else
        {
        cCopy=0;
        ++sCopy;
        }
    }
    ++str;
    ++col;
    printf("New array:\n");
    two_dimensional_array_output_int (first,str,col);
    return 0;
}
