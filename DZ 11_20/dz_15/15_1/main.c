#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000


int main()
{
    int array_1[size_max];
    printf("Проверка скобок!\n");
    printf("Окончание ввода: символ #\n");
    checking_brackets(array_1);
    if (array_1[0]==0)
    {
        printf("Ошибок нет.\n");
    }
    else
    {
        printf("Имеются ошибки!\n");
    }
    system("pause");
    return 0;
}
