#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max];
    int size;
    printf("Введите размер массива:\n");
    scanf("%d",&size);
    array_input(array,size);
    printf("Изначальный массив:\n");
    array_output (array,size);
    mergesort(array,size);
    printf("\nОтсортированный массив:\n");
    array_output (array,size);
    system("pause");
    return 0;
}
