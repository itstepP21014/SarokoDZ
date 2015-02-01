#include "Arrayss.h"
#include "funcRand.h"
#include <stdio.h>
#include <stdlib.h>

int sta_m,fin_m;

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
         if (number==array[counter])
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
          while (size>=0)
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
          while (size>=0)
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


    int array_search_positive (int array[size_max],int size)
    {
        int num_1,counter=0;
        size-=1;
          while (counter<=size)
     {
         num_1=array[counter];
        if (num_1>0)
        {
          return counter;
        }
       ++counter;
     }
     return -1;
    }



    int array_search_negative (int array[size_max],int size)
    {
        int num_1,result=-1,counter=0;
        size-=1;
          while (counter<=size)
     {
         num_1=array[counter];
        if (num_1<0)
        {
          result=counter;
        }
       ++counter;
     }
     return result;
    }


    int array_search_Max_parity (int array[size_max],int size)
    {
        int num_1,result=1;
        size-=1;
        num_1=array[size];
        if (num_1%2==0)
        result=num_1;
          while (size>0)
     {
        --size;
        num_1=array[size];
        if (result<num_1 && num_1%2==0)
        {
         result=num_1;
        }
     }
     return result;
    }

     int array_search_Min_parity (int array[size_max],int size)
    {
        int num_1,result=2;
        size-=1;
        num_1=array[size];
        if (num_1%2!=0)
        result=num_1;
          while (size>0)
     {
        --size;
        num_1=array[size];
        if (result>num_1 && num_1%2!=0)
        {
         result=num_1;
        }
     }
     return result;
    }

     int array_search_same (int array[size_max],int size,int number)
    {
        int counter=size-1;
          while (counter>=0)
     {
         if (number==array[counter])
         {
             array[counter]=counter;
         }
        --counter;
     }
     return 0;
    }


    int array_replacement (int array[size_max],int size,int max,int min)
    {
        int counter=size-1;
          while (counter>=0)
     {
         if (array[counter]%2==0)
         {
             array[counter]=max;
         }
         else
         {
             array[counter]=min;
         }
        --counter;
     }
     return 0;
    }


 int array_search_MP_dif (int array[size_max],int size,int number)
    {
        int counter=0,result=-1;
        size-=1;
          while (counter<=size)
     {
         if (array[counter]>0)
         {
            if (array[counter]%number==0 && array[counter]%2==0)
          {
             result=counter;
          }
         }
        ++counter;
     }
     return result;
    }


 void array_replacement_2 (int array[size_max],int size,int index_1,int index_2)
    {
        int num_1,num_2;
        num_1=array[index_1];
        num_2=array[index_2];
        array[index_1]=num_2;
        array[index_2]=num_1;
    }

int array_search_same_lenght (int array[size_max],int size,int number)
{
  size-=1;
  int counter=0,lenght=0,lenghtCopy=0,swi=0,swi_1=0,sta,fin;
  int result=0;
  while (counter<=size)
  {
      if (array[counter]==number && swi==0)
      {
          sta=counter;
          ++lenght;
          ++swi_1;
          swi=1;
          result=1;
      }
      else
      {
       if (array[counter]==number)
       {
          ++lenght;
          ++swi_1;
       }
      }

      if (array[counter+1]!=number && swi==1)
      {
        fin=counter;
          if (lenght>lenghtCopy)
          {
           sta_m=sta;
           fin_m=fin;
          }
        swi=0;
        lenghtCopy=lenght;
        lenght=0;
      }
     ++counter;
  }
  if (swi_1>1)
  {
      result=2;
  }
  return result;
}

int array_search_max_one (int array[size_max],int size)
{
    int num_1,result=0;
    int counter=size-1;
  while (counter>=0)
  {
    num_1=array[counter];
    if (result<num_1 && array_search_Element_more (array,size,num_1)==1)
    {
        result=num_1;
    }
    --counter;
  }
  return result;
}

int array_search_Element_more (int array[size_max],int size,int number)
    {
        int result=0;
        int counter=size-1;
          while (counter>=0)
     {
         if (number==array[counter])
         {
             ++result;
         }
        --counter;
     }
     return result;
    }


    int array_search_min_many (int array[size_max],int size)
{
    int num_1,result=0,swi_1=0;
    int counter=size-1;
  while (counter>=0)
  {
    num_1=array[counter];
    if (array_search_same_lenght (array,size,num_1)>1 && swi_1==0)
    {
        result=num_1;
        swi_1=1;
    }
    if (array_search_same_lenght (array,size,num_1)>1 && result>num_1)
    {
        result=num_1;
    }
    --counter;
  }
  return result;
}


 int array_search_same_x (int array[size_max], int size)
    {
        int check[1000],num_1,result=0,counter=size-1,swi_1=0,counter_1=0,counter_1C,swi_2=0;

          while (counter>=0)
     {
        num_1=array[counter];
        if (array_search_Element_more (array,size,num_1)>1)
        {

            if (swi_1==1)
            {
                while (swi_2==0 && counter_1C>=0)
                {
                    if (check[counter_1C]==num_1)
                    {
                       swi_2=1;
                    }
                    --counter_1C;
                }
                 if (swi_2==0)
                 {
                   check[counter_1]=num_1;
                   ++result;
                   counter_1C=counter_1;
                   ++counter_1;
                 }
                 else
                 {
                    swi_2=0;
                    counter_1C=counter_1;
                 }
            }
            if (swi_1==0)
            {
                check[counter_1]=num_1;
                swi_1=1;
                counter_1C=counter_1;
                ++counter_1;
                ++result;
            }
        }
        --counter;
     }
     return result;
    }


int array_search_same_lenght_x (int array[size_max],int size)
{
  size-=1;
  int counter=0,lenght=0,lenghtCopy=0,swi=0,num_1;
  while (counter<=size)
  {
      num_1=array[counter];
      if (array[counter]==num_1 && swi==0)
      {
          ++lenght;
          swi=1;
      }
      else
      {
       if (array[counter]==num_1)
       {
          ++lenght;
       }
      }

      if (array[counter+1]!=num_1 && swi==1)
      {
        swi=0;
        if (lenghtCopy<lenght)
        {
         lenghtCopy=lenght;
        }
        lenght=0;
      }
     ++counter;
  }
  return lenghtCopy;
}




