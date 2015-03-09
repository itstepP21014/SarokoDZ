#include "Arrayss.h"
#include "funcRand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int sta_m,fin_m;

  void array_input (int *array, int size)
    {
        size-=1;
        int counter=0;
          while (counter<=size)
     {
        scanf("%d",&*(array+counter));
        ++counter;
     }
    }


    void array_input_random (int *array, int size)
    {
        size-=1;
          while (size>=0)
     {
        array[size]=randomS();
        --size;
     }
    }


    void array_output (int *array,int size)
    {
        size-=1;
        int counter=0;
        printf("\n");
          while (counter<=size)
     {
        printf("%d  ",*(array+counter));
        ++counter;
     }
    }


        int array_search_Element (int *array,int size,int number)
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


int array_search_Max (int *array,int size)
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


 int array_search_Min (int *array,int size)
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


    int array_search_positive (int *array,int size)
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



    int array_search_negative (int *array,int size)
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


    int array_search_Max_parity (int *array,int size)
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

     int array_search_Min_parity (int *array,int size)
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

     int array_search_same (int *array,int size,int number)
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


    int array_replacement (int *array,int size,int max,int min)
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


 int array_search_MP_dif (int *array,int size,int number)
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


 void array_replacement_2 (int *array,int size,int index_1,int index_2)
    {
        int num_1,num_2;
        num_1=array[index_1];
        num_2=array[index_2];
        array[index_1]=num_2;
        array[index_2]=num_1;
    }

int array_search_same_lenght (int *array,int size,int number)
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

int array_search_max_one (int *array,int size)
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

int array_search_Element_more (int *array,int size,int number)
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


    int array_search_min_many (int *array,int size)
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


 int array_search_same_x (int *array, int size)
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


int array_search_same_lenght_x (int *array,int size)
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


int array_sum (int *array, int size)
    {
        int result=0,num_1;
          while (size>=0)
     {
         num_1=array[size];
        result+=num_1;
        --size;
     }
     return result;
    }



void checking_brackets (int *array_1)
 {

     int brackets_reflection,swi=1,counter=0;
     char brackets;
     while (swi)
     {
        scanf("%c",&brackets);
        brackets_reflection=brackets;
        if (brackets_reflection==35)
        {
            swi=0;
        }
        if (swi==1)
        {
            if (brackets_reflection==41 || brackets_reflection==93 || brackets_reflection==125)
            {
                --counter;
                if ((brackets_reflection-array_1[counter])>5 || counter==-1)
                {
                    printf("Ошибка!\n");
                    system ("pause");
                    exit(1);
                }
                array_1[counter]=0;
            }
            if (brackets_reflection==40 || brackets_reflection==91 || brackets_reflection==123)
            {
                array_1[counter]=brackets_reflection;
                ++counter;
            }
        }
     }
}




 int array_input_char (char *array, int size)
    {
        int counter=0,check,result=0,num_1,num_2,swi=1;
        char put;
          while (counter<=size)
     {
        scanf("%c",&put);
        fflush(stdin);
        check=put;
        if (check>=48 && check<=57)
        {
          array[counter]=put;
                  ++counter;
        }
        if (check==61)
        {
            return result;
        }
        if (check==45)
        {
            num_1=array[counter-2]-48;
            num_2=array[counter-1]-48;
            if (swi==1)
            {
                result=num_1-num_2;
                swi=0;
                array[counter]=0;
                array[counter-1]=0;
                array[counter-2]=0;
                counter-=2;
            }
            else
            {
               result=result-num_2;
                array[counter]=0;
                array[counter-1]=0;
                counter-=1;
            }

        }
         if (check==43)
        {
            num_1=array[counter-2]-48;
            num_2=array[counter-1]-48;
           if (swi==1)
            {
                result=num_1+num_2;
                swi=0;
                array[counter]=0;
                array[counter-1]=0;
                array[counter-2]=0;
                counter-=2;
            }
            else
            {
               result=num_2+result;
                array[counter]=0;
                array[counter-1]=0;
                counter-=1;
            }

        }
        if (check==42)
        {
            num_1=array[counter-2]-48;
            num_2=array[counter-1]-48;
            if (swi==1)
            {
                result=num_1*num_2;
                swi=0;
                array[counter]=0;
                array[counter-1]=0;
                array[counter-2]=0;
                counter-=2;
            }
            else
            {
               result=result*num_2;
                array[counter]=0;
                array[counter-1]=0;
                counter-=1;
            }

        }
        if (check==47)
        {
            num_1=array[counter-2]-48;
            num_2=array[counter-1]-48;
            if (swi==1)
            {
                result=num_1/num_2;
                swi=0;
                array[counter]=0;
                array[counter-1]=0;
                array[counter-2]=0;
                counter-=2;
            }
            else
            {
               result=num_2/result;
                array[counter]=0;
                array[counter-1]=0;
                counter-=1;

            }
        }
     }
     return result;
    }


    int array_input_char_BF (unsigned char *array, int size)
    {
        int counter=0,check;
        unsigned char put;
          while (counter<=size)
     {
        scanf("%c",&put);
        fflush(stdin);
        check=put;
        array[counter]=put;
        if (check==110)
        {
            return counter;
        }
        ++counter;
     }
     return counter-1;
    }


    int array_BF_processing (unsigned char *array,int *array_1,int *array_2, int size)
    {
        int counter=0,counter_1=0,check,result=0,count=-1;
        unsigned char c;
        while (counter<=size)
        {
         array_1[counter]=-1;
         ++counter;
        }
        counter=0;
          while (counter<=size)
     {
        check=array[counter];
        if (check==110)
        {
            return result;
        }
        if (check==43)
        {
          array_1[counter_1]+=1;
          ++counter;
        }
        if (check==44)
        {
          scanf("%c",&array_1[counter_1]);
          ++counter;
        }
        if (check==45)
        {
          array_1[counter_1]-=1;
          ++counter;
        }
        if (check==62)
        {
          counter_1+=1;
          ++counter;
        }
        if (check==60)
        {
          counter_1-=1;
          ++counter;
        }
        if (check==46)
        {
            c=array_1[counter_1];
          printf("%c",c);
          ++counter;
        }
        if (check==93)
        {
            count-=1;
            if (array_1[counter_1]!=0)
            {
                counter=array_2[count]+1;
            }
            if (array_1[counter_1]==0)
            {
               ++counter;
            }
            count+=1;
        }
        if (check==91)
        {
            count+=2;
            if (array_1[counter_1]!=0)
            {
                ++counter;
            }
            if (array_1[counter_1]==0)
            {
              counter=array_2[count]+1;
            }
        }
        if (array_1[counter_1]==256)
        {
          array_1[counter_1]=0;
        }
     }
      return result;
    }


    int array_BF_BRACKETS (unsigned char *array, int size)
    {
        int counter=0,check,check_b=0;
          while (check!=110)
     {
        check=array[counter];
        if (check==91)
        {
            check_b+=1;
        }
        if (check==93)
        {
            check_b-=1;
        }
        ++counter;
     }
     if (check_b!=0)
     {
         return 0;
     }
     else
     {
         return 1;
     }
    }


     int array_BF_chars (unsigned char *array, int size)
    {
        int counter=0,check;
          while (counter<=size)
     {
        check=array[counter];
        if (check!=91)
        {
          if (check!=93)
          {
            if (check!=45)
            {
              if (check!=43)
              {
                if (check!=60)
                {
                 if (check!=62)
                 {
                     if (check!=46)
                     {
                        if (check!=44)
                        {
                          if (check!=110)
                          {
                              return 0;
                          }
                        }
                     }
                 }
                }
              }
            }
          }
        }
        ++counter;
     }
         return 1;
    }


    void array_index_BRACKETS (unsigned char *array,int *array_2, int size)
    {
       int counter_1=0,counter_1C,counter_2=0,count=0,check=0;
       while (check!=110)
       {
           check=array[counter_1];
           if (check==91)
           {
             counter_1C=counter_1;
             array_2[counter_2]=counter_1;
             ++counter_2;
             ++count;
             while (count!=0)
             {
               ++counter_1;
               if (array[counter_1]==91)
               {
                   ++count;
               }
               if (array[counter_1]==93)
               {
                   --count;
               }
             }
             array_2[counter_2]=counter_1;
             ++counter_2;
             counter_1=counter_1C;
           }
           ++counter_1;
       }
    }




void two_dimensional_array_input_one_element_char(char *array,int str_1,int col_1,int col,char element)
{
    int check;
    check=array[str_1*(col)+col_1];
    if (check!=48 && check!=120)
    {
        array[str_1*(col)+col_1]=element;
    }
    else
    {
        printf("Невозможно ввести символ в данные координаты!\n");
        system ("pause");
        exit (2);
    }
}


void two_dimensional_array_x0_reaction (char *array,int str,int col)
{
    str-=1;
    col-=1;
   char element=48;
   int swi=1,check;
   int c_1=0,c_2=0;
   while (swi==1)
   {
       check=array[c_1*(col+1)+c_2];
       if (check!=48 && check!=120)
       {
         array[c_1*(col+1)+c_2]=element;
         swi=0;
       }
       else
       {
           if (c_1<str)
           {
            ++c_1;
           }
           else
           {
               c_1=0;
               if (c_2<col)
               ++c_2;
               else
               swi=0;
           }
       }
   }
}


void two_dimensional_array_output (char *array,int str,int col)
{
    int swi=1;
   int c_1=0,c_2=0;
          while (swi)
     {
        printf("%c",array[c_1*col+c_2]);
          if (c_2<col-1)
           {
            ++c_2;
           }
           else
           {
               printf ("\n");
               c_2=0;
               if (c_1<str-1)
               ++c_1;
               else
               swi=0;
           }
     }
}


void two_dimensional_array_input_elements (char *array,int str,int col,char element)
{
   int c_1=0,c_2=0,swi=1;
          while (swi)
     {
      array[c_1*col+c_2]=element;
          if (c_1<str)
           {
            ++c_1;
           }
           else
           {
               c_1=0;
               if (c_2<col)
               ++c_2;
               else
               swi=0;
           }
     }
}


int check_win_x0 (char *array,int str,int col)
{
    char x=120,b=48,c='#';
    int c_1=0,c_2=0,player=0,comp=0;
    while (c_1<str)
    {
        if (array[c_1*col+c_2]==x)
        {
           ++player;
           comp=0;
        }
        if (array[c_1*col+c_2]==b)
        {
           ++comp;
           player=0;
        }
        if (array[c_1*col+c_2]==c)
        {
           comp=0;
           player=0;
        }
        if (player==3)
        {
        return (1);
        }
        if (comp==3)
        {
        return (0);
        }
        if (c_2<(col-1))
            ++c_2;
            else
        {
            c_2=0;
            ++c_1;
        }
    }
    c_1=0;
    c_2=0;
    comp=0;
    player=0;
        while (c_2<col)
    {
        if (array[c_1*col+c_2]==x)
        {
           ++player;
           comp=0;
        }
        if (array[c_1*col+c_2]==b)
        {
           ++comp;
           player=0;
        }
        if (array[c_1*col+c_2]==c)
        {
           comp=0;
           player=0;
        }
        if (player==3)
        {
        return (1);
        }
        if (comp==3)
        {
        return (0);
        }
        if (c_2<(col-1))
            ++c_1;
            else
        {
            c_1=0;
            ++c_2;
        }
    }
    c_1=0;
    c_2=0;
    comp=0;
    player=0;
    while (c_1<str)
    {
        if (array[c_1*col+c_2]==x)
        {
           ++player;
           comp=0;
        }
        if (array[c_1*col+c_2]==b)
        {
           ++comp;
           player=0;
        }
        if (array[c_1*col+c_2]==c)
        {
           comp=0;
           player=0;
        }
        if (player==3)
        {
        return (1);
        }
        if (comp==3)
        {
        return (0);
        }
        ++c_1;
        ++c_2;
    }
    c_1=str-1;
    c_2=col-1;
    comp=0;
    player=0;
    while (c_1<str)
    {
        if (array[c_1*col+c_2]==x)
        {
           ++player;
           comp=0;
        }
        if (array[c_1*col+c_2]==b)
        {
           ++comp;
           player=0;
        }
        if (array[c_1*col+c_2]==c)
        {
           comp=0;
           player=0;
        }
        if (player==3)
        {
        return (1);
        }
        if (comp==3)
        {
        return (0);
        }
        --c_1;
        --c_2;
    }
    return (2);
}


  void array_input_reg (int *array, int size)
    {
        size-=1;
        int counter=0,reg=0,swi=1,num_1;
    while (swi==1)
     {
        printf("%02d?  ",reg);
        scanf("%d",&num_1);
        if (num_1==-99999)
        {
            swi=0;
        }
        else
        {
         array[counter]=num_1;
         ++counter;
         ++reg;
         if (counter>size)
         {
            swi=0;
         }
        }
     }
    }


  void array_output_reg (int *array, int size)
    {
        printf("memory status:\n");
        size-=1;
        int counter=0,reg=0,check=0;
    while (counter<=size)
     {
        printf("%d\t",reg);
        while (check<10)
        {
         ++check;
         printf("%04d\t",array[counter]);
         ++counter;
        }
        reg+=10;
        check=0;
        printf("\n");
     }
    }


void array_elements_mustBe_0 (int *array, int size)
{
    size-=1;
    while (size>=0)
    {
        array[size]=0;
        --size;
    }
}


void two_in_one (int *array_1,int str, int col, int *array_2,int size)
{
    size-=1;
    str-=1;
    col-=1;
   int sCount=0,cCount=0;
   while (sCount<=str)
   {
     while (cCount<=col)
     {
     array_2[size]=array_1[sCount*(col+1)+cCount];
     ++cCount;
     --size;
     }
     cCount=0;
     ++sCount;
   }
}

int count_numbers (int *array_1,int size)
{
    size-=1;
    int result=0;
    while (size>=0)
    {
        if (array_1[size_max]==0)
        {
            ++result;
        }
        --size;
    }
    return result;
}

int search_min_easy (int *array_1,int size)
{
    size-=1;
  int result,counter=size,swi=1;
  result=array_1[0];
  while (counter>=0)
  {
      if (array_1[counter]<result && array_1[counter]!=0)
      {
          result=array_1[counter];
      }
      --counter;
  }
  counter=size;
  while (counter>=0 && swi==1)
  {
      if (array_1[counter]==result)
      {
          array_1[counter]=0;
          swi=0;
      }
      --counter;
  }

  return result;
}


void two_dimensional_array_input (int *array,int str,int col)
{
  str-=1;
  col-=1;
   int c_1=0,c_2=0;
    while (c_1<=str)
     {
         scanf("%d",&array[c_1*(col+1)+c_2]);
          if (c_2<col)
          {
              ++c_2;
          }
          else
          {
              c_2=0;
              ++c_1;
          }
     }
}


void two_dimensional_array_input_rand_1 (int *array,int str,int col,int max)
{
  str-=1;
  col-=1;
  srand(time(NULL));
   int c_1=0,c_2=0;
    while (c_1<=str)
     {
         array[c_1*(col+1)+c_2]=rand()%max;
          if (c_2<col)
          {
              ++c_2;
          }
          else
          {
              c_2=0;
              ++c_1;
          }
     }
}


void two_dimensional_array_input_rand_2 (int **array,int str,int col,int max)
{
  str-=1;
  col-=1;
  srand(time(NULL));
   int c_1=0,c_2=0;
    while (c_1<=str)
     {
         array[c_1][c_2]=rand()%max;
          if (c_2<col)
          {
              ++c_2;
          }
          else
          {
              c_2=0;
              ++c_1;
          }
     }
}


void two_dimensional_array_output_int (int **array,int str,int col)
{
    col-=1;
    str-=1;
    int swi=1;
   int c_1=0,c_2=0;
          while (swi)
     {
        printf("%d",array[c_1][c_2]);
          if (c_2<col)
           {
            ++c_2;
           }
           else
           {
               printf ("\n");
               c_2=0;
               if (c_1<str)
               ++c_1;
               else
               swi=0;
           }
     }
}


void two_dimensional_array_output_int_1 (int *array,int str,int col)
{
    col-=1;
    str-=1;
    int swi=1;
   int c_1=0,c_2=0;
          while (swi)
     {
        printf("%d",array[c_1*(col+1)+c_2]);
          if (c_2<col)
           {
            ++c_2;
           }
           else
           {
               printf ("\n");
               c_2=0;
               if (c_1<str)
               ++c_1;
               else
               swi=0;
           }
     }
}



void two_dimensional_array_sdvig_horizont (int *array,int str,int col,int number)
{
  str-=1;
  col-=1;
  int sCount=0,cCount=1,memory=0,memory_2=0,swi=0;
  while (number>0)
  {
    while (sCount<=str)
  {
     while (cCount<=col)
     {
         if (swi==0 && cCount==col)
         {
         memory=array[sCount*(col+1)+cCount];
         array[sCount*(col+1)+cCount]=array[sCount*(col+1)+(cCount-1)];
         array[sCount*(col+1)+(cCount-1)]=memory;
         }
         if (swi==0 && cCount!=col)
         {
          memory=array[sCount*(col+1)+cCount];
         array[sCount*(col+1)+cCount]=array[sCount*(col+1)+(cCount-1)];
         }
        if (swi==1 && cCount!=col)
        {
          memory_2=array[sCount*(col+1)+cCount];
          array[sCount*(col+1)+cCount]=memory;
          memory=memory_2;
        }
        if (cCount==col && swi==1)
        {
          memory_2=array[sCount*(col+1)+cCount];
         array[sCount*(col+1)+cCount]=memory;
          array[sCount*(col+1)+0]=memory_2;
        }
        swi=1;
        ++cCount;
     }
     ++sCount;
     cCount=1;
     swi=0;
  }
  --number;
  sCount=0;
  cCount=1;
  }

}


void two_dimensional_array_sdvig_column (int *array,int str,int col,int number)
{
  str-=1;
  col-=1;
  int sCount=1,cCount=0,memory=0,memory_2=0,swi=0;
  while (number>0)
  {
    while (cCount<=col)
  {
     while (sCount<=str)
     {
         if (swi==0 && sCount==str)
         {
         memory=array[sCount*(col+1)+cCount];
         array[sCount*(col+1)+cCount]=array[(sCount-1)*(col+1)+cCount];
         array[(sCount-1)*(col+1)+cCount]=memory;
         }
         if (swi==0 && sCount!=str)
         {
          memory=array[sCount*(col+1)+cCount];
          array[sCount*(col+1)+cCount]=array[(sCount-1)*(col+1)+cCount];
         }
        if (swi==1 && cCount!=col)
        {
          memory_2=array[sCount*(col+1)+cCount];
          array[sCount*(col+1)+cCount]=memory;
          memory=memory_2;
        }
        if (sCount==str && swi==1)
        {
          memory_2=array[sCount*(col+1)+cCount];
          array[sCount*(col+1)+cCount]=memory;
          array[0*(col+1)+cCount]=memory_2;
        }
        swi=1;
        ++sCount;
     }
     ++cCount;
     sCount=1;
     swi=0;
  }
  --number;
  sCount=1;
  cCount=0;
  }
}


void mergesort(int *array,int size)
{
   int memory[size_max],swi=0,swi_1=0,counter=0,copy,counter_1,factor=1,count=0,count_get=0,check_1=0,check_2=0;
   if (size%2==1)
   {
       array[size]=1;
       ++size;
       swi=1;
   }
   if (size%2==0 && (size/2)%2==1)
   {
       array[size]=1;
       array[size+1]=1;
       swi=2;
       size+=2;
   }
   //..................
   while (factor!=size)
   {
    while (counter<size)
    {
    copy=counter;
    counter_1=counter+factor;
    while (check_1+check_2<factor*2 && swi_1==0)
   {
     if (array[counter]<array[counter_1])
     {
         memory[count]=array[counter];
         ++count;
         ++counter;
         ++check_1;
     }
     else
     {
       if (array[counter]>array[counter_1])
      {
        memory[count]=array[counter_1];
        ++count;
        ++counter_1;
        ++check_2;
      }
       else
      {
        memory[count]=array[counter];
        ++count;
        memory[count]=array[counter_1];
        ++count;
        ++counter;
        ++counter_1;
        ++check_1;
        ++check_2;
      }
     }
     if (check_1==factor)
     {
        while (check_2!=factor)
        {
            memory[count]=array[counter_1];
            ++count;
            ++check_2;
            ++counter_1;
        }
        check_2=0;
        swi_1=1;
     }
     if (check_2==factor)
     {
        while (check_1!=factor)
        {
            memory[count]=array[counter];
            ++count;
            ++check_1;
            ++counter;
        }
        check_1=0;
        swi_1=1;
     }
   }
   check_1=0;
   check_2=0;
   swi_1=0;
   while (count>0)
   {
       array[copy]=memory[count_get];
       --count;
       ++copy;
       ++count_get;
   }
   count_get=0;
   counter=copy;
    }
    counter=0;
    factor*=2;
   }
   //..................
   if (swi==1)//Это костыль.
   {
       counter=0;
       while (array[counter]!=1)
       {
           ++counter;
       }
       while (counter!=size)
       {
           array[counter]=array[counter+1];
           ++counter;
       }
   }
    if (swi==2)//Это костыль.
   {
       count=2;
       counter=0;
       while (count>0)
       {
          while (array[counter]!=1)
       {
           ++counter;
       }
       while (counter!=size)
       {
           array[counter]=array[counter+1];
           ++counter;
       }
       --count;
       counter=0;
       }
   }
}



void heapSort (int *array,int size)
{
 int half,counter,memory;
 half=(size/2)-1;
 counter=half;
 while (counter>=0)
 {
    if (array[counter]<array[2*counter+1] && 2*counter+1<size)
       {
           memory=array[counter];
           array[counter]=array[2*counter+1];
           array[2*counter+1]=memory;
       }
    if (array[counter]<array[2*counter+2] && 2*counter+2<size)
        {
           memory=array[counter];
           array[counter]=array[2*counter+2];
           array[2*counter+2]=memory;
        }
       --counter;
 }
--size;
int number=0;
while (size>0)
{
    memory=array[size];
    array[size]=array[number];
    array[number]=memory;
    counter=size/2;
    while (counter>=0)
   {
    if (array[counter]<array[2*counter+1] && 2*counter+1<size)
       {
           memory=array[counter];
           array[counter]=array[2*counter+1];
           array[2*counter+1]=memory;
       }
    if (array[counter]<array[2*counter+2] && 2*counter+2<size)
        {
           memory=array[counter];
           array[counter]=array[2*counter+2];
           array[2*counter+2]=memory;
        }
       --counter;
    }
    --size;
}
}



void check_sortirovka_foolish (int *array,int size)
{
  size-=2;
  int swi=0,swi_2=0,counter=0,count=0,n;
  while (swi==0)
  {
      if (array[counter]<array[counter+1])
      {
          if (swi_2==0)
          {
            printf("Failed\n");
            swi_2=1;
          }
          n=array[counter];
          array[counter]=array[counter+1];
          array[counter+1]=n;
          count=0;
      }
      if (counter==size)
      {
          counter=0;
          count=0;
      }
      else
      {
          ++counter;
          ++count;
      }
     if (count==size)
     {
         printf("array is ready!");
         swi=1;
     }
  }
}


void quickSort (int *array,int first,int last)
{
      int one=first,two=last,memory;
   int center=array[(first+last)/2];
   do
   {
     while (array[one]<center)
     {
         ++one;
     }
     while (array[two]>center)
     {
         --two;
     }
     if (one<=two)
     {
         if (array[one]>array[two])
         {
            memory=array[one];
            array[one]=array[two];
            array[two]=memory;
         }
         ++one;
         --two;
     }
   }while (one<=two);
   if (one<last)
   {
    quickSort (array,one,last);
   }
   if (two>first)
   {
    quickSort (array,first,two);
   }
}


void insertion_sort (int *array,int size)
{
 int count=1,memory,copy;
 while (count<size)
 {
     if (array[count-1]>array[count])
     {
         copy=count;
         memory=array[copy];
         while (copy-1>=0 && array[copy-1]>memory)
         {
           array[copy]=array[copy-1];
           --copy;
         }
         array[copy]=memory;
     }
     ++count;
 }
}


void bubble_sort (int *array,int size)
{
  int count=size-1,copy,memory,max=size-1,counter;
  counter=max;
  while (max>0)
  {
      copy=count;
      while(counter>0)
      {
        if (array[copy]<array[copy-1])
        {
          memory=array[copy];
          array[copy]=array[copy-1];
          array[copy-1]=memory;
        }
        --copy;
        --counter;
      }
        --max;
        counter=max;
  }
}


void selection_sort (int *array,int size)
{
  int memory,count=0,counter=1,copy=1;
  while(count<size-1)
  {
    while (counter<size)
   {
      if (array[count]>array[counter])
      {
          memory=array[count];
          array[count]=array[counter];
          array[counter]=memory;
      }
      ++counter;
   }
   ++copy;
   counter=copy;
   ++count;
  }
}


int check_win_x0_5_20 (char *array,int str,int col)
{
    int colCopy=col-1,strCopy=str-1;
    int swi=1,c_1=0,c_2=0,comp=0,player=0,counter=0,c_1Copy,c_2Copy;
    char b=48,x=120;
  while (c_1<str)
  {
    if (array[c_1*col+c_2]==b)
    {
     player=0;
     ++comp;
    }
    if (array[c_1*col+c_2]==x)
    {
     comp=0;
     ++player;
    }
    if (array[c_1*col+c_2]=='#')
    {
     comp=0;
     player=0;
    }
    if (player==5)
    {
        return (1);
    }
    if (comp==5)
    {
        return (0);
    }
    if (c_2<colCopy)
    {
    ++c_2;
    }
    else
    {
     c_2=0;
     comp=0;
     player=0;
     ++c_1;
    }
  }
  c_1=0;
  c_2=0;
  while (c_2<col)
  {
    if (array[c_1*col+c_2]==b)
    {
     player=0;
     ++comp;
    }
    if (array[c_1*col+c_2]==x)
    {
     comp=0;
     ++player;
    }
    if (array[c_1*col+c_2]=='#')
    {
     comp=0;
     player=0;
    }
    if (player==5)
    {
        return (1);
    }
    if (comp==5)
    {
        return (0);
    }
    if (c_1<strCopy)
    {
    ++c_1;
    }
    else
    {
     comp=0;
     player=0;
     c_1=0;
     ++c_2;
    }
  }
  c_1=0;
  c_1Copy=c_1;
  c_2=4;
  c_2Copy=c_2;
  while (swi!=2)
  {
    if (array[c_1*col+c_2]==b)
    {
     player=0;
     ++comp;
    }
    if (array[c_1*col+c_2]==x)
    {
     comp=0;
     ++player;
    }
    if (array[c_1*col+c_2]=='#')
    {
     comp=0;
     player=0;
    }
    if (player==5)
    {
        return (1);
    }
    if (comp==5)
    {
        return (0);
    }
    if(counter<c_2Copy && swi==1)
    {
            ++c_1;
            --c_2;
            ++counter;
    }
    else
    {
        if (counter<(19-c_1Copy) && swi==0)
        {
            ++c_1;
            --c_2;
            ++counter;
        }
    else
    {
        if (counter<19 && swi==1)
        {
            ++c_2Copy;
            counter=0;
            c_1=0;
            c_2=c_2Copy;
        }
        else
        {
         swi=0;
         ++c_1Copy;
         c_1=c_1Copy;
         c_2=19;
         if (counter==4)
         swi=2;
         counter=0;
        }
    }
    }

  }
  c_1=0;
  c_1Copy=c_1;
  c_2=15;
  c_2Copy=c_2;
  counter=0;
  swi=1;
  while (swi!=2)
  {
    if (array[c_1*col+c_2]==b)
    {
     player=0;
     ++comp;
    }
    if (array[c_1*col+c_2]==x)
    {
     comp=0;
     ++player;
    }
    if (array[c_1*col+c_2]=='#')
    {
     comp=0;
     player=0;
    }
    if (player==5)
    {
        return (1);
    }
    if (comp==5)
    {
        return (0);
    }
    if(counter<(19-c_2Copy) && swi==1)
    {
      ++counter;
      ++c_1;
      ++c_2;
    }
    else
    {
        if (counter<(19-c_1Copy) && swi==0)
        {
            ++counter;
            ++c_1;
            ++c_2;
        }
    else
    {
        if (counter<19 && swi==1)
        {
         counter=0;
         --c_2Copy;
         c_2=c_2Copy;
         c_1=0;
        }
        else
        {
         swi=0;
         c_2=0;
         ++c_1Copy;
         c_1=c_1Copy;
         if (counter==4)
         swi=2;
         counter=0;
        }
    }
    }


  }
  return (2);
}


void two_dimensional_array_x0_reaction_20x20 (char *array,int str,int col)
{
   char element=48;
   int swi=1,c_1,c_2;
   srand(time(NULL));
   while (swi==1)
   {
        c_1=rand()%20;
        c_2=rand()%20;
       if (array[c_1*col+c_2]!=48 && array[c_1*col+c_2]!=120)
       {
         array[c_1*col+c_2]=element;
         swi=0;
       }
   }
}


void x0_20x20_player_turn (char *array,int str,int col)
{
    int str_1,col_1,swi=1;
    char player='x';
while (swi==1)
            {
                printf("\nВведите координаты крестика:\n");
                scanf("%d",&str_1);
                scanf("%d",&col_1);
                if (str_1<20 && col_1<20 && str_1>-1 && col_1>-1)
                {
                    if (array[str_1*col+col_1]!=48 && array[str_1*col+col_1]!=120)
                    {
                      array[str_1*col+col_1]=player;
                      swi=0;
                    }
                }
                else
                {
                  printf("\nВведены неверные координаты!\n");
                }
            }
}


int two_dimensional_array_saddle_point_2 (int **array,int *array_1,int str,int col)
{
int c_1=0,c_2=0,c_11=0,c_2Copy,c_1Copy,c_11Copy,number_1,number_2,counter=0;
int colCopy=col-1,swi=1;
while (c_1<str)
{
 number_1=array[c_1][c_2];
c_2Copy=c_2;
c_1Copy=c_1;
++c_2;
while (counter<(col-1))
{
    if (number_1>array[c_1][c_2])
    {
        number_1=array[c_1][c_2];
        c_2Copy=c_2;
        c_1Copy=c_1;
    }
    ++c_2;
    ++counter;
}
while (swi)
{
number_2=array[c_11][c_2Copy];
c_11Copy=c_11;
++c_11;
while (c_11<str)
{
    if (number_2<array[c_11][c_2Copy])
    {
        number_2=array[c_11][c_2Copy];
        c_11Copy=c_11;
    }
    ++c_11;
}
if (c_1Copy==c_11Copy)
{
    array_1[0]=c_1Copy;
    array_1[1]=c_2Copy;
    return 1;
}
while (colCopy>=0 && array[c_1][colCopy]!=number_1)
{
    --colCopy;
}
if (array[c_1][colCopy]==number_1)
{
c_11=0;
c_2Copy=colCopy;
}
if (colCopy<0)
    swi=0;
    --colCopy;
}
c_2=0;
c_11=0;
counter=0;
++c_1;
swi=1;
}
return 0;
}


int two_dimensional_array_saddle_point_1 (int *array,int *array_1,int str,int col)
{
int c_1=0,c_2=0,c_11=0,c_2Copy,c_1Copy,c_11Copy,number_1,number_2,counter=0;
int colCopy=col-1,swi=1;
while (c_1<str)
{
 number_1=array[c_1*col+c_2];
c_2Copy=c_2;
c_1Copy=c_1;
++c_2;
while (counter<(col-1))
{
    if (number_1>array[c_1*col+c_2])
    {
        number_1=array[c_1*col+c_2];
        c_2Copy=c_2;
        c_1Copy=c_1;
    }
    ++c_2;
    ++counter;
}
while (swi)
{
number_2=array[c_11*col+c_2Copy];
c_11Copy=c_11;
++c_11;
while (c_11<str)
{
    if (number_2<array[c_11*col+c_2Copy])
    {
        number_2=array[c_11*col+c_2Copy];
        c_11Copy=c_11;
    }
    ++c_11;
}
if (c_1Copy==c_11Copy)
{
    array_1[0]=c_1Copy;
    array_1[1]=c_2Copy;
    return 1;
}
while (colCopy>=0 && array[c_1*col+colCopy]!=number_1)
{
    --colCopy;
}
if (array[c_1*col+colCopy]==number_1)
{
c_11=0;
c_2Copy=colCopy;
}
if (colCopy<0)
    swi=0;
    --colCopy;
}
c_2=0;
c_11=0;
counter=0;
++c_1;
swi=1;
}
return 0;
}


void push (int *stack,int *top,int size,int data)
{
    if (*top<size)
    {
    stack[*top]=data;
    ++*top;
    }
    else
    {
    printf("Стек плностью заполнен:\n");
    }
}


void pop (int *top)
{
    if (*top>0)
    {
    --*top;
    }
    else
    {
    printf("Стек пустой:\n");
    }
}


void onTop (int *top,int size)
{
    *top=size-1;
}


void isEmpty (int *top)
{
    *top=0;
}


float bisection_method(float(*func)(float),float epsilon,float check)
{
int swi=1,counter=1000;
float left=-1.0,right=-1.0,half;
while (swi)
{
 if ((*func)(left)>0 && (*func)(right)<0)
 {
    swi=0;
 }
 else
 if ((*func)(right)>0 && (*func)(left)<0)
 {
    swi=0;
 }
 else
 {
    left=left+(-1.0);
    right+=1.0;
 }
}
while (counter)
{
    half=(left+right)/2.0;
    if ((*func)(half)<0 && (*func)(left)<0)
    {
        left=half;
    }
    else
    if((*func)(half)>0 && (*func)(left)>0)
    {
        left=half;
    }
    else
    {
        right=half;
    }
  if ((*func)(half)==check)
    return half;
    --counter;
}
return half;
}
