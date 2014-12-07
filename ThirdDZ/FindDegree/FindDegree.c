#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,l,x1,degree=1,x1copy=0,m;
    printf("Please enter the number l>0:\n");
    scanf("%d",&l);
    printf("Please enter the number x<=l:\n");
    scanf("%d",&x);
    x1=x;
    //Я использовал здесь цикл While так как мне не было известно сколько раз должен выполниться цикл и нужен ли он будет вообще.
    //Сделано для натуральных чисел
    while (!(x1copy<=l && (x1copy*x1)>l))
    {
      x*=x1;
      x1copy=x;
      degree+=1;
    }
    printf("result:\n");
    printf("%d\n",degree);
	system("pause");

    return 0;
}
