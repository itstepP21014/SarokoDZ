#include "mathx.h"
int NOD(int line, int column)
{
      while (line%column!=0)
   {
       int c=line%column;
       line=column;
       column=c;
   }
   return column;
}

