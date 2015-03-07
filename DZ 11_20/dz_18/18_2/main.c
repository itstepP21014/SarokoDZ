#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"
#include "../../../modules/compatibility.h"

#define mas_col 30
#define mas_str 30
#define size_max 1000

float f_1(float);
float f_2(float);
float f_3(float);

int main()
{

    float (*first)(float)=&f_1,(*second)(float)=&f_2,(*third)(float)=&f_3;
    float epsilon=0.005,result;
    float num=0.0;
    printf("x+4.0=0");
    result=bisection_method(first,epsilon,num);
    printf("\nx=%f\n",result);
    printf("x*7.0=0");
    result=bisection_method(second,epsilon,num);
    printf("\nx=%f\n",result);
    printf("(x*x)-5.0=0");
    result=bisection_method(third,epsilon,num);
    printf("\nx=%f\n",result);
    return 0;
}


float f_1(float x)
{
    return x+4.0;
}

float f_2(float x)
{
    return x*7.0;
}

float f_3(float x)
{
    return (x*x)-5.0;
}


