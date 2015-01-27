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

