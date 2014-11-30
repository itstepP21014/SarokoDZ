#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int x,y;
    printf("Enter the radius of the base of the cone\n");
    scanf("%d",&x);
    printf("\n");
    printf("Enter the height of the cone\n");
    scanf("%d",&y);
    printf("\n");
    printf("The volume of a cone is equal to %1.5lf\n", 0.33*3.14*pow(x,2)*y);
    printf("The area of the cone is %1.5lf\n", 3.14*x*(x+sqrt(pow(x,2)+pow(y,2))));
	system("pause");
    return 0;
}
