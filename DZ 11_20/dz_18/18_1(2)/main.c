#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"
#include "../../../modules/compatibility.h"

#define mas_col 30
#define mas_str 30
#define size_max 1000

int main()
{
    int *coordinates=NULL,size=2;
    int *matrix=NULL,str,col,max,size_matrix;
    printf ("Введите количество строк в матрице:\n");
    scanf("%d",&str);
    printf ("Введите количество столбцов в матрице:\n");
    scanf("%d",&col);
    size_matrix=str*col;
    matrix=(int*)malloc(size_matrix*sizeof(int));
    coordinates=(int*)malloc(size*sizeof(int));
    printf ("Введите максимально возможное случайное число (для заполнения матрицы):\n");
    scanf("%d",&max);
    two_dimensional_array_input_rand_1 (matrix,str,col,max);
    two_dimensional_array_output_int_1 (matrix,str,col);
    if (two_dimensional_array_saddle_point_1(matrix,coordinates,str,col)==1)
    {
    printf ("В матрице найдена седловая точка: ее расположение строка-%d столбец-%d:\n",coordinates[0],coordinates[1]);
    }
    else
    {
    printf ("В матрице нет седловой точки.\n");
    }
    free(matrix);
    free(coordinates);
    return 0;
}
