#define size_max 1000
#define mas_col 100
#define mas_str 100
#include <stdio.h>
#include <stdlib.h>

int string_lenght(const char *str)
{
int check=0;
while (str[check]!='\0')
{
    ++check;
}
return check;
}


int string_comparison(const char *str_1,const char *str_2)
{
int counter=0,s_1,s_2;
while (str_1[counter]==str_2[counter] && str_1[counter]!='\0' && str_2[counter]!='\0')
{
++counter;
}
if (str_1[counter]=='\0' && str_2[counter]=='\0')
return 0;
s_1=str_1[counter];
s_2=str_2[counter];
if (s_1>s_2)
return 1;
else
return -1;
}


void string_copy(char *dest_string,const char *string)
{
int counter=0;
while (string[counter]!='\0' && counter!=(size_max-1))
{
    dest_string[counter]=string[counter];
    ++counter;
}
}


void string_print_words(const char *string,const char *symbols)
{
char array[mas_str][mas_col],start,end;
int str=0,col=0,str_count=0,col_count=0,check=0,counter=0,counter_1=0,counter_2=0,check_point,swi=1;
//Заполнение двумерного массива пробелами.
while (str!=mas_str)
{
array[str][col]=' ';
++col;
if (col==mas_col)
{
    col=0;
    ++str;
}
}
str=0;
col=0;

while (string[counter]!='\0')
{
    while (symbols[counter_1]!='\0')
    {
        if (string[counter]==symbols[counter_1])
        check=1;
        ++counter_1;
    }
counter_1=0;
    while (check==1)
    {
    check=0;
    while (symbols[counter_1]!='\0')
    {
        if (string[counter]==symbols[counter_1])
        check=1;
        ++counter_1;
    }
    counter_1=0;
    if (check==1)
    ++counter;
    }
    counter_1=0;
    check=0;
    start=string[counter];
    check_point=counter;
    while (check==0)
    {
        ++counter;
        check=0;
    while (symbols[counter_1]!='\0')
    {
        if (string[counter]=='\0')
        check=1;
        if (string[counter]==symbols[counter_1])
        check=1;
        ++counter_1;
    }
    counter_1=0;
    }
    end=string[counter-1];
    check=0;
    //Сверка с таблицей.(двумерным массивом.)
    if (end==start)
       {
           while(array[str][0]!=' ' && str!=mas_str-1 && swi==1)
           {
            counter_2=check_point;
            while(array[str][col]!=' ' && check==0)
           {
               if (array[str][col]!=string[counter_2])
               check=1;
               ++counter_2;
               ++col;
           }
           if (check==0)
            swi=0;
           check=0;
           col=0;
           ++str;
           }
           str=0;
           col=0;
           //Печать
           if (swi==1)
           {
               counter_2=check_point;
               while (counter_2!=counter)
               {
                   printf("%c",string[counter_2]);
                   array[str_count][col_count]=string[counter_2];
                   ++counter_2;
               }
               col_count=0;
               ++str_count;
               printf("\n");
           }
           swi=1;
       }
}
}
