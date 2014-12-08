#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0,l;
    /*Я использовал здесь цикл for, так как мне точно известно, сколько раз должен выполниться цикл(137)  */
    for ( l=1;l<=137;l++)
    {
      printf("Hello world!\n");
      t+=1;
      printf("%d\n",t);
    }
	system ("pause");

    return 0;
}
