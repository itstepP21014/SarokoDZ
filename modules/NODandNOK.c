#include "mathx.h"
int NOD(int a, int b)
{
    int c;
    if (a==0)
    {
        return b;
    }
    else
    {
        if (b==0)
        {
          return a;
        }
        else
        {
          if (b==a && a==0)
          {
           c=1;
           return c;
          }
          else
          {
           while (a%b!=0)
           {
            c=a%b;
            a=b;
            b=c;
           }
          return b;
          }
        }
    }

}

int NOK (int a,int b)
{
   int c;
   if (a==0 || b==0)
   {
       c=0;
       return c;
   }
   else
   {
    c=a;
    while (a%b!=0)
    {
     a+=c;
    }
    return a;
   }
}

