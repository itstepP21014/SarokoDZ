#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max],size,check,number,index_1,index_2;
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
    printf("Введите целое число:\n");
    scanf("%d",&number);
    index_1=array_search_MP_dif (array,size,number);
    if (index_1==-1)
    {
        printf("Массив не содержит четных положительных элементов, кратных %d.\n",number);
        system ("pause");
        exit (2);
    }
    index_2=size-1;
    array_replacement_2(array,size,index_1,index_2);
    printf("Последний четный, положительный элемент массива кратный %d поменялся местами с последним элементом.\n",number);
    system ("pause");
    return 0;
}
