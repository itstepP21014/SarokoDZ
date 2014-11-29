#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int x,y;
    printf("Vvedite radius osnovania konysa\n");
    scanf("%d",&x);
    printf("\n");
    printf("Vvedite visoty konysa\n");
    scanf("%d",&y);
    printf("\n");
    printf("Obem (V) konysa raven %1.5lf\n", 0.33*3.14*pow(x,2)*y);
    printf("Ploshad (S) konusa ravna %1.5lf\n", 3.14*x*(x+sqrt(pow(x,2)+pow(y,2))));
	system("pause");
    return 0;
}
