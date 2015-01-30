#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max],size,check,positive,negative,numPos,numNeg,swi=1;
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
    numPos=array_search_positive(array,size);
    if (numPos<0)
    {
        printf("Массив не содержит положительных элементов.\n");
        swi=0;
    }
    else
    {
        positive=array[numPos];
    }
    numNeg=array_search_negative(array,size);
        if (numPos<0)
    {
        printf("Массив не содержит отрицательных элементов.\n");
        swi=0;
    }
    else
    {
        negative=array[numNeg];
    }
    if (swi==1)
    {
     array[numPos]=negative;
     array[numNeg]=positive;
     printf("Перестановка элементов успешно завершена!\n");
     system ("pause");
     return 1;
    }
    printf("Перестановка невозможна!\n");
    return 0;
}
