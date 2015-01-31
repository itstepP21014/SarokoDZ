#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max],size,check,max,min;
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
    printf("Внимательно читайте инструкции!\n");
    system("pause");
    exit(2);
    }
    max=array_search_Max(array,size);
    min=array_search_Min(array,size);
    array_replacement (array,size,max,min);
    printf("Все четные элементы массива заменены максимальным, а все нечеиные минимальным элементом.\n");
    system ("pause");
    return 0;
}

