#include <stdio.h>
#include <stdlib.h>

int main()
{
    int swi=1,check,h1;
	double k,l;
	char h;
    while (swi)
    {
     printf("List arithmetic (Only double!):\n1(+)\n2(-)\n3(*)\n4(/)\n");
     printf("Enter the first operand\n");
	 scanf("%lf",&k);
	 printf("\n");
	 printf("Enter arithmetic operation:\n");
	 fflush(stdin);
	 h=getchar();
	 h1=h;
     printf("\n");
	 printf("Enter the second operand\n");
	 scanf("%lf",&l);
     printf("\n result:");
	 switch (h1)
		{case 43:
	 printf("%fl\n",k+l);
	 break;
		case 45:
	 printf("%fl\n",k-l);
		break;
		case 42:
	 printf("%fl\n",k*l);
		break;
		case 47:
	 printf("%fl\n",k/l);
		break;
	}
	 printf("Do you want to make another operation? yes(1)/no(2)\n");
	 scanf("%d",&check);
	 switch (check)
	 {case 1:
	 swi=1;
	 case 2:
        swi=0;
		printf("The program is completed\n");
	 }
    }
	system("pause");
	return 0;
}
