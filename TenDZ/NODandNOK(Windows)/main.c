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
    printf ("���������� ������� ������ ����� �����:\n");
    scanf ("%d",&number1);
    printf ("���������� ������� ������ ����� �����:\n");
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
       printf("���=0\n");
   }
   else
   {
      while (a%b!=0)
   {
       int c=a%b;
       a=b;
       b=c;
   }
   printf ("���=%d\n",b);
   }
}


void NOK(int a, int b)
{
   if (b==0 || a==0)
   {
       printf("�� ���� ������ ������ - ��� �� ���������.\n");
   }
   else
   {
          if (b==a)
    {
       printf("���=%d\n",a);
    }
     else
     {
      int c=a;
      while (a%b!=0)
      {
       a+=c;
      }
      printf ("���=%d\n",a);
     }
   }
}
