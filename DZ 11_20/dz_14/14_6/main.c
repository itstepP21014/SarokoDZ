#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int sta_m,fin_m;

int main()
{
    int array[size_max],size,check,number;
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
    printf ("Введите целое число:\n");
    scanf ("%d",&number);
    array_search_same_lenght (array,size,number);
    if (array_search_same_lenght (array,size,number)==0)
    {
        printf("В массиве нет такого элемента.-----\n");
        system ("pause");
        return 1;
    }
    printf("Самый длинный участок массива состоящий только из %d начинается с индекса %d и заканчивается индексом %d\n+++++",number,sta_m,fin_m);
    system ("pause");
    return 0;
}

