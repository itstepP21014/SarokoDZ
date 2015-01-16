
void translation (int number, int degree)
 {
   int numberCopy=number;
   int count=0,var1,residue1,resultOfTheDivision,countChange;
      while(numberCopy)
    {
     ++count;
     numberCopy=numberCopy/10;
    }
    count+=10;
    countChange=count;
    printf("\n");
    while (resultOfTheDivision)
    {
       residue1=number%degree;
       resultOfTheDivision=number/degree;
       number=resultOfTheDivision;
           while (count)
           {
               printf(" ");
               --count;
           }
           --countChange;
           count=countChange;
           switch (residue1)
           {
           case 10:
               var1=65;
               printf("%c",var1);
               break;
           case 11:
               var1=66;
               printf("%c",var1);
               break;
           case 12:
               var1=67;
               printf("%c",var1);
               break;
            case 13:
               var1=68;
               printf("%c",var1);
               break;
            case 14:
               var1=69;
               printf("%c",var1);
               break;
            case 15:
               var1=70;
               printf("%c",var1);
               break;
            case 16:
               var1=71;
               printf("%c",var1);
               break;
            case 17:
               var1=72;
               printf("%c",var1);
               break;
            case 18:
               var1=73;
               printf("%c",var1);
               break;
            case 19:
               var1=74;
               printf("%c",var1);
               break;
            case 20:
               var1=75;
               printf("%c",var1);
               break;
            case 21:
               var1=76;
               printf("%c",var1);
               break;
            case 22:
               var1=77;
               printf("%c",var1);
               break;
            case 23:
               var1=78;
               printf("%c",var1);
               break;
            case 24:
               var1=79;
               printf("%c",var1);
               break;
            case 25:
               var1=80;
               printf("%c",var1);
               break;
            case 26:
               var1=81;
               printf("%c",var1);
               break;
            case 27:
               var1=82;
               printf("%c",var1);
               break;
            case 28:
               var1=83;
               printf("%c",var1);
               break;
            case 29:
               var1=84;
               printf("%c",var1);
               break;
            case 30:
               var1=85;
               printf("%c",var1);
               break;
            case 31:
               var1=86;
               printf("%c",var1);
               break;
            case 32:
               var1=87;
               printf("%c",var1);
               break;
            case 33:
               var1=88;
               printf("%c",var1);
               break;
            case 34:
               var1=89;
               printf("%c",var1);
               break;
            case 35:
               var1=90;
               printf("%c",var1);
               break;
           default:
               printf("%d",residue1);
               break;
           }
           printf ("\r");
    }
    printf ("Result:\n");
    system("pause");
}



