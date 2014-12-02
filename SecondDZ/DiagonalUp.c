#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,n,m;
    char a[]="";
    printf("Enter the four numbers\n");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&n);
    scanf("%d",&m);
    printf("%*s%d\n%*s%d\n%*s%d\n%*s%d\n",0,a,x*2,1,a,y*2,2,a,n*2,3,a,m*2);
    return 0;
}
