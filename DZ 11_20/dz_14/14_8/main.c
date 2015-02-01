#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max],size,check;
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
    if (array_search_Element_more (array,size,array_search_min_many(array,size))<2 && array_search_min_many(array,size)==0)
    {
    printf("В массиве нет элементов встречающихся более одного раза.\n");
    system("pause");
    return 1;
    }
    printf ("Минимальный элемент массива, встречающийся более одного раза:%d\n",array_search_min_many(array,size));
    system ("pause");
    return 0;
}
