#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../modules/gameDice.h"
#include "../../../modules/roll.c"

int main()
{
    int choice, swi=1, d_6, d_6n, sum1,sum2;
    srand(time(NULL));

    while (swi)
    {
     printf("Игра в кости против компьютера!\n");
     printf("Хотите кинуть кости? 1-да, 2-нет\n");
     scanf ("%d",&choice);
     switch (choice)
        {
        case 1:
        printf ("Ваш результат (2 кости)\n");
        d_6=1+rand()%6;
        d_6n=1+rand()%6;
        sum1=d_6+d_6n;
        roll (d_6,d_6n);
        printf ("Результат компьютера\n");
        d_6=1+rand()%6;
        d_6n=1+rand()%6;
        sum2=d_6+d_6n;
        roll (d_6,d_6n);
        if (sum1>sum2)
        {
            printf ("Вы победили.\n");
        }
        else
        {
            if (sum1==sum2)
            {
             printf ("Ничья.\n");
            }
            else
            {
             printf ("Вы проиграли.\n");
            }
        }
        break;
        case 2:
        swi=0;
        break;
        default:
        printf ("Введите 1 или 2.\n");
        break;
        }
    }
    system ("pause");
    return 0;
}
