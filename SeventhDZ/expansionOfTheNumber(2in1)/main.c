#include <stdio.h>
#include <stdlib.h>

int main()
{
   int number,counter,number1,result,count,c,n;
   printf("Please enter integer >=2:\n");
   scanf("%d",&number);
   number1=number/2;
   if (number==2 || number==3)
   {
      printf("This is prime number\n");
      printf ("%d=%d",number,number);
   }
   else
   {
       counter=2;
       while (result!=0 && counter<=number1)
    {
       result=number%counter;
       count=counter;
       counter+=1;
    }
     if (result!=0)
     {
       printf ("This is prime number\n");
       printf ("%d=%d",number,number);
     }
     else
     {
      c=number/count;
      printf("This is not prime number\n");
      printf ("%d=%d",number,count);
      //..............................
     while (n!=1)
     {
      result=1;
      number1=c/2;
        if (c==2 || c==3)
   {
      n=1;
      printf ("*%d",c);
   }
   else
   {
       counter=2;
       while (result!=0 && counter<=number1)
    {
       result=c%counter;
       count=counter;
       counter+=1;
    }
     if (result!=0)
     {
       n=1;
       printf ("*%d",c);
     }
     else
     {
       c=c/count;
       printf ("*%d",count);
     }
   }
     }
     }
   }
       //....................
    printf("\n");
	system ("pause");
    return (0);
}
