#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,d,sum=0,sum1=0,digit,number1,num1,mediator;
    printf("Please enter integer (must be >0:\n");
    scanf("%d",&number);
    mediator=number;
    number1=mediator;
    d=10;
    while (number!=0)
    {
      digit=number%d;
      number-=digit;
      sum+=digit;
      if (number!=0)
      {
          number=number/d;
      }
      else
      {
          printf ("Sum1=%d\n",sum);
      }
    }
    printf ("........................\n");
    while (sum1!=sum)
   {
    sum1=0;
    number1+=1;
    num1=number1;
    while (num1!=0)
    {
      digit=num1%d;
      num1-=digit;
      sum1+=digit;
      if (num1!=0)
      {
          num1=num1/d;
      }
      else
      {
          printf ("Sum2=%d\t",sum1);
      }
    }
   }
   printf ("\n");
   printf (" The next integer number with this sum of digits: %d\n",number1);
    system("pause");
    return 0;
}
