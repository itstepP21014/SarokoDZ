#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max];
    int size,choice;
    int first=0,last;//для быстрой сортировки
    printf("Введите размер массива:\n");
    scanf("%d",&size);
    printf("Введите массив:\n");
    array_input(array,size);
    printf("Изначальный массив:\n");
    array_output (array,size);
    printf("\nВыберите тип сортировки:\n1-слиянием\n2-пирамидальная\n3-быстрая сортировка\n4-сортировка вставками\n");
    printf("5-сортировка пузырьком\n6-сортировка выбором\n");
    scanf ("%d",&choice);
    last=size-1;
    switch (choice)
    {
    case 1:
    mergesort(array,size);
    break;
    case 2:
    heapSort(array,size);
    break;
    case 3:
    quickSort(array,first,last);
    break;
    case 4:
    insertion_sort(array,size);
    break;
    case 5:
    bubble_sort(array,size);
    break;
    case 6:
    selection_sort(array,size);
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
