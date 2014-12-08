#include <stdio.h>
#include <stdlib.h>

int main()
{
    int counter,number=1;
    printf("Number\tCubed\n");
    //Использован цикл For, так как известно количество чисел.
    for (counter=1;counter<=17;counter++)
    {
       printf("%d\t%d\n",number,number*number*number);
       number+=2;
    }

    return 0;
}
