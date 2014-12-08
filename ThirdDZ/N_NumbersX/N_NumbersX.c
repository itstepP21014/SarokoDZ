#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,counter,number,multiplicand=1;
    printf("Please enter an integer:\n");
    scanf("%d",&n);
    printf("Please enter the %d integers:\n",n);
//Использовал цикл for  так как известно количество повторений цикла.
    for (counter=n;counter!=0;--counter)
    {
       scanf("%d",&number);
       multiplicand*=number;
    }

    printf("The result of multiplying the number %d:\n",n);
    printf("%d\n",multiplicand);
	system("pause");
    return 0;
}
