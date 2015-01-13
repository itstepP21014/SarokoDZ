#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
void NOD(int a, int b);
void NOK(int a, int b);

int main()
{
    system ("chcp 1251");
    system ("cls");
    int number1,number2;
    setlocale(LC_ALL, "russian_russia.1251");
    printf ("Пожалуйста введите первое целое число:\n");
    scanf ("%d",&number1);
    printf ("Пожалуйста введите второе целое число:\n");
    scanf ("%d",&number2);
    NOD(number1,number2);
    NOK(number1,number2);
    system ("pause");
    return 0;
}


void NOD(int a, int b)
{
   if (b==0 || a==0)
   {
       printf("НОД=0\n");
   }
   else
   {
      while (a%b!=0)
   {
       int c=a%b;
       a=b;
       b=c;
   }
   printf ("НОД=%d\n",b);
   }
}


void NOK(int a, int b)
{
   if (b==0 || a==0)
   {
       printf("На ноль делить нельзя - НОК не определен.\n");
   }
   else
   {
          if (b==a)
    {
       printf("НОК=%d\n",a);
    }
     else
     {
      int c=a;
      while (a%b!=0)
      {
       a+=c;
      }
      printf ("НОК=%d\n",a);
     }
   }
}
