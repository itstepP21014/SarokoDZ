#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/structs.h"

int main()
{
int whole,swi=1;
char enter;
double res_1;
printf("Example of the program:\n5(8/9)\n+\n1(2/3)\n=\nresult:7(5/9)\n..........\n");
while (swi)
{
scanf("%d(%d/%d)",&whole,&first.num,&first.denom);
fflush(stdin);
first.num+=(whole*first.denom);
scanf("%c",&enter);
fflush(stdin);
scanf("%d(%d/%d)",&whole,&second.num,&second.denom);
fflush(stdin);
second.num+=(whole*second.denom);
if(enter=='+')
first=fraction_sum(first,second);
if(enter=='-')
first=fraction_minus(first,second);
if(enter=='/')
first=fraction_div(first,second);
if(enter=='*')
first=fraction_multiply(first,second);
if(enter=='=')
{
printf("Invalid operation!\n");
return 0;
}
scanf("%c",&enter);
fflush(stdin);
if(enter=='=')
{
whole=first.num/first.denom;
res_1=(double)first.num/first.denom;
first.num=first.num%first.denom;
if (first.num==0)
printf("\nresult:\n%d",whole);
else
printf("\nresult:%d(%d/%d) or %f\n",whole,first.num,first.denom,res_1);
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
        scanf("%c",&enter);
        fflush(stdin);
        scanf("%d(%d/%d)",&whole,&second.num,&second.denom);
        fflush(stdin);
        second.num+=(whole*second.denom);
        if(enter=='+')
        first=fraction_sum(first,second);
        if(enter=='-')
        first=fraction_minus(first,second);
        if(enter=='/')
        first=fraction_div(first,second);
        if(enter=='*')
        first=fraction_multiply(first,second);
        if(enter=='=')
        {
            whole=first.num/first.denom;
            res_1=(double)first.num/first.denom;
            first.num=first.num%first.denom;
            if (first.num==0)
            printf("\nresult:\n%d",whole);
            else
            printf("\nresult:%d(%d/%d) or %f\n",whole,first.num,first.denom,res_1);
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


