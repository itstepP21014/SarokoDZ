#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    char array[size_max];
    int counter,size=999;
    printf("Обратная польская запись!\n");
    printf("Окончание ввода: символ =\n");
    counter=array_input_char(array,size);
    printf("Результат:\n%d.\n",counter);
    system("pause");
    return 0;
}
