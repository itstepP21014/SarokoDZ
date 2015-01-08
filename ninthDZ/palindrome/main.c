#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number,numberCopy1,numberCopy2,numberCopy3,check,count=0,countCopy=0,top,divider2,digitB=0,digitT=0,swi=1;
    printf("Please enter some integer:\n");
    scanf("%d",&number);
    numberCopy1=number;
    numberCopy2=number;
    numberCopy3=number;
    while (number)
    {
        number=number/10;
        ++count;
    }
    countCopy=count;
    if (count==1)
    {
        printf("Number %d is palindrome\n",numberCopy1);
    }
    else
    if (count%2!=0)
    {
      count-=1;
    }

      top=countCopy-1;
      check=count/2;
      while (check && swi)
      {
         digitB=numberCopy2%10;
         numberCopy2=numberCopy2/10;
         divider2=pow(10,top);
         digitT=numberCopy3/divider2;
         numberCopy3=numberCopy3-(divider2*digitT);
         --top;
         --check;
         if (digitB!=digitT)
         {
             swi=0;
         }
      }
      if (swi)
      {
        printf("Number %d is palindrome\n",numberCopy1);
      }
      else
      {
        printf("Number %d is not palindrome\n",numberCopy1);
      }

    system("pause");
    return 0;
}
