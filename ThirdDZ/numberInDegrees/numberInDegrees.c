#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,p,counter,x1=1;
    printf("Please enter number:\n");
    scanf("%d",&x);
    printf("Please enter degree:\n");
    scanf("%d",&p);
    if (x==0)
    {
      x1=x;
    }
    else
    //����������� ���� For ��� ��� �������� ���-�� ����������.
    //��������� (0) � ������� (p) ����� ��� ������ ���������� �����������(if) (else).
    //����� ��� �� �������������, ��� ������������ ����������� ����� � ����.
   {

    for (counter=p;counter!=0;--counter)
    {
        x1*=x;
    }

    }
    printf("The result %d",x1);

    return 0;
}
