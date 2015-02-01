#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int array[size_max],array_1[size_max],size,check,number;
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
    printf("Введите индекс элемента, который имеется в созданном массиве:\n");
    scanf("%d",&number);
    if (number<0 || number>size)
    {
        printf("Внимательно читайте инструкции!\n");
        system ("pause");
        exit(3);
    }
    array_1[number]=array_sum (array,number)/(number+1);
    printf("%d элемент второго массива заменен средним арифметическим первых %d элементов созданного вами массива.\n",number,number+1);
    system ("pause");
    return 0;
}
