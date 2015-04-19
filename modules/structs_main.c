#include "structs.h"
#include "string_func.h"

fraction fraction_sum(fraction first,fraction second)
{
int copy;
copy=first.denom;
first.num=first.num*second.denom;
first.denom=first.denom*second.denom;
second.num=second.num*copy;
second.denom=second.denom*copy;
first.num+=second.num;
return first;
}

fraction fraction_div(fraction first,fraction second)
{
int copy;
copy=second.num;
second.num=second.denom;
second.denom=copy;
first.num=first.num*second.num;
first.denom=first.denom*second.denom;
return first;
}

fraction fraction_multiply(fraction first,fraction second)
{
first.num=first.num*second.num;
first.denom=first.denom*second.denom;
return first;
}

fraction fraction_minus(fraction first,fraction second)
{
int copy;
copy=first.denom;
first.num=first.num*second.denom;
first.denom=first.denom*second.denom;
second.num=second.num*copy;
second.denom=second.denom*copy;
first.num-=second.num;
return first;
}

complex_number complex_sum(complex_number c_1,complex_number c_2)
{
c_1.f_n=c_1.f_n+c_2.f_n;
c_1.s_n=c_1.s_n+c_2.s_n;
return c_1;
}

complex_number complex_minus(complex_number c_1,complex_number c_2)
{
c_1.f_n=c_1.f_n-c_2.f_n;
c_1.s_n=c_1.s_n-c_2.s_n;
return c_1;
}

complex_number complex_multiply(complex_number c_1,complex_number c_2)
{
c_1.f_n=(c_1.f_n*c_2.f_n)+(-(c_1.s_n*c_2.s_n));
c_1.s_n=(c_1.f_n*c_2.s_n)+(c_1.s_n*c_2.f_n);
return c_1;
}

complex_number complex_div(complex_number c_1,complex_number c_2)
{
complex_number copy;
copy.f_n=c_2.f_n;
copy.s_n=-c_2.s_n;
complex_multiply(c_1, copy);
complex_multiply(c_2, copy);
c_1.f_n=c_1.f_n/c_2.f_n;
c_1.s_n=c_1.s_n/c_2.f_n;
return c_1;
}


time time_sum(int sec, time t_1)
{
t_1.hours+=sec/3600;
t_1.hours%=24;
sec=sec%3600;
t_1.minutes+=sec/60;
t_1.hours+=t_1.minutes/60;
t_1.minutes%=60;
t_1.hours%=24;
sec=sec%60;
t_1.seconds+=sec;
t_1.minutes+=t_1.seconds/60;
t_1.seconds%=60;
t_1.hours+=t_1.minutes/60;
t_1.minutes%=60;
t_1.hours%=24;
return t_1;
}

int time_difference(time t_1,time t_2)
{
int sec_1,sec_2,dif;
sec_1=t_1.hours*3600+t_1.minutes*60+t_1.seconds;
sec_2=t_2.hours*3600+t_2.minutes*60+t_2.seconds;
dif=sec_1-sec_2;
if (dif<0)
dif=-dif;
return dif;
}

date date_sum(date d_1,int days)
{
int swi=1;
while (swi)
{
if (d_1.month==1 || d_1.month==3 || d_1.month==5 || d_1.month==7 || d_1.month==10 || d_1.month==12 || d_1.month==8)
{
while (d_1.day<32 && days>0)
{
    --days;
    ++d_1.day;
}
if (d_1.month<12 && d_1.day==32)
{
    ++d_1.month;
    d_1.day=1;
}
if (d_1.month==12 && d_1.day==32)
{
    d_1.month=1;
    d_1.day=1;
    ++d_1.year;
}
if (days==0)
    swi=0;
}
if (d_1.month==2 && d_1.year%4==0)
{
 while (d_1.day<30 && days>0)
{
    --days;
    ++d_1.day;
}
if (d_1.day==30)
{
    ++d_1.month;
    d_1.day=1;
}
if (days==0)
    swi=0;
}
if (d_1.month==2 && d_1.year%4!=0)
{
 while (d_1.day<29 && days>0)
{
    --days;
    ++d_1.day;
}
if (d_1.day==29)
{
    ++d_1.month;
    d_1.day=1;
}
if (days==0)
    swi=0;
}
if (d_1.month==4 || d_1.month==6 || d_1.month==9 || d_1.month==11)
{
while (d_1.day<31 && days>0)
{
    --days;
    ++d_1.day;
}
if (d_1.month<12 && d_1.day==31)
{
    ++d_1.month;
    d_1.day=1;
}
if (d_1.month==12 && d_1.day==31)
{
    d_1.month=1;
    d_1.day=1;
    ++d_1.year;
}
if (days==0)
    swi=0;
}
}
return d_1;
}

int date_difference(date d_1,date d_2)
{
int days_1=0,days_2=0;
 while (d_1.year!=1)
 {
    if(d_1.year%4==0)
        days_1+=366;
    else
        days_1+=365;
    --d_1.year;
 }
 while (d_2.year!=1)
 {
    if(d_2.year%4==0)
        days_2+=366;
    else
        days_2+=365;
        --d_2.year;
 }
  while (d_1.month!=1)
 {
if (d_1.month==3 || d_1.month==5 || d_1.month==7 || d_1.month==10 || d_1.month==12 || d_1.month==8)
{
days_1+=31;
--d_1.month;
}
if (d_1.month==2)
{
days_1+=28;
--d_1.month;
}
if (d_1.month==4 || d_1.month==6 || d_1.month==9 || d_1.month==11)
{
    days_1+=30;
    --d_1.month;
}
 }
  while (d_2.month!=1)
 {
if (d_2.month==3 || d_2.month==5 || d_2.month==7 || d_2.month==10 || d_2.month==12 || d_2.month==8)
{
days_2+=31;
--d_2.month;
}
if (d_2.month==2)
{
days_2+=28;
--d_2.month;
}
if (d_2.month==4 || d_2.month==6 || d_2.month==9 || d_2.month==11)
{
    days_2+=30;
    --d_2.month;
}
 }
days_1+=d_1.day;
days_2+=d_2.day;
days_1=days_1-days_2;
if (days_1<0)
    days_1=-(days_1);
 return days_1;
}

int comp(database data_11,database data_22,int number_1,char check_1)
{
int copy_int,copy_int_2;
if (check_1=='b')
{
switch (number_1)
{
    case 1:
    copy_int=string_lenght(data_11.name);
    copy_int_2=string_lenght(data_22.name);
    if (copy_int < copy_int_2)
        return 1;
    else
        return -1;
    break;
    case 2:
    copy_int=string_lenght(data_11.country);
    copy_int_2=string_lenght(data_22.country);
    if (copy_int < copy_int_2)
        return 1;
    else
        return -1;
    break;
    case 3:
    copy_int=string_lenght(data_11.city);
    copy_int_2=string_lenght(data_22.city);
    if (copy_int < copy_int_2)
        return 1;
    else
        return -1;
    break;
    case 4:
    copy_int=string_lenght(data_11.street);
    copy_int_2=string_lenght(data_22.street);
    if (copy_int < copy_int_2)
        return 1;
    else
        return -1;
    break;
    case 5:
    copy_int=string_lenght(data_11.job);
    copy_int_2=string_lenght(data_22.job);
    if (copy_int < copy_int_2)
        return 1;
    else
        return -1;
    break;
    case 6:
    copy_int=data_11.age;
    copy_int_2=data_22.age;
    if (copy_int < copy_int_2)
        return 1;
    else
        return -1;
    break;
    case 7:
    copy_int=data_11.house_number;
    copy_int_2=data_22.house_number;
    if (copy_int < copy_int_2)
        return 1;
    else
        return -1;
    break;
    default:
    return 0;
    break;
}
}
else
{
switch (number_1)
{
    case 1:
    copy_int=string_lenght(data_11.name);
    copy_int_2=string_lenght(data_22.name);
    if (copy_int < copy_int_2)
        return -1;
    if (copy_int==copy_int_2)
        return 0;
    else
        return 1;
    break;
    case 2:
    copy_int=string_lenght(data_11.country);
    copy_int_2=string_lenght(data_22.country);
    if (copy_int < copy_int_2)
        return -1;
    if (copy_int==copy_int_2)
        return 0;
    else
        return 1;
    break;
    case 3:
    copy_int=string_lenght(data_11.city);
    copy_int_2=string_lenght(data_22.city);
    if (copy_int < copy_int_2)
        return -1;
    if (copy_int==copy_int_2)
        return 0;
    else
        return 1;
    break;
    case 4:
    copy_int=string_lenght(data_11.street);
    copy_int_2=string_lenght(data_22.street);
    if (copy_int < copy_int_2)
        return -1;
    if (copy_int==copy_int_2)
        return 0;
    else
        return 1;
    break;
    case 5:
    copy_int=string_lenght(data_11.job);
    copy_int_2=string_lenght(data_22.job);
    if (copy_int < copy_int_2)
        return -1;
    if (copy_int==copy_int_2)
        return 0;
    else
        return 1;
    break;
    case 6:
    copy_int=data_11.age;
    copy_int_2=data_22.age;
    if (copy_int < copy_int_2)
        return -1;
    if (copy_int==copy_int_2)
        return 0;
    else
        return 1;
    break;
    case 7:
    copy_int=data_11.house_number;
    copy_int_2=data_22.house_number;
    if (copy_int < copy_int_2)
        return -1;
    if (copy_int==copy_int_2)
        return 0;
    else
        return 1;
    break;
    default:
    return 0;
    break;
}
}
}

void qs(database* s_arr, int first, int last,int num,char original,int (*comp)(database,database,int,char))
{
    database data_4;
    database data_5;
    char check=original;
    int number=num;
    int i = first, j = last;
    data_5=s_arr[(first + last)/2];
    do {
        data_4=s_arr[i];
        while (comp(data_4,data_5,number,check)>0)
        {
            i++;
            data_4=s_arr[i];
        }
        data_4=s_arr[j];
        while (comp(data_4,data_5,number,check)<0)
        {
            j--;
            data_4=s_arr[j];
        }

        if(i <= j) {
            data_4=s_arr[i];
            data_5=s_arr[j];
            if (comp(data_4,data_5,number,check)<0)
            {
               s_arr[i]=data_5;
               s_arr[j]=data_4;
            }
            i++;
            j--;
        }
    } while (i<=j);

    if (i < last)
    {
        int (*p)(database,database,int,char);
        p=comp;
        qs(s_arr, i, last,number,original,p);
    }
    if (first<j)
    {
        int (*p)(database,database,int,char);
        p=comp;
        qs(s_arr, first, j,number,original,p);
    }
}

