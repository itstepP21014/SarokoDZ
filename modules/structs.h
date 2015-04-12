#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct fraction
{
    int num;
    int denom;
};
struct complex_number
{
    double f_n;
    double s_n;
    char i;
};
struct time
{
    int hours;
    int minutes;
    int seconds;
};
typedef struct complex_number complex_number;
typedef struct fraction fraction;
typedef struct time time;
time t_1;
time t_2;
complex_number c_1;
complex_number c_2;
fraction first;
fraction second;
fraction fraction_sum(fraction,fraction);
fraction fraction_div(fraction,fraction);
fraction fraction_multiply(fraction,fraction);
fraction fraction_minus(fraction,fraction);
complex_number complex_sum(complex_number,complex_number);
complex_number complex_minus(complex_number,complex_number);
complex_number complex_div(complex_number,complex_number);
complex_number complex_multiply(complex_number,complex_number);
time time_sum (int,time);
int time_difference (time,time);

#endif // STRUCTS_H_INCLUDED
