#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/structs.h"

int main()
{
int seconds,swi=1;
char enter;
printf("1 example of program:\ni\n60\nresult: 00:01:00\n");
printf("2 example of program:\nd\n15:00:20 15:00:00\nresult: 20 seconds\n");
t_1.hours=0;
t_1.minutes=0;
t_1.seconds=0;
t_2.hours=0;
t_2.minutes=0;
t_2.seconds=0;
printf("\nstart %02d:%02d:%02d\n",t_1.hours,t_1.minutes,t_1.seconds);
while (swi)
{
    scanf("%c",&enter);
    fflush(stdin);
    if(enter=='i')
    {
        scanf("%d",&seconds);
        fflush(stdin);
        t_1=time_sum(seconds,t_1);
        printf("\n%02d:%02d:%02d\n",t_1.hours,t_1.minutes,t_1.seconds);
    }
    if(enter=='d')
    {
        scanf("%d:%d:%d",&t_1.hours,&t_1.minutes,&t_1.seconds);
        fflush(stdin);
        scanf("%d:%d:%d",&t_2.hours,&t_2.minutes,&t_2.seconds);
        fflush(stdin);
        printf("\nresult: %d seconds\n",time_difference(t_1,t_2));
    }
    if (enter!='i' && enter!='d')
    printf("\nInvalid operation!\n");
    printf("\nDo you want to exit the program? - yes (y) no (n)\n");
    scanf("%c",&enter);
    fflush(stdin);
    if (enter=='y')
    swi=0;
}
return 0;
}
