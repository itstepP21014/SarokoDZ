#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"
#include "../../../modules/compatibility.h"

#define mas_col 30
#define mas_str 30

int main()
{
    char game_field[mas_str][mas_col],elements='#';
    int check,win_check=2,str=20,col=20,counter=0;
    two_dimensional_array_input_elements (&game_field[0][0],str,col,elements);
    two_dimensional_array_output (&game_field[0][0],str,col);
    printf("Выберите кто первым будет ходить: вы(1) или компьютер(2).\n");
    scanf("%d",&check);
    switch (check)
    {
    case 1:
        while (win_check==2)
        {
            x0_20x20_player_turn (&game_field[0][0],str,col);
            ++counter;
            if (counter==400)
            {
                printf("\nВсе поле заполнено!\n");
                system("pause");
                exit (2);
            }
            win_check=check_win_x0_5_20 (&game_field[0][0],str,col);
            universalClear();
            two_dimensional_array_output (&game_field[0][0],str,col);
            system ("pause");
                if (win_check==1)
                {
                printf("\nВы одержали победу над компьютером!\n");
                system("pause");
                return (0);
                }
                if (win_check==0)
                {
                printf("\nКомпьютер одержал победу над вами!\n");
                system("pause");
                return (0);
                }
            two_dimensional_array_x0_reaction_20x20 (&game_field[0][0],str,col);
            universalClear();
            two_dimensional_array_output (&game_field[0][0],str,col);
            ++counter;
            win_check=check_win_x0_5_20 (&game_field[0][0],str,col);
            if (counter==400)
            {
                printf("\nВсе поле заполнено!\n");
                system("pause");
                exit (2);
            }
            universalClear();
            two_dimensional_array_output (&game_field[0][0],str,col);
                if (win_check==1)
                {
                printf("\nВы одержали победу над компьютером!\n");
                system("pause");
                return (0);
                }
                if (win_check==0)
                {
                printf("\nКомпьютер одержал победу над вами!\n");
                system("pause");
                return (0);
                }
        }
    break;
    case 2:
        while (win_check==2)
        {
            two_dimensional_array_x0_reaction_20x20 (&game_field[0][0],str,col);
            ++counter;
            win_check=check_win_x0_5_20 (&game_field[0][0],str,col);
            if (counter==400)
            {
              printf("\nВсе поле заполнено!\n");
                system("pause");
                exit (2);
            }
            universalClear();
            two_dimensional_array_output (&game_field[0][0],str,col);
                if (win_check==1)
                {
                printf("\nВы одержали победу над компьютером!\n");
                system("pause");
                return (0);
                }
                if (win_check==0)
                {
                printf("\nКомпьютер одержал победу над вами!\n");
                system("pause");
                return (0);
                }
            x0_20x20_player_turn (&game_field[0][0],str,col);
            universalClear();
            two_dimensional_array_output (&game_field[0][0],str,col);
            win_check=check_win_x0_5_20 (&game_field[0][0],str,col);
            ++counter;
            if (counter==400)
            {
              printf("\nВсе поле заполнено!\n");
                system("pause");
                exit (2);
            }
            universalClear();
            two_dimensional_array_output (&game_field[0][0],str,col);
                if (win_check==1)
                {
                printf("\nВы одержали победу над компьютером!\n");
                system("pause");
                return (0);
                }
                if (win_check==0)
                {
                printf("\nКомпьютер одержал победу над вами!\n");
                system("pause");
                return (0);
                }
        }
        break;
     default:
     printf("\nВнимательно читайте инструкции!\n");
     system("pause");
     exit (3);
    }
    return 0;
}
