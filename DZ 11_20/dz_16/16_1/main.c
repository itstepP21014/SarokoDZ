#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"
#include "../../../modules/compatibility.h"

#define mas_col 100
#define mas_str 100
int main()
{
    char array [mas_str][mas_col];
    char element='#',xin='x';
    int str=3,col=3,swi=1,counter=0,c_1,c_2;
    two_dimensional_array_input_elements (array,str,col,element);
    two_dimensional_array_output (array,str,col);
    printf("\n\n");
    printf("\n");
    while (swi)
    {
     scanf ("%d",&c_1);
     scanf ("%d",&c_2);
     two_dimensional_array_input_one_element_char(array,c_1,c_2,xin);
     ++counter;
     universalClear();
     two_dimensional_array_output (array,str,col);
     system ("pause");
     if (check_win_x0 (array,str,col)==1)
     {
        printf("You win!\n");
        system ("pause");
        return 1;
     }
     if (counter==9)
     {
         printf("draw...\n");
         system ("pause");
         exit (1);
     }
     two_dimensional_array_x0_reaction (array,str,col);
     universalClear();
     ++counter;
     two_dimensional_array_output (array,str,col);
     system ("pause");
     if (check_win_x0 (array,str,col)==0)
     {
        printf("You lose!\n");
        system ("pause");
        return 1;
     }
     if (counter==9)
     {
         printf("draw...\n");
         system ("pause");
         exit (1);
     }
    }
    return 0;
}
