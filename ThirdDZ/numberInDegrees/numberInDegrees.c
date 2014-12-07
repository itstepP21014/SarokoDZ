#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,p,counter,x1=1;
    printf("Please enter number:\n");
    scanf("%d",&x);
    printf("Please enter degree:\n");
    scanf("%d",&p);
    if (x==0)
    {
      x1=x;
    }
    else
    //»спользован цикл For так как известно кол-во повторений.
    //¬ычислить (0) в степени (p) можно при помощи добавлени€ конструкции(if) (else).
    //ƒелал так из предположени€, что используютс€ натуральные числа и ноль.
   {

    for (counter=p;counter!=0;--counter)
    {
        x1*=x;
    }

    }
    printf("The result %d",x1);

    return 0;
}
