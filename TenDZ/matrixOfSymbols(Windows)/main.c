#include <stdio.h>
#include <stdlib.h>
void matrix(int n);
int NOD(int line, int column);

int main()
{
    system ("chcp 1251");
    system ("cls");
    int n;
    printf("���������� ������� ����� �����, ������� ��������� ������ �������:\n");
    scanf ("%d",&n);
    matrix (n);
    system ("pause");
    return 0;
}

void matrix(int n)
{
    int swi=1,swi1=1,line=1,column=0;
  while (swi)
  {
     ++column;
     while (swi1)
     {
     if (column>n)
     {
         printf ("\n");
         swi1=0;
     }
     else
     {
       if (NOD(line,column)==1)
       {
         printf ("0");
       }
       else
       {
         printf ("#");
       }
     }
     ++column;
     }
     swi1=1;
     column=0;
     ++line;
     if (line>n)
     {
         swi=0;
         printf("������.");
     }
  }
}


int NOD(int line, int column)
{
    int a=line,b=column;
      while (a%b!=0)
   {
       int c=a%b;
       a=b;
       b=c;
   }
   return b;
}
