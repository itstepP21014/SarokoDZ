#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/numbers.h"
#include "../../../modules/compatibility.h"

void safe(int number);

int main()
{
    int number;
    printf("Please enter an integer:\n");
    scanf("%d",&number);
    safe(number);
    return 0;
}

void safe(int number)
{
   int digits,digCopy,digCopy_1,dCopy,numberNew,newCopy,paste,pasteCopy,cy=1,degree,degCopy,degree_1=0,degree_1Copy,dCopy_1,n1,n2,n3,n4;
   double delay=0.5;
   digits=numberOfDigits(number);
   digCopy=digits-1;
   digCopy_1=digCopy;
   degree=digits-1;
   dCopy=digits-1;
   n2=dCopy;
   dCopy_1=dCopy;
   numberNew=firstNumber(number);
   paste=exceptFirst(number);
   pasteCopy=paste;
   while (dCopy)
   {
     numberNew=cycle(numberNew,cy);
     newCopy=numberNew;
     while (digCopy)
     {
         paste*=10;
         --digCopy;
     }
     digCopy=digCopy_1;
     numberNew+=paste;
     paste=pasteCopy;
     printf("%d\n",numberNew);
     if (degree==0)
     {
         printf ("!number has only one digit!\n");
     }
     else
     {
         degCopy=degree;
         n4=10;
         while (degree>1)
         {
             n4*=10;
             --degree;
         }
     }
     degree=degCopy;
     numberNew%=n4;
     universalSleep(delay);
     while (dCopy_1)
     {
         degree_1Copy=degree_1;
         if (degree_1==0)
         {
             n3=1;
         }
         else
         {
          n3=10;
          while (degree_1>1)
          {
              n3*=10;
              --degree_1;
          }
         }
       degree_1=degree_1Copy;
       n1=numberNew%n3;
       numberNew-=n1;
       numberNew*=10;
       numberNew+=(n3*paste);
       numberNew+=n1;
       if (dCopy_1==dCopy && dCopy==n2)
       {
          number=numberNew;
       }
       printf("%d\n",numberNew);
       universalSleep(delay);
       degree_1+=1;
       --dCopy_1;
       numberNew=newCopy;
     }
     degree_1=0;
     dCopy_1=n2;
     --dCopy;
   }
   safe(number);
}

