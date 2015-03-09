#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../modules/qSort_func.h"
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"
#include "../../../modules/compatibility.h"

#define mas_col 30
#define mas_str 30
#define size_max 1000

int main()
{
    int array[size_max];
    int size=10;
    array_input_random(array,size);
    printf ("\nСортировка в обратном порядке:\n");
    qsort(array, size, sizeof(int),reverse_sort);
    array_output(array,size);
    printf ("\nСортировка по возрастанию суммы цифр:\n");
    qsort(array, size, sizeof(int),sum_of_digits);
    array_output(array,size);
    printf ("\nСортировка по возрастанию количества делителей числа:\n");
    qsort(array, size, sizeof(int),number_of_divisors);
    array_output(array,size);
    return 0;
}
