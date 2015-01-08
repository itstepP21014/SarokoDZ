#include <stdio.h>
#include <stdlib.h>

int main()
{
    int answer,swi=0,swiM=1,swi1=0;
    printf("Your computer does not work. Your actions?\n");
    while (swiM)
    {
     if (swi>0)
     {
       printf("1.Hit again.\n");
     }
     else
     {
       printf("1.Hit in a special place\n");
     }
     if (swi1>0)
     {
       printf("2.Continue to talk with your computer.\n");
     }
     else
     {
       printf("2.Pat the system unit and kindly ask him to work.\n");
     }
     printf("3.Check the connection to the wall outlet\n");
     scanf("%d",&answer);
     system ("cls");
     switch (answer)
     {
     case 1:
        if (swi==0)
        {
          printf("You beat the system unit, but it still does not respond to attempts to turn it on.\n\n");
          swi=1;
        }
        else
        {
          printf("You hit with such force that the main body is dent..Inside hear the crunch.\n\n");
          swiM=2;
        }
        break;
     case 2:
         if (swi1==0)
         {
           printf("Despite the suasion computer still does not work.\n\n");
           swi1=1;
         }
         else
         {
          if (swi1==1)
          {
            printf("You move to the threats, but the computer does not respond to them, too.\n\n");
            swi1=2;
          }
          else
          {
            printf("You show a computer document that you are a deputy city council. But even this does not help.\n\n");
          }
         }
        break;
     case 3:
        if (swiM==2)
        {
            printf("It seems plug is not plugged into the wall outlet.Damn! You stick a plug into the outlet but nothing happens. It seems you broke something inside the system unit. Beat him wasn't the best idea after all.\nGame over!\n");
            swiM=0;
        }
        else
        {
             printf("It seems plug is not plugged into the wall outlet.Damn! You stick a plug into the outlet and turn on your computer.\nCongratulations, you have completed the game!\n");
             swiM=0;
        }
        break;
     default:
        printf("You must choose one of the options!\n\n");
        break;
     }
     if (swiM>0)
     {
       printf("Your computer still does not work. Your actions?\n");
     }
    }
    system("pause");
    return 0;
}
