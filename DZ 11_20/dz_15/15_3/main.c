#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    unsigned char array[size_max];
    int size=999,array_1[size_max],array_2[size_max],counter;
    printf("Интерпретатор BF!\n");
    printf("Окончание ввода пограммы: символ ;\n");
    printf("Пожалуйста введите текст программы:\n");
    counter=array_input_char_BF(array,size);
    if (array_BF_BRACKETS (array,size)==0 || array_BF_chars (array,counter)==0)
    {
        printf("Обнаружены ошибки в тексте программы!\n");
        system ("pause");
        exit (1);
    }
    array_index_BRACKETS (array,array_2,size);
    printf("Результат обработки текста программы:\n");
    array_BF_processing (array,array_1,array_2,size);
    printf("\n");
    system("pause");
    return 0;
}
