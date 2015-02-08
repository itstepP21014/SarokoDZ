#include "Arrayss.h"
#include "funcRand.h"
#include <stdio.h>
#include <stdlib.h>

int sta_m,fin_m;

  void array_input (int array[size_max], int size)
    {
        size-=1;
        int counter=0;
          while (counter<=size)
     {
        scanf("%d",&array[counter]);
        ++counter;
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


int array_sum (int array[size_max], int size)
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



void checking_brackets (int array_1[])
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




 int array_input_char (char array[size_max], int size)
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


    int array_input_char_BF (unsigned char array[size_max], int size)
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


    int array_BF_processing (unsigned char array[size_max],int array_1[size_max],int array_2[size_max], int size)
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


    int array_BF_BRACKETS (unsigned char array[size_max], int size)
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


     int array_BF_chars (unsigned char array[size_max], int size)
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


    void array_index_BRACKETS (unsigned char array[size_max],int array_2[size_max], int size)
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




void two_dimensional_array_input_one_element_char(char array[][mas_col],int str,int col,char element)
{
    str-=1;
    col-=1;
    int check;
    check=array[str][col];
    if (check!=48 && check!=88)
    {
        array[str][col]=element;
    }
    else
    {
        printf("Невозможно ввести Х в данные координаты!\n");
        system ("pause");
        exit (2);
    }
}


void two_dimensional_array_x0_reaction (char array[][mas_col],int str,int col)
{
    str-=1;
    col-=1;
   char element=48;
   int swi=1,check;
   int c_1=0,c_2=0;
   while (swi==1)
   {
       check=array[c_1][c_2];
       if (check!=48 && check!=120)
       {
         array[c_1][c_2]=element;
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


void two_dimensional_array_output (char array[][mas_col],int str,int col)
{
    col-=1;
    str-=1;
    int swi=1;
   int c_1=0,c_2=0;
          while (swi)
     {
        printf("%c",array[c_1][c_2]);
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


void two_dimensional_array_input_elements (char array[][mas_col],int str,int col,char element)
{
   str-=1;
   col-=1;
   int c_1=0,c_2=0,swi=1;
          while (swi)
     {
      array[c_1][c_2]=element;
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


int check_win_x0 (char array[][mas_col],int str,int col)
{
    char x=120,b=48;
    if (array[0][0]==b && array[1][1]==b && array[2][2]==b)
    {
        return 0;
    }
    if (array[0][0]==x && array[1][1]==x && array[2][2]==x)
    {
        return 1;
    }
    if (array[0][2]==b && array[1][1]==b && array[2][0]==b)
    {
        return 0;
    }
    if (array[0][0]==x && array[0][1]==x && array[0][2]==x)
    {
        return 1;
    }
    if (array[1][0]==x && array[1][1]==x && array[1][2]==x)
    {
        return 1;
    }
    if (array[2][0]==x && array[2][1]==x && array[2][2]==x)
    {
        return 1;
    }
    if (array[0][0]==b && array[0][1]==b && array[0][2]==b)
    {
        return 0;
    }
    if (array[1][0]==b && array[1][1]==b && array[1][2]==b)
    {
        return 0;
    }
    if (array[2][0]==b && array[2][1]==b && array[2][2]==b)
    {
        return 0;
    }
    if (array[0][0]==x && array[1][0]==x && array[2][0]==x)
    {
        return 1;
    }
    if (array[0][1]==x && array[1][1]==x && array[2][1]==x)
    {
        return 1;
    }
    if (array[0][2]==x && array[1][2]==x && array[2][2]==x)
    {
        return 1;
    }
    if (array[0][0]==b && array[1][0]==b && array[2][0]==b)
    {
        return 0;
    }
    if (array[0][1]==b && array[1][1]==b && array[2][1]==b)
    {
        return 0;
    }
    if (array[0][2]==b && array[1][2]==b && array[2][2]==b)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}


  void array_input_reg (int array[size_max], int size)
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


  void array_output_reg (int array[size_max], int size)
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


void array_elements_mustBe_0 (int array[size_max], int size)
{
    size-=1;
    while (size>=0)
    {
        array[size]=0;
        --size;
    }
}

