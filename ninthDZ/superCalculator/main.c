#include <stdio.h>
#include <stdlib.h>

int main()
{
    int swi,check,h1,swi1=1;;
	double k,l,result;
	char h;
   while (swi1)
   {
     swi=1;
     printf("List arithmetic (Only double!):\n1.(+)\n2.(-)\n3.(*)\n4.(/)\n5.(c-a fresh start)\n6.(e-to complete the program)\n");
     printf("Enter the first operand\n");
	 scanf("%lf",&k);
	 result=k;
	 printf("\n");
    while (swi)
    {
	 printf("Enter arithmetic operation or =:\n");
	 fflush(stdin);
	 h=getchar();
	 h1=h;
     printf("\n");
	 switch (h1)
		{case 43:
     printf("Enter next operand:\n");
	 scanf("%lf",&l);
     printf("\n");
     result+=l;
	 break;
		case 45:
     printf("Enter next operand:\n");
	 scanf("%lf",&l);
     printf("\n");
     result-=l;
		break;
		case 42:
     printf("Enter next operand:\n");
	 scanf("%lf",&l);
     printf("\n");
     result*=l;
		break;
		case 47:
     printf("Enter next operand:\n");
	 scanf("%lf",&l);
     printf("\n");
     result/=l;
		break;
		case 61:
     printf("result: %fl\n",result);
     printf("Do you want to make another operation? yes(1)/no(2)\n");
	 scanf("%d",&check);
	 switch (check)
	 {case 1:
	 swi=0;
	 break;
	 case 2:
     swi1=0;
     swi=0;
     printf("The program is completed\n");
     break;
	 }
        break;
     case 67:
     swi=0;
        break;
     case 69:
        swi=0;
        swi1=0;
        printf("The program is completed\n");
        break;
	}
    }
   }
	system("pause");
	return 0;
}
