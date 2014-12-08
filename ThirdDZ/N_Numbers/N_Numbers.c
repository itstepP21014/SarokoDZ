#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,counter;
    printf("Please enter an integer >1:\n");
    scanf("%d",&number);
    /*Я использовал здесь цикл For, так как здесь как и в первом задании нам известно количество циклов.*/
    for (counter=1;counter<=number;counter++)
    {
      printf(" %d",counter);
    }
    return 0;
}
