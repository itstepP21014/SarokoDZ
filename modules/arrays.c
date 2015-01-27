extern int array_1[];

  void array_input (int size)
    {
          while (size>=0)
     {
        scanf("%d",&array_1[size]);
        --size;
     }
    }


    void array_output (int size)
    {
          while (size>=0)
     {
        printf("%d",array_1[size]);
        --size;
     }
    }


        int array_search_Element (int size,int number)
    {
        int check=size;
          while (size)
     {
         if (number==array_1[size])
         {
             check-=size;
             ++check;
             return check;
         }
        --size;
     }
     return -1;
    }


int array_search_Max (int size)
    {
        int num_1,num_2,result=0;
          while (size)
     {
         num_1=array_1[size];
        --size;
        if (size>0)
        {
          num_2=array_1[size];
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


 int array_search_Min (int size)
    {
        int num_1,num_2,result=0;
          while (size)
     {
         num_1=array_1[size];
        --size;
        if (size>0)
        {
          num_2=array_1[size];
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


