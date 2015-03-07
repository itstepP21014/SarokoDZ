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
    int **matrix=NULL,str,col,max;
    printf ("Введите количество строк в матрице:\n");
    scanf("%d",&str);
    printf ("Введите количество столбцов в матрице:\n");
    scanf("%d",&col);
    matrix=(int**)malloc(str*sizeof(int));

    for (int i=0; i<str; i++)
    matrix[i]=(int*)malloc(col*sizeof(float));

    coordinates=(int*)malloc(size*sizeof(int));
    printf ("Введите максимально возможное случайное число (для заполнения матрицы):\n");
    scanf("%d",&max);
    two_dimensional_array_input_rand_2 (matrix,str,col,max);
    two_dimensional_array_output_int (matrix,str,col);
    if (two_dimensional_array_saddle_point_2(matrix,coordinates,str,col)==1)
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

