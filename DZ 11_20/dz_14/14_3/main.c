#include <stdio.h>
#include <stdlib.h>

#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max],size,check,number,swi=1;
    printf("Пожалуйста введите размер массива:\n");
    scanf("%d",&size);
    if (size>size_max || size<1)
    {
        printf("Неверный размер массива!\n");
        system("pause");
        exit(1);
    }
    printf("Ввести элементы массива самостоятельно или сгенерировать их? ввод-1, генерация-2:\n");
    scanf("%d",&check);
    switch (check)
    {
    case 1:
    array_input(array,size);
    break;
    case 2:
    array_input_random(array,size);
    break;
    default:
    printf("Внимательнор читайте инструкции!\n");
    system("pause");
    exit(2);
    }
    number=array_search_Max_parity(array,size);
    if (number==1)
    {
    printf("Массив не содержит четных элементов.\n");
    swi=0;
    }
    if (swi==1)
    {
     array_search_same (array,size,number);
    printf("Максимальные четные элементы массива заменены их индексами.\n");
    }
    system ("pause");
    return 0;
}

