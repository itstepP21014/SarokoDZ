#include <stdio.h>
#include <stdlib.h>

int main()
{
    double N,exorcismSpeed,flyReturnSpeed,fatigueTime;
    int swi=1,time=0;
    printf("Only double!\n");
    printf("Please enter number of flies:\n");
    scanf("%lf",&N);
    printf("Please enter number of banished flies per minute:\n");
    scanf("%lf",&exorcismSpeed);
    printf("Please enter number of minutes, when man get tired:\n");
    scanf("%lf",&fatigueTime);
    printf("Please enter number of flies, which come back every minute:\n");
    scanf("%lf",&flyReturnSpeed);
    while (swi && N>0)
    {
        --fatigueTime;
        N-=exorcismSpeed;
        N+=flyReturnSpeed;
        if (fatigueTime==0)
        {
           exorcismSpeed=(exorcismSpeed*80.0)/100.0;
        }
        if (exorcismSpeed<=flyReturnSpeed)
        {
            swi=0;
        }
        ++time;
    }
    if (swi==0)
    {
        printf("You're kidding me - this is not possible!\n");
    }
    else
    {
        printf("All flies are driven for %d minutes.\n",time);
    }
    system("pause");
    return 0;
}
