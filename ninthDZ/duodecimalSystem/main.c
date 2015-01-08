#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number,resultOfTheDivision,resultOfTheDivisionCopy=1,residue1;
    int count=0,countChange,numberCopy2,var1;
    printf ("Please enter the integer you want to convert to a twelve-number system:\n");
    scanf("%d",&number);
    numberCopy2=number;
    while(numberCopy2)
 {
  ++count;
  numberCopy2=numberCopy2/10;
 }
    count+=10;
    countChange=count;
    printf("\n");
    while (resultOfTheDivisionCopy)
    {
       residue1=number%12;
       resultOfTheDivision=number/12;
       number=resultOfTheDivision;
       resultOfTheDivisionCopy=resultOfTheDivision;
           while (count)
           {
               printf(" ");
               --count;
           }
           --countChange;
           count=countChange;
           switch (residue1)
           {
           case 10:
               var1=65;
               printf("%c",var1);
               break;
           case 11:
               var1=66;
               printf("%c",var1);
               break;
           default:
               printf("%d",residue1);
               break;
           }
           printf ("\r");
    }
    printf ("Result:\n");
    system("pause");
    return 0;
}




