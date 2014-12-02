#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=15,b=12,c=8;
    printf("Please, enter the time ((Hours, minutes, seconds) ");
    scanf("%d%d%d",&a,&b,&c);
    printf("%02d:%02d:%02d",a,b,c);
    return 0;
}
