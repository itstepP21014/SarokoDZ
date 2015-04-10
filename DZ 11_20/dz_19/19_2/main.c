#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/structs.h"

int main()
{
int swi=1;
char enter;
printf("Example of the program:\n8.0+7.5i\n+\n11.5+6.5i\n=\nresult:9.5+13.5i\n..........\n");
printf("Operation of complex conjugation: f\n");
while (swi)
{
scanf("%lf+%lfi",&c_1.f_n,&c_1.s_n);
fflush(stdin);
while (swi)
{
scanf("%c",&enter);
fflush(stdin);
if(enter=='f')
c_1.s_n=-c_1.s_n;
else
swi=0;
}
swi=1;
scanf("%lf+%lfi",&c_2.f_n,&c_2.s_n);
fflush(stdin);
if(enter=='+')
c_1=complex_sum(c_1,c_2);
if(enter=='-')
c_1=complex_minus(c_1,c_2);
if(enter=='/')
c_1=complex_div(c_1,c_2);
if(enter=='*')
c_1=complex_multiply(c_1,c_2);
if(enter=='=')
{
printf("Invalid operation!\n");
return 0;
}
scanf("%c",&enter);
fflush(stdin);
if(enter=='=')
{
printf("\nresult:%f+%fi\n",c_1.f_n,c_1.s_n);
printf("\nDo you want to exit the program? - yes (y) no (n)\n");
scanf("%c",&enter);
fflush(stdin);
if (enter=='y')
swi=0;
}
else
{
    while (enter!='=')
    {
        while (swi)
        {
            scanf("%c",&enter);
            fflush(stdin);
            if(enter=='f')
            c_1.s_n=-c_1.s_n;
            else
            swi=0;
        }
        swi=1;
        scanf("%lf+%lfi",&c_2.f_n,&c_2.s_n);
        fflush(stdin);
        if(enter=='+')
        c_1=complex_sum(c_1,c_2);
        if(enter=='-')
        c_1=complex_minus(c_1,c_2);
        if(enter=='/')
        c_1=complex_div(c_1,c_2);
        if(enter=='*')
        c_1=complex_multiply(c_1,c_2);
        if(enter=='=')
        {
            printf("\nresult:%f+%fi\n",c_1.f_n,c_1.s_n);
        }
    }
printf("\nDo you want to exit the program? - yes (y) no (n)\n");
scanf("%c",&enter);
fflush(stdin);
if (enter=='y')
swi=0;
}
}

return 0;
}
