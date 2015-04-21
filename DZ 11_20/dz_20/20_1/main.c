#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../../modules/structs.h"
#include "../../../modules/numbers.h"
#include "../../../modules/string_func.h"

#define SIZE_MAX 1000

int main()
{
    char expression[SIZE_MAX],operations[SIZE_MAX],main_check;
    int counter_2=0,swi=1,swi_2=0,counter=0,count_br_num=0,interp=0,counter_copy=0;
    double degree,copy_1,copy_2,m_copy=0.0;
    int count_b=0,count_e=0,count=0;
    symbol expt[SIZE_MAX];
    printf("infix calculator\nSupported operations:+-*/ (^)-involution\n");
    printf("!important! You can only use integers, but the result will be, if necessary, in a fractional form.\n");
    while (swi)
    {
        printf("Enter an expression\n");
        gets(expression);
//Check of brackets
        while(expression[counter]!='\0')
        {
            if (expression[counter]=='(')
            ++count_br_num;
            if (expression[counter]==')')
            --count_br_num;
            if (count_br_num<0)
            {
                swi=0;
                printf("Error! (brackets)\n");
                return 1;
            }
            ++counter;
        }
        counter=0;
        if (count_br_num!=0)
        {
            printf("Error! (brackets)\n");
            count_br_num=0;
            return 1;
        }
//Write in massive of structures
        while(swi)
        {
            interp=expression[counter];
            if (interp>47 && interp<58)
            {
                while ((interp>47 && interp<58 && counter_copy<29) || (interp==46 && counter_copy<29))
                {
                    s_1.sym[counter_copy]=expression[counter];
                    ++counter_copy;
                    ++counter;
                    interp=expression[counter];
                }
                while (counter_copy<=29)
                {
                    s_1.sym[counter_copy]='#';
                    ++counter_copy;
                }
                counter_copy=0;
                s_1.number_m=atof(s_1.sym);
                s_1.check=false;
                expt[counter_2]=s_1;
                ++counter_2;
            }
            if (expression[counter]=='^')
            {
                interp=expression[counter-1];
                if (interp>47 && interp<58)
                {
                    s_1=expt[counter_2-1];
                    ++counter;
                    interp=expression[counter];
                    while ((interp>47 && interp<58 && expression[counter]!='\0') || interp==46)
                    {
                        operations[counter_copy]=expression[counter];
                        ++counter;
                        ++counter_copy;
                        interp=expression[counter];
                    }
                    counter_copy=0;
                    degree=atof(operations);
                    s_1.number_m=pow(s_1.number_m,degree);
                    expt[counter_2-1]=s_1;
                }
                else
                {
                    s_1.sym[0]=expression[counter];
                    s_1.check=true;
                    ++counter;
                    expt[counter_2]=s_1;
                    ++counter_2;
                }
            }
            else
            {
                s_1.sym[0]=expression[counter];
                s_1.check=true;
                ++counter;
                expt[counter_2]=s_1;
                ++counter_2;
            }
            if (expression[counter]=='\0')
            swi=0;
        }
        swi=1;
//Calculations
        --counter_2;
        counter=0;
        while (swi)
        {
            count_b=0;
            count_e=counter_2;
            degree=1.0;
            s_1=expt[counter];
            while (swi!=2 && counter<=counter_2)
            {
                ++counter;
                s_1=expt[counter];
                if (s_1.sym[0]==')')
                {
                    swi_2=1;
                    swi=2;
                    count_e=counter;
                    expt[counter].sym[0]='#';
                    expt[counter].imp=1;
                }
            }
            if (swi==2)
            {
                while (s_1.sym[0]!='(')
                {

                    --counter;
                    s_1=expt[counter];
                }
                count_b=counter;
                expt[counter].sym[0]='#';
                expt[counter].imp=1;
                s_2=expt[count_e+1];
                if (s_2.sym[0]=='^')
                {
                    s_2=expt[count_e+2];
                    degree=s_2.number_m;
                }
            }
            swi=1;
            counter=0;
//************
            while (swi)
            {
                swi=1;
                count=count_b+1;
                s_1=expt[count];
                while (s_1.sym[0]!='*' && count<count_e)
                {
                    ++count;
                    s_1=expt[count];
                }
                if (s_1.sym[0]=='*')
                swi=2;
                if (swi==2)
                {
                    expt[count].sym[0]='#';
                    expt[count].imp=1;
                    --count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        --count;
                        s_2=expt[count];
                    }
                    counter_copy=count;
                    copy_1=s_2.number_m;
                    ++count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        ++count;
                        s_2=expt[count];
                    }
                    copy_2=s_2.number_m;
                    copy_1=copy_1*copy_2;
                    s_2.number_m=copy_1;
                    expt[counter_copy]=s_2;
                    expt[count].imp=1;
                }
                else
                {
                    swi=0;
                }

            }
            swi=1;

            while (swi)
            {
                swi=1;
                count=count_b+1;
                s_1=expt[count];
                while (s_1.sym[0]!='/' && count<count_e)
                {
                    ++count;
                    s_1=expt[count];
                }
                if (s_1.sym[0]=='/')
                swi=2;
                if (swi==2)
                {
                    expt[count].sym[0]='#';
                    expt[count].imp=1;
                    --count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        --count;
                        s_2=expt[count];
                    }
                    counter_copy=count;
                    copy_1=s_2.number_m;
                    ++count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        ++count;
                        s_2=expt[count];
                    }
                    copy_2=s_2.number_m;
                    copy_1=copy_1/copy_2;
                    s_2.number_m=copy_1;
                    expt[counter_copy]=s_2;
                    expt[count].imp=1;
                }
                else
                {
                    swi=0;
                }

            }
            swi=1;

            while (swi)
            {
                swi=1;
                count=count_b+1;
                s_1=expt[count];
                while (s_1.sym[0]!='+' && count<count_e)
                {
                    ++count;
                    s_1=expt[count];
                }
                if (s_1.sym[0]=='+')
                swi=2;
                if (swi==2)
                {
                    expt[count].sym[0]='#';
                    expt[count].imp=1;
                    --count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        --count;
                        s_2=expt[count];
                    }
                    counter_copy=count;
                    copy_1=s_2.number_m;
                    ++count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        ++count;
                        s_2=expt[count];
                    }
                    copy_2=s_2.number_m;
                    copy_1=copy_1+copy_2;
                    s_2.number_m=copy_1;
                    expt[counter_copy]=s_2;
                    expt[count].imp=1;
                }
                else
                {
                    swi=0;
                }

            }
            swi=1;

            while (swi)
            {
                swi=1;
                count=count_b+1;
                s_1=expt[count];
                while (s_1.sym[0]!='-' && count<count_e)
                {
                    ++count;
                    s_1=expt[count];
                }
                if (s_1.sym[0]=='-')
                swi=2;
                if (swi==2)
                {
                    expt[count].sym[0]='#';
                    expt[count].imp=1;
                    --count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        --count;
                        s_2=expt[count];
                    }
                    counter_copy=count;
                    copy_1=s_2.number_m;
                    ++count;
                    s_2=expt[count];
                    while (s_2.check!=false || s_2.imp==1)
                    {
                        ++count;
                        s_2=expt[count];
                    }
                    copy_2=s_2.number_m;
                    copy_1=copy_1-copy_2;
                    s_2.number_m=copy_1;
                    expt[counter_copy]=s_2;
                    expt[count].imp=1;
                }
                else
                {
                    swi=0;
                }

            }
            copy_1=pow(copy_1,degree);
            m_copy=copy_1;
            s_2.number_m=copy_1;
            expt[counter_copy]=s_2;
            swi=1;
            if (swi_2==0)
            swi=0;
            swi_2=0;
        }
        swi=1;
        printf ("\nresult:%f\n",copy_1);
        printf("Want to solve another expression? (y)-yes\n");
        scanf("%c",&main_check);
        fflush(stdin);
        if (main_check=='y')
        swi=1;
        else
        swi=0;
    }
    return 0;
}
