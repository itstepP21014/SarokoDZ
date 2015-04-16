#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/structs.h"

int main()
{
char enter;
int swi=1,days;
d_1.year=1;
d_1.month=1;
d_1.day=1;
printf("'+' add days to current date,'d' compare with next date (return difference)\n");
printf("\nStarting date: %d.%d.%d\n",d_1.day,d_1.month,d_1.year);
while (swi)
{
scanf("%c",&enter);
fflush(stdin);
if (enter=='+')
{
scanf("%d",&days);
fflush(stdin);
d_1=date_sum(d_1,days);
printf("\nThe current date: %d.%d.%d\n",d_1.day,d_1.month,d_1.year);
}
if (enter=='d')
{
scanf("%d.%d.%d",&d_2.day,&d_2.month,&d_2.year);
fflush(stdin);
days=date_difference(d_1,d_2);
printf("\nDifference: %d days\n",days);
}
printf("\nDo you want to exit the program? - yes (y) no (n)\n");
scanf("%c",&enter);
fflush(stdin);
if (enter=='y')
swi=0;
}
scanf("%d.%d.%d",&d_1.day,&d_1.month,&d_1.year);
fflush(stdin);
printf("\nThe current date: %d.%d.%d\n",d_1.day,d_1.month,d_1.year);
return 0;
}
