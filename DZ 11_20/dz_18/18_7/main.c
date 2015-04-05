#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../modules/Files.h"
#include "../../../modules/numbers.h"
#include "../../../modules/string_func.h"

#define size_max 1000

int main()
{
    char str_1[10]="--help",str_2[5]="-n",str_3[12]="-b",str_4[7]="cat",str_5[7]="-p",str_6[10]="--exit";
    char comand[size_max],comand_copy[size_max];
    int counter=0,counter_1=0,swi=0,swi_1=0,impotant=0;
    printf("Type a command or '--help' if you run the program for the first time:\n");
    while (swi==0)
    {
        while (counter<size_max)
        {
            comand_copy[counter]='\0';
            ++counter;
        }
        counter=0;
        gets(comand);

        while (comand[counter_1]==' ')
        {
            ++counter_1;
        }
        while (comand[counter_1]!=' ')
        {
            comand_copy[counter]=comand[counter_1];
            ++counter;
            ++counter_1;
        }
        counter=0;
        if (string_check(comand_copy,str_6)==1) impotant=10;
        if (string_check(comand_copy,str_1)==1) impotant=1;
        if (string_check(comand_copy,str_4)==1)
        {
            impotant=4;
        }
        if (string_check(comand_copy,str_5)==1)
        {
            impotant=5;
            while (counter<size_max)
            {
                comand_copy[counter]='\0';
                ++counter;
            }
            counter=0;
            while (comand[counter_1]==' ')
            {
                ++counter_1;
            }
            while (comand[counter_1]!=' ')
            {
                comand_copy[counter]=comand[counter_1];
                ++counter;
                ++counter_1;
            }

            counter=0;
            if (string_check(comand_copy,str_2)==1)
            {
                swi_1=1;
                impotant=2;
            }

            if (string_check(comand_copy,str_3)==1)
            {
                swi_1=1;
                impotant=3;
            }
            if (swi_1==0)
            {
                --counter_1;
            while (comand[counter_1]!=' ')
            {
                --counter_1;
            }
            }
            while (counter<size_max)
            {
                comand_copy[counter]='\0';
                ++counter;
            }
            counter=0;
        }
        switch (impotant)
        {
        case 1:
            printf("commands:\ncat file_1 file_2 ... file_n > file_name - unification of multiple files (file_n) into one (file_name)\n");
            printf("-p file_1...file_n - displays the contents of files\n");
            printf("-p -n file_1...file_n - displays the contents of files and all line numbers\n");
            printf ("--exit - end of the program\n");
            break;
        case 4:
            files_unite(comand,counter_1);
            counter_1=0;
            break;
        case 5:
            files_print(comand,counter_1);
            counter_1=0;
            break;
        case 2: //line numbers
            files_print_lines(comand,counter_1);
            counter_1=0;
            break;
        case 10:
            printf ("the program is completed\n");
            swi=1;
            break;
        default:
            printf("Invalid command!\n");
        }
    }

    return 0;
}
