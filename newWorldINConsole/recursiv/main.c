#include <stdio.h>
#include <stdlib.h>
//Ханойская башня. Тот самый часто используемый примитив _|_||. Перетаскивание дисков.
void towers(int d,char from, char to,char helper);

int main()
{
    char a,b,c;
    scanf("%c",&a);
    fflush(stdin);
    scanf("%c",&b);
    fflush(stdin);
    scanf("%c",&c);
    fflush(stdin);
    towers(5,a,b,c);
    return 0;
}


void towers(int d,char from, char to,char helper)
{
    if (d>1)
    {
        towers(d-1,from,helper,to);
        printf("%c->%c\n",from,to);
        towers(d-1,helper,to,from);
    }
    else
    {
        printf("%c->%c\n",from,to);
    }

}

