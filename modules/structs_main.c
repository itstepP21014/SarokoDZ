#include "structs.h"

fraction fraction_sum(fraction first,fraction second)
{
int copy;
copy=first.denom;
first.num=first.num*second.denom;
first.denom=first.denom*second.denom;
second.num=second.num*copy;
second.denom=second.denom*copy;
first.num+=second.num;
return first;
}

fraction fraction_div(fraction first,fraction second)
{
int copy;
copy=second.num;
second.num=second.denom;
second.denom=copy;
first.num=first.num*second.num;
first.denom=first.denom*second.denom;
return first;
}

fraction fraction_multiply(fraction first,fraction second)
{
first.num=first.num*second.num;
first.denom=first.denom*second.denom;
return first;
}

fraction fraction_minus(fraction first,fraction second)
{
int copy;
copy=first.denom;
first.num=first.num*second.denom;
first.denom=first.denom*second.denom;
second.num=second.num*copy;
second.denom=second.denom*copy;
first.num-=second.num;
return first;
}
