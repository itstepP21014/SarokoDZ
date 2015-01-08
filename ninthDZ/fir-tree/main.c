#include <stdio.h>
#include <stdlib.h>

int main()
{
    int counter,counter1=1, foundation=3,foundationCopy1=3,foundationBegin=1,foundationCopy2=3,foundationCopy2C=1,anotherMainF=1,point1,point2,pointMain,shift=0,check=0,checkCopy=0;
    int point11,point22,shift1=0,c;
    printf ("Please enter number of storeys fir-three:\n");
    scanf("%d",&counter);
    while(counter!=counter1)
    {
        foundationCopy2+=2;
        counter1+=1;
    }
    while(counter)
    {
       pointMain=(foundationCopy2/2)+1;
       c=pointMain;
       while (pointMain>1)
       {
           printf(" ");
           --pointMain;
       }
       printf("*");
       pointMain=(foundationCopy2/2)+1;
       while (pointMain>1)
       {
           printf(" ");
           --pointMain;
       }
       printf("\n\n");
       while(checkCopy)
    {
       pointMain=(foundationCopy2/2)+1;
       shift+=1;
       point1=pointMain-shift;
       point2=pointMain+shift;
       while(foundationBegin<=foundationCopy2)
       {
          if (foundationBegin==point1 || foundationBegin==point2)
          {
              printf("*");
          }
          else
          {
              printf(" ");
          }
          ++foundationBegin;
       }
       foundationBegin=1;
       printf("\n\n");
        --checkCopy;
    }
       ++shift1;
       point11=c-shift1;
       point22=c+shift1;
       while (anotherMainF<=foundationCopy2)
       {
           if (anotherMainF>=point11 && anotherMainF<=point22)
           {
            printf("*");
           }
           else
           {
             printf(" ");
           }

           ++anotherMainF;
       }
       foundation+=2;
       foundationCopy1=foundation;
       foundationBegin=1;
       shift=0;
       printf("\n");
       ++check;
       checkCopy=check;
       --counter;
       anotherMainF=1;
    }
printf("\n");
shift=1;
point1=pointMain-shift;
point2=pointMain+shift;
counter=2;
while (counter)
{
   while(foundationCopy2C<=foundationCopy2)
 {
   if (foundationCopy2C==point1 || foundationCopy2C==point2)
   {
       printf("*");
   }
   else
    {
       printf(" ");
    }
    ++foundationCopy2C;
 }
 printf("\n\n");
 foundationCopy2C=1;
 --counter;
}
    printf("Ready!");
    system("pause");
    return 0;
}
