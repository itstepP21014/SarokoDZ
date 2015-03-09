int string_lenght(const char *str)
{
int check=0;
while (str[check]!='\0')
{
    ++check;
}
return check;
}
