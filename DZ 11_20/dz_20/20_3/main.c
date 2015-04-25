#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/useful_stuff.h"

int main()
{
    FILE *file;
    int vertices,edges,counter=0,first,second,swi=1,top_count=1,begin=0,end=1;

        file=fopen("graf_data.txt","r");
        if (file==0)
        {
            printf("Cant open file!\n");
            return 1;
        }
        fscanf(file,"%d %d",&vertices,&edges);
        int matrix[vertices][vertices],tops[vertices],result[vertices];

        while (counter<vertices)
        {
            tops[counter]=1;
            ++counter;
        }
        counter=0;

        first=0;
        second=0;
        while (first<vertices)
        {
            while (second<vertices)
            {
                matrix[first][second]=0;
                ++second;
            }
            second=0;
            ++first;
        }

        printf ("counter top:%d\n",vertices);
        while (counter<edges)
        {
            fscanf(file,"\r\n%d %d",&first,&second);
            matrix[first-1][second-1]=1;
            matrix[second-1][first-1]=1;
            printf ("edges:%d %d\n",first,second);
            ++counter;
        }
        counter=0;
        fclose(file);

        first=0;
        second=0;
        printf("\n");
        counter=0;
        first=0;
        second=0;
        tops[first]=0;
        printf("into the deep:%d ",top_count);

        graf_deep(&matrix[0][0],vertices,tops);

        printf("\n");
        file=fopen("graf_data.txt","r");
        if (file==0)
        {
            printf("Cant open file!\n");
            return 1;
        }
        fscanf(file,"%d %d",&vertices,&edges);

        while (counter<vertices)
        {
            tops[counter]=1;
            result[counter]=0;
            ++counter;
        }
        counter=0;

        first=0;
        second=0;
        while (first<vertices)
        {
            while (second<vertices)
            {
                matrix[first][second]=0;
                ++second;
            }
            second=0;
            ++first;
        }

        while (counter<edges)
        {
            fscanf(file,"\r\n%d %d",&first,&second);
            matrix[first-1][second-1]=1;
            matrix[second-1][first-1]=1;
            printf ("edges:%d %d\n",first,second);
            ++counter;
        }
        counter=0;
        fclose(file);

        first=0;
        second=0;
        printf("\n");
        counter=0;
        first=0;
        second=0;
        tops[first]=0;
        printf("\nin width:%d ",top_count);
        int v_copy=vertices-1;
        int counter_2=0;
        counter=0;
        swi=1;

    graf_width(&matrix[0][0],vertices,result);

    return 0;
}
