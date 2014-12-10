#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int x,y,counter=0;
    int afterWin;
    x=(1+rand()%98);
    printf("You have to guess the number 1 to 99:\n");
    scanf("%d",&y);
    while (y!=x)
    {
        if (y>x)
        {
            printf ("No,no,no - too much\n");
            counter+=1;
        }
        else
        {
            printf ("No,no,no - too small\n");
            counter+=1;
        }
        scanf("%d",&y);
    }
    printf ("Congratulations! You win!\n");
    printf ("You took %d turns.",counter);
    printf ("Want to improve your score? (1-yes//2-no)");
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
