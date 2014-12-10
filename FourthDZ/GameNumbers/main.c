#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int x,y;
    int afterWin;
    x=(1+rand()%98);
    printf("You have to guess the number 1 to 99:\n");
    scanf("%d",&y);
    while (y!=x)
    {
        if (y>x)
        {
            printf ("No,no,no - too much\n");

        }
        else
        {
            printf ("No,no,no - too small\n");
        }
        scanf("%d",&y);
    }
    printf ("Congratulations! You win!");
    printf ("Want to play again? (1-yes//2-no)");
    scanf ("%d",&afterWin);
    switch (afterWin)
    {
    case 1:
    main();
    break;
    case 2:
    printf ("Coward!");
    break;
    default:
    printf("You can not be serious?!");
    break;
    }
    return 0;
}
