#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct fraction
{
    int num;
    int denom;
};
typedef struct fraction fraction;
fraction first;
fraction second;
fraction fraction_sum(fraction,fraction);
fraction fraction_div(fraction,fraction);
fraction fraction_multiply(fraction,fraction);
fraction fraction_minus(fraction,fraction);

#endif // STRUCTS_H_INCLUDED
