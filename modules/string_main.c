#define size_max 1000
#define mas_col 100
#define mas_str 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numbers.h"

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


void string_vowels_consonants(const char *string)
{
char check_consonants[size_max]="QqWwRrTtPpSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm",check_vowels[size_max]="EeYyUuIiOoAa",end[size_max]=".?!";
int sum=0,sum_consonants=0,counter=0,check_point=0,check=0,counter_1=0,marker=1,count=0;
while (string[counter]!='\0')
{
while (check!=1)
{
    check=0;
    if (string[counter]==' ')
    {
        ++counter;
        check=2;
    }
    while (end[counter_1]!='\0' && check==0)
    {
        if (string[counter]==end[counter_1])
        {
        check=1;
        ++counter;
        }
        ++counter_1;
    }
    counter_1=0;
    if (check==0)
    {
    while (check_consonants[counter_1]!='\0' && check_point!=1)
    {
        if (string[counter]==check_consonants[counter_1])
        {
         ++sum_consonants;
         check_point=1;
        }
        ++counter_1;
    }
    counter_1=0;
    while (check_vowels[counter_1]!='\0' && check_point!=1)
    {
        if (string[counter]==check_vowels[counter_1])
        {
         ++sum;
         check_point=1;
        }
        ++counter_1;
    }
    counter_1=0;
    check_point=0;
    ++counter;
    ++count;
    }
}
check=0;
if (count>0)
{
if (sum>sum_consonants)
printf("%d - vowels",marker);
if (sum==sum_consonants)
printf("%d - equally",marker);
if (sum<sum_consonants)
printf("%d - consonants",marker);
printf("\n");
++marker;
}
count=0;
sum=0;
sum_consonants=0;
}
}


void string_substitute(char *string)
{
char letters[size_max]="QqWwRrTtPpSsDdFfGgHhJjKkLlZzXxCcVvBbNnMmEeYyUuIiOoAa";
int counter=0,navigation_1=0,navigation=0,begin=0,check=0,swi=0,swi_1=0;
while (string[navigation]!='\0')
{
    check=0;

 while (letters[navigation_1]!='\0' && check!=1)
    {
        if (string[navigation]==letters[navigation_1])
        {
         check=1;
         ++counter;
         swi_1=1;
        }
        ++navigation_1;
    }
    navigation_1=0;
   if (check==1 && swi==0)
   {
    begin=navigation;
    swi=1;
   }
    if (check==0 && swi_1==1)
    {
        if (prime_number(counter)==1)
        {
             while (counter)
            {
            string[begin]='*';
            ++begin;
            --counter;
            }
        }
        swi_1=0;
    }
   if (check==0)
   {
    swi=0;
    counter=0;
   }
++navigation;
}
}

int string_check(const char *str_1,const char *str_2)
{
int swi=0,counter=0;
while(swi==0 && str_1[counter]!='\0')
{
if(str_1[counter]!=str_2[counter]) swi=1;
++counter;
}
if(swi==0)
return 1;
else
return 0;
}
