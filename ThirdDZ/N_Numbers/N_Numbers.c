#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,counter;
    printf("Please enter an integer >1:\n");
    scanf("%d",&number);
    /*� ����������� ����� ���� For, ��� ��� ����� ��� � � ������ ������� ��� �������� ���������� ������.*/
    for (counter=1;counter<=number;counter++)
    {
      printf(" %d",counter);
    }
    return 0;
}
