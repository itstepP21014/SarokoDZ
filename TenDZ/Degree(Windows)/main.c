#include <stdio.h>
#include <stdlib.h>
void degree1(float number,int degree);
void degree2(float number,int degree);

int main()
{
    system ("chcp 1251");
    system ("cls");
    float number;
    int degree;
    printf("������� ������� �����:\n");
    scanf("%f",&number);
    printf("������� �������:\n");
    scanf("%d",&degree);
    if (degree>=0)
    {
      degree1(number,degree);
    }
    else
    {
      degree2(number,degree);
    }
    system ("pause");
    return 0;
}

void degree1(float number, int degree)
{
    if (degree==0)
    {
      printf ("���������: 1");
    }
    else
   {
      --degree;
      float numberCopy=number;
      while (degree)
    {
      --degree;
      number*=numberCopy;
    }
    printf ("���������:%f",number);
   }

}


void degree2(float number, int degree)
{
    if (degree==0)
    {
      printf ("���������: -1");
    }
    else
   {
      ++degree;
      float numberCopy=number;
      while (degree)
    {
      ++degree;
      number*=numberCopy;
    }
    printf ("���������:%f",1.0/number);
   }
}
