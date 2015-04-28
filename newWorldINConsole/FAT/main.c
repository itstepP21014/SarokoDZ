#include <stdio.h>
#include <stdlib.h>
#include "../../modules/numbers.h"
#include "../../modules/string_func.h"
#include "../../modules/structs.h"

#define SIZE_MAX 5000

int main()
{
    typedef struct FAT
    {
        int file;
        int index;
    }FAT;
    FAT FAT_table[SIZE_MAX];
    char real_clusters[SIZE_MAX],input[100],input_check[50],input_copy[100];
    file_open table_opened_files[15];
    int fast_memory[500];
    int counter=0,counter_copy=0,f_d,counter_2=0,count=0,swi_2=0,count_cluster=0,counter_3=0;
    char main_catalog[SIZE_MAX]; //Example:#filename/date/size/...# #-file separator ( and ) - directory separators

//Create an empty table of opened files
    while (counter<15)
    {
        table_opened_files[counter].descriptor=3;
        ++counter;
    }
    counter=0;

//Create an empty FAT table
    while (counter<SIZE_MAX)
    {
        FAT_table[counter].index=0;
        ++counter;
    }
    counter=0;
//Create an empty main catalog
    while (counter<SIZE_MAX)
    {
        main_catalog[counter]='\0';
        ++counter;
    }
    counter=0;
//Operations**********************************
    printf ("List of commands:\n-create\n-delete\n-open\n-close\n-seek\n-read");
    gets(input);

//search for a file (using his name)
SEARCH
counter=0;
counter_2=0;
int swi=0;
while (swi==0)
{
    swi=1;
    while (main_catalog[counter]!='/' && swi==0)
    {
    if (input[counter_2]!=main_catalog[counter])
    swi=0;
    ++counter;
    }
    counter_2=0;
    if (swi==1)//We found the file
    else//Check next filename
    {
    ++counter;
    while (main_catalog[counter]!='#' && main_catalog[counter]!='(' && main_catalog[counter]!=')')
    {
    ++counter;
    }
    ++counter;
    }
}

//**********************************

    if (string_comparison(input,"-create")==0)
    {
        gets(input);//Name of file
        scanf("%d",&f_d);//File or catalog
        while (counter<SIZE_MAX && main_catalog[counter]!='\0')
        {
            ++counter;
        }
        if (f_d==1)
        {
            while (input[counter_copy]!='\0' && main_catalog[counter]=='\0')
            {
                main_catalog[counter]=input[counter_copy];
                ++counter;
                ++counter_copy;
            }
            //Place for files in catalog*************
            if(main_catalog[counter]!='\0' && input[counter_copy]!='\0')
            {
                printf("Not enough space to create a directory!\n");
            }
            else
            {
            counter_copy=counter+200;
            while (counter_2<200)
            {
                main_catalog[counter_copy]=main_catalog[counter];
                main_catalog[counter]='\0';
                --counter_copy;
                --counter;
                ++counter_2;
            }
            }
            counter_copy=0;
            //***************************************
        }
        if (f_d==0)
        {
            while (input[counter_copy]!='\0')
            {
                main_catalog[counter]=input[counter_copy];
                ++counter;
                ++counter_copy;
            }
            if(main_catalog[counter]!='\0' && input[counter_copy]!='\0')
            {
                printf("Not enough space to create a file!\n");
            }
            counter_copy=0;

        }
    }

    if (string_comparison(input,"-delete")==0)
    {
        gets(input);//Name of file
        while ((counter<SIZE_MAX)   //Search filename
        {
            ++counter;
        }
        counter_2=index;//read the index
        while (main_catalog[counter]!='#')//erase file from array
        {
            main_catalog[counter]=='\0';
            ++counter;
        }
        while (FAT_table[counter_2]!=/*number of end*/)//erase file from FAT_table
        {
            counter_2=FAT_table[counter_2];
            FAT_table[counter_2]=0;
        }
    }

    if (string_comparison(input,"-open")==0)
    {
        count_cluster=0;
        SEARCH
        while (count<...)//search attributes
        {
            if (main_catalog[counter]=='/')
            {
                ++count;
            }
            ++counter;
        }
        while (main_catalog[counter]!='/' && swi==0)//check attributes
        {
            if()
            if()
            if()...
            ++counter;
        }
        if (swi=...)//write the file into a table of open files and assign it a value descriptor
        {
            counter=0;
            while (table_opened_files[counter].descriptor!=3)
            {
                ++counter;
            }
            table_opened_files[counter].clusters=count_cluster;
            string_copy(table_opened_files[counter].file_name,input);
            table_opened_files[counter].memory_addr=counter;
            count=0;
            if ()
            table_opened_files[counter].descriptor=0;
            if ()
            table_opened_files[counter].descriptor=1;
            ...
        }
    }

    if (string_comparison(input,"-close")==0)
    {
        counter=0;
        while (string_comparison(table_opened_files[counter].file_name,input)!=0)//find the entry in the table
        {
            ++counter;
        }
        counter_2=table_opened_files[counter].clusters;
        counter_3-table_opened_files[counter].memory_addr;
        while (clusters>0)//Clears the memory
        {
            fast_memory[counter_3]=0;
            --counter_3;
        }
        table_opened_files[counter].descriptor=3;//mark, indicating that the cell is empty
    }

    if (string_comparison(input,"-seek")==0)
    {
        counter_2=table_opened_files[counter].memory_addr;//take a memory location from the table
        count=table_opened_files[counter].clusters;
        counter_3-=count;
        while (seek>0) //count bytes
        {
            --seek;
            ++counter_3;
        }
    }

    if (string_comparison(input,"-read")==0)
    {
        while (count<...)//search number of cluster
        {
            if (main_catalog[counter]=='/')
            {
                ++count;
            }
            ++counter;
        }
        counter_2=index;
        while (FAT_table[counter_2].index!=-1)//load the file into memory
        {
            while (fast_memory[counter]!=0)
            {
                ++counter;
            }
            while(FAT_table[counter_2].index!=-1)
            {
                if (fast_memory[counter]!=0)
                {
                    printf("Out of memory!");
                }
                fast_memory[counter]=FAT_table[counter_2].file;
                counter_2=FAT_table[counter_2].index;
                ++counter;
                ++count_cluster;
            }

            ++counter;
        }
        swi_2=0;
    }

    return 0;
}
