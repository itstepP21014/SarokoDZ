
int randomS ()
{
    static int n=1;
   int x,a=4096,c=150889,m=714025;
   x=(a*n+c)%m;
   n=x;
   return x;
}

int randomR ()
{
   static int n_1=1;
   int x,a=6,c=14,m=25;
   x=(a*n_1+c)%m;
   n_1=x;
   return x;
}
