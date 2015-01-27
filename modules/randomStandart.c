
int randomS (int y)
{
   int x,a=4096,c=150889,m=714025;
   x=(a*y+c)%m;
   return x;
}

int randomR (int y)
{
   int x,a=6,c=14,m=25;
   x=(a*y+c)%m;
   return x;
}
