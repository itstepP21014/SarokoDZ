#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/useful_stuff.h"

int main()
{
    char UTF8[SIZE_MAX];
    printf("Please enter the string in the encoding UTF-8.\nexample:30 30 F3 8F 9B 9C;\n");
    gets(UTF8);
    printf("\nRESULT:%d\n",UTF8_count_symbols(UTF8));
    return 0;
}
