#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "../../../modules/structs.h"
#include "../../../modules/string_func.h"

int main()
{
    FILE *file;
    char *fname="database.bin";
    char enter[30]="empty;",check_sort;

    string_copy(data_1.name,enter);
    string_copy(data_1.country,enter);
    string_copy(data_1.job,enter);
    string_copy(data_1.city,enter);
    string_copy(data_1.street,enter);
    data_1.age=1250044;
    data_1.house_number=122;
    int counter=0,check=100,swi=1,counter_2=0,counter_3=0,check_new=0,counter_copy,number,swi_2=0;
    database pages[1000];
    data_3=data_1;
    int (*p)(database,database,int,char);
    p=comp;
    while (counter!=50)
    {
        pages[counter]=data_1;
        ++counter;
    }
    counter=0;
    printf("List of commands:\n-load - load the database file\n-save - save database in file\n-new - create new record\n");
    printf("-delete\n'number' - remove record from database\n-print - display the contents of a database\n");
    printf("-sort\n'number'\n'direction' - Sorting a database on line 'number' ascending(+) or descending(-) order(direction can be + or -).\n");
    printf("-help - type this to see list of commands\n-exit - end of program\n");
while (swi)
{
        scanf("%s",&enter);
        fflush(stdin);
//Checks of commands
        if (string_comparison(enter,"-load")==0)
        check=0;
        if (string_comparison(enter,"-save")==0)
        check=1;
        if (string_comparison(enter,"-new")==0)
        check=2;
        if (string_comparison(enter,"-delete")==0)
        check=3;
        if (string_comparison(enter,"-print")==0)
        check=4;
        if (string_comparison(enter,"-sort")==0)
        check=5;
        if (string_comparison(enter,"-help")==0)
        check=6;
        if (string_comparison(enter,"-exit")==0)
        return 0;

//Write in binary file
    if (check==1)
    {
        file=fopen(fname,"wb");
        if(file==0)
        {
            printf("Cant save database!\n",fname);
            swi=0;
        }
        if (check_new!=1)
            printf("\nError: no data!\n(You must create at least one record in database to unlock this operation)\n");
        if (swi==1 && check_new==1)
        {
            counter=counter_2;
            fwrite(&counter,sizeof(counter),1,file);
        while (counter_2>=0)
        {
            data_1=pages[counter_2];
            fwrite(&data_1,sizeof(database),1,file);
            --counter_2;
        }
        counter_2=0;
            fclose(file);
        }
        swi=1;
    }
//Read from binary file
    if (check==0)
    {
        file=fopen(fname,"rb");
        if(file==0)
        {
            printf("Cant open file! '%s'\n",fname);
            swi=0;
        }
        if (swi==1)
        {
            swi_2=1;
            check_new=1;
            fread(&counter,sizeof (counter),1,file);
            counter_copy=counter;
            counter_2=0;
            while (counter!=0)
            {
                fread(&data_1,sizeof (database),1,file);
                pages[counter_2]=data_1;
                ++counter_2;
                --counter;
            }
            counter=counter_copy;
            fclose(file);
        }
        swi=1;
    }
//Create new record (struct)
    if (check==2)
    {
        check_new=1;
        printf("\nrecord creation:\nName:");
        scanf("%s",&data_1.name);
        fflush(stdin);
        printf("\n");
        printf("Country:");
        scanf("%s",&data_1.country);
        fflush(stdin);
        printf("\n");
        printf("City:");
        scanf("%s",&data_1.city);
        fflush(stdin);
        printf("\n");
        printf("Street:");
        scanf("%s",&data_1.street);
        fflush(stdin);
        printf("\n");
        printf("Job:");
        scanf("%s",&data_1.job);
        fflush(stdin);
        printf("\n");
        printf("Age:");
        scanf("%d",&data_1.age);
        fflush(stdin);
        printf("\n");
        printf("House number:");
        scanf("%d",&data_1.house_number);
        fflush(stdin);
        printf("\n");
        data_2=pages[counter_2];
        if (swi_2==0)
        {
            pages[counter_2]=data_1;
            swi_2=1;
        }
        else
        {
            ++counter_2;
            pages[counter_2]=data_1;
        }
    }
//Delete record.
    if (check==3)
    {
        scanf("%d",&number);
        fflush(stdin);
        pages[number-1]=pages[counter_2];
        pages[counter_2]=data_3;
        --counter_2;
    }
//Print records
    if (check==4)
    {
        if (check_new!=1)
            printf("You must first either create at least one record or upload a database file.");
        while (counter_3<=counter_2 && check_new==1)
        {
            data_1=pages[counter_3];
            printf("---%d---\n",counter_3+1);
            printf("name:%s\ncountry:%s\ncity:%s\nstreet:%s\njob:%s\nhouse number:%d\nage:%d\n",data_1.name,data_1.country,data_1.city,data_1.street,data_1.job,data_1.house_number,data_1.age);
            ++counter_3;
        }
        counter_3=0;
    }
//Sorting
    if (check==5)
    {
        printf("enter the number of the field for sorting(1-7):\n");
        scanf("%d",&number);
        fflush(stdin);
        if (number<1 || number>7)
        {
            printf ("Invalid number!\n");
            swi=0;
        }
        printf("enter the sort direction (along the length of a string or integer value) (+) - ascending (-) - descending:\n");
        scanf("%c",&check_sort);
        fflush(stdin);
        if (check_sort!='-' && check_sort!='+')
        {
            printf ("Invalid operation!\n");
            swi=0;
        }
        if (check_sort=='+')
        check_sort='b';
        if (check_sort=='-')
        check_sort='e';
        if (swi==1)
        {
            qs(pages,0,counter_2,number,check_sort,p);
        }
        swi=1;
    }
//HELP
        if (check==6)
    {
        printf("List of commands:\n-load - load the database file\n-save - save database in file\n-new - create new record\n");
        printf("-delete\n'number' - remove record from database\n-print - display the contents of a database\n");
        printf("-sort\n'number'\n'direction' - Sorting a database on line 'number' ascending(+) or descending(-) order(direction can be + or -.\n");
        printf("-help - type this to see list of commands\n-exit - end of program\n");
    }
}
    return 0;
}
