#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    char array[size_max];
    int size=999,array_1[size_max];
    printf("Интерпретатор BF!\n");
    printf("Окончание ввода пограммы: символ ;\n");
    printf("Пожалуйста введите текст программы:\n");
    array_input_char_BF(array,size);
    printf("Результат обработки текста программы:\n");
    array_BF_processing (array,array_1,size);
    printf("\n");
    system("pause");
    return 0;
}
