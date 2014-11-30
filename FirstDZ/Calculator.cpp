#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x,y;
    printf("Enter the first number\n");
	scanf("%d",&x);
    printf("\n");
    printf("Enter the second number\n");
	scanf("%d",&y);

	printf("%d/%d=%d\n",x,y,x/y);
	printf("%d%%%d=%d\n",x,y,x%y);
	printf("%d+%d=%d\n",x,y,x+y);
	printf("%d-%d=%d\n",x,y,x-y);
	printf("%d*%d=%d\n",x,y,x*y);

	system("Pause");
    return 0;
}
