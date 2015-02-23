#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max];
    int size,choice;
    printf("Введите размер массива:\n");
    scanf("%d",&size);
    array_input(array,size);
    printf("Изначальный массив:\n");
    array_output (array,size);
    printf("Выберите тип сортировки:\n1-слиянием\n2-пирамидальная\n");
    scanf ("%d",&choice);
    switch (choice)
    {
    case 1:
    mergesort(array,size);
    break;
    case 2:
    heapSort(array,size);
    break;
    default:
    printf("Внимательно читайте инструкции!");
    system("pause");
    exit (2);
    }
    printf("\nОтсортированный массив:\n");
    array_output (array,size);
    system("pause");
    return 0;
}
