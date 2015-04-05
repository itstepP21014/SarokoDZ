#include <stdio.h>
#include <string.h>

#define size_max 1000

int files_unite(const char*comand,int counter_1)
{
    FILE *first;
    int counter=0,counter_3=0;
    char comand_copy[size_max],result_string[size_max],unite_string[size_max];
            while (comand[counter_1]!='>')
            {
                while (comand[counter_1]==' ')
                {
                    ++counter_1;
                }
                while (counter<size_max)
                {
                    comand_copy[counter]='\0';
                    ++counter;
                }
                counter=0;
                while (comand[counter_1]!=' ')
                {
                  comand_copy[counter]=comand[counter_1];
                  ++counter;
                  ++counter_1;
                }
                ++counter_1;
                counter=0;
                first=fopen(comand_copy,"r");
                if(first == 0)
                {
                    printf("cant open file");
                    return 0;
                }
                else
                while (counter<size_max)
                {
                    comand_copy[counter]='\0';
                    ++counter;
                }
                counter=0;
                fgets(result_string,sizeof(result_string),first);
                while(result_string[counter]!='\0')
                {
                        unite_string[counter_3]=result_string[counter];
                        ++counter_3;
                        ++counter;
                }
                counter=0;
                while (counter<size_max)
                {
                    result_string[counter]='\0';
                    ++counter;
                }
                counter=0;
                fclose(first);
            }
            if (comand[counter_1]!='>')
            {
                printf("Invalid comand_2\n");
            }
            ++counter_1;
            while (comand[counter_1]!=' ')
            {
                ++counter_1;
            }
            while (comand[counter_1]!='\0')
            {
                result_string[counter]=comand[counter_1];
                ++counter_1;
                ++counter;
            }
            printf ("%s\n",result_string);
            counter_1=0;
            counter=0;
            first=fopen(result_string, "wb");
            if(first == 0)
            {
                printf("cant open file!!!");
                return 0;
            }
            printf ("%s\n",unite_string);
            fwrite(unite_string, strlen(unite_string), 1, first);
            fclose(first);
            return 1;
}


int files_print(const char*comand,int counter_1)
{
    FILE *first;
    int counter=0;
    char comand_copy[size_max],result_string[size_max];
            while (comand[counter_1]!='\0')
            {
                while (comand[counter_1]==' ')
                {
                    ++counter_1;
                }
                while (counter<size_max)
                {
                    comand_copy[counter]='\0';
                    ++counter;
                }
                counter=0;
                while (comand[counter_1]!=' ')
                {
                  comand_copy[counter]=comand[counter_1];
                  ++counter;
                  ++counter_1;
                }
                ++counter_1;
                counter=0;
                first=fopen(comand_copy,"r");
                if(first == 0)
                {
                    printf("cant open file");
                    return 0;
                }

                while (counter<size_max)
                {
                    comand_copy[counter]='\0';
                    ++counter;
                }
                counter=0;
                fgets(result_string,sizeof(result_string),first);
                printf("%s",result_string);
                printf("\n");
                while (counter<size_max)
                {
                    result_string[counter]='\0';
                    ++counter;
                }
                counter=0;
                fclose(first);
            }
            return 1;
}


int files_print_lines(const char*comand,int counter_1)
{
    FILE *first;
    int counter=0,num=1;
    char comand_copy[size_max],result_string[size_max];
while (comand[counter_1]!='\0')
            {
                while (comand[counter_1]==' ')
                {
                    ++counter_1;
                }
                while (counter<size_max)
                {
                    comand_copy[counter]='\0';
                    ++counter;
                }
                counter=0;
                while (comand[counter_1]!=' ')
                {
                  comand_copy[counter]=comand[counter_1];
                  ++counter;
                  ++counter_1;
                }
                ++counter_1;
                counter=0;
                first=fopen(comand_copy,"r");
                if(first == 0)
                {
                    printf("cant open file");
                    return 0;
                }

                while (counter<size_max)
                {
                    comand_copy[counter]='\0';
                    ++counter;
                }
                counter=0;
                while(fgets(result_string,sizeof(result_string),first))
                {
                    printf("%d ",num);
                    ++num;
                    printf("%s",result_string);
                }
                while (counter<size_max)
                {
                    result_string[counter]='\0';
                    ++counter;
                }
                counter=0;
                fclose(first);
            }
            return 1;
}
