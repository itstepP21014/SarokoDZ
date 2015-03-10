#define size_max 1000

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
