#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x,y;
    printf("Vvedite pervoe 4islo\n");
	scanf("%d",&x);
    printf("\n");
    printf("Vvedite vtoroe 4islo\n");
	scanf("%d",&y);

	printf("%d/%d=%d\n",x,y,x/y);
	printf("%d%%%d=%d\n",x,y,x%y);
	printf("%d+%d=%d\n",x,y,x+y);
	printf("%d-%d=%d\n",x,y,x-y);
	printf("%d*%d=%d\n",x,y,x*y);

	system("Pause");
    return 0;
}
