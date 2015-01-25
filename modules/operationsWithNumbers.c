#include <math.h>

int numberOfDigits(int number)
{
   int result=1,sum=0;
   while (result!=0)
   {
       result=number/10;
       number/=10;
       sum+=1;
   }
   return sum;
}


int firstNumber(int number)
{
   int result=1,result_1,copy=number,sum=0,degree,divider=10;
   while (result!=0)
   {
       result=number/10;
       number/=10;
       sum+=1;
   }
   degree=sum-1;
   if (degree==0)
   {
       divider=1;
   }
   else
   {
     while (degree>1)
    {
     divider*=10;
     --degree;
    }
   }
   result_1=copy%divider;
   return result_1;
}


int exceptFirst(int number)
{
   int result=1,result_1,copy=number,sum=0,degree,divider;
   while (result!=0)
   {
       result=number/10;
       number/=10;
       sum+=1;
   }
   degree=sum-1;
   divider=pow(10,degree);
   result_1=copy/divider;
   return result_1;
}

int plusDigit(int number,int digit)
{
   number*=10;
   number+=digit;
   return number;
}

int cycle(int number,int cycles)
{
    int result=1,result_1,result_2,copy=number,sum=0,degree,divider;
   while (cycles)
   {
    sum=0;
    while (result!=0)
    {
       result=number/10;
       number/=10;
       sum+=1;
    }
    degree=sum-1;
    divider=pow(10,degree);
    result_1=copy/divider;
    result=1;
    sum=0;
    number=copy;
    while (result!=0)
    {
       result=number/10;
       number/=10;
       sum+=1;
    }
    degree=sum-1;
    divider=pow(10,degree);
    result_2=copy%divider;
    copy=result_2;
    result=1;
    copy*=10;
    copy+=result_1;
    --cycles;
    number=copy;
    printf ("%d This is only a message from the function, i sorry about that.\n",copy);
   }
   return copy;
}


