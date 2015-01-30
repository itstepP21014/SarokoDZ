#include <stdio.h>
#include <stdlib.h>

#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max],size,check,pMax,pMin,swi=1,swi_1=1;
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
    pMax=array_search_Max_parity(array,size);
    if (pMax==1)
    {
        printf("Массив не содержит четных элементов.\n");
        swi=0;
    }
    if (swi==1)
    {
        printf("Максимальный четный элемент массива: %d\n",pMax);
    }
        pMin=array_search_Min_parity(array,size);
    if (pMin==2)
    {
        printf("Массив не содержит нечетных элементов.\n");
        swi_1=0;
    }
        if (swi_1==1)
    {
        printf("Минимальный нечетный элемент массива: %d\n",pMin);
    }
    system ("pause");
    return 0;
}

