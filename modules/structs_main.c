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

complex_number complex_sum(complex_number c_1,complex_number c_2)
{
c_1.f_n=c_1.f_n+c_2.f_n;
c_1.s_n=c_1.s_n+c_2.s_n;
return c_1;
}

complex_number complex_minus(complex_number c_1,complex_number c_2)
{
c_1.f_n=c_1.f_n-c_2.f_n;
c_1.s_n=c_1.s_n-c_2.s_n;
return c_1;
}

complex_number complex_multiply(complex_number c_1,complex_number c_2)
{
c_1.f_n=(c_1.f_n*c_2.f_n)+(-(c_1.s_n*c_2.s_n));
c_1.s_n=(c_1.f_n*c_2.s_n)+(c_1.s_n*c_2.f_n);
return c_1;
}

complex_number complex_div(complex_number c_1,complex_number c_2)
{
complex_number copy;
copy.f_n=c_2.f_n;
copy.s_n=-c_2.s_n;
complex_multiply(c_1, copy);
complex_multiply(c_2, copy);
c_1.f_n=c_1.f_n/c_2.f_n;
c_1.s_n=c_1.s_n/c_2.f_n;
return c_1;
}

