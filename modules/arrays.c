#include "Arrayss.h"
#include "funcRand.h"
#include <stdio.h>
#include <stdlib.h>




  void array_input (int array[size_max], int size)
    {
        size-=1;
          while (size>=0)
     {
        scanf("%d",&array[size]);
        --size;
     }
    }


    void array_input_random (int array[size_max], int size)
    {
        size-=1;
          while (size>=0)
     {
        array[size]=randomS();
        --size;
     }
    }


    void array_output (int array[size_max],int size)
    {
        size-=1;
          while (size>=0)
     {
        printf("%d",array[size]);
        --size;
     }
    }


        int array_search_Element (int array[size_max],int size,int number)
    {
        int counter=size-1;
          while (counter>=0)
     {
         if (number==array[size])
         {
             return counter;
         }
        --counter;
     }
     return -1;
    }


int array_search_Max (int array[size_max],int size)
    {
        int num_1,num_2,result=0;
        size-=1;
          while (size)
     {
         num_1=array[size];
        --size;
        if (size>=0)
        {
          num_2=array[size];
          --size;
        }
       if (num_1>num_2 && num_1>result)
       {
        result=num_1;
       }
      if (num_2>num_1 && num_2>result)
       {
        result=num_2;
       }
      if (num_1==num_2 && num_1>result)
       {
        result=num_1;
       }
     }
     return result;
    }


 int array_search_Min (int array[size_max],int size)
    {
        int num_1,num_2,result=0;
        size-=1;
          while (size)
     {
         num_1=array[size];
        --size;
        if (size>0)
        {
          num_2=array[size];
          --size;
        }
       if (num_1>num_2 && num_2<result)
       {
        result=num_2;
       }
      if (num_2>num_1 && num_1<result)
       {
        result=num_1;
       }
      if (num_1==num_2 && num_1<result)
       {
        result=num_1;
       }
     }
     return result;
    }


