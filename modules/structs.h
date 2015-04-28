#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <stdbool.h>

struct fraction
{
    int num;
    int denom;
};
struct complex_number
{
    double f_n;
    double s_n;
    char i;
};
struct time
{
    int hours;
    int minutes;
    int seconds;
};
struct date
{
    int year;
    int month;
    int day;
};
struct database
{
    char name[30];
    int age;
    char job[30];
    char country[30];
    char city[30];
    char street[30];
    int house_number;
};
struct symbol
{
    char sym[30];
    bool check;
    double number_m;
    int imp;
};
struct process
{
    int number;
    int time_coming;
    int time_lenght;
};
//FILES**********************
struct file
{
    int file_catalog;
    char file_name[30] ;
    int attributes[8];
    int date_creation[3];
    int date_change[3];
    int size_of_file;
    int first_cluster;
};
typedef struct file file;
struct file_r
{
    int file_catalog;
    char file_name[30];
    int attributes[8];
    int date_creation[3];
    int date_change[3];
    int size_of_file;
    int first_cluster;
    file array_files[100];
};
typedef struct file_r file_r;

struct file_open
{
    char file_name[30];
    int descriptor;
    int memory_addr;
    int clusters;
};

typedef struct file_open file_open;
//***********************************
typedef struct complex_number complex_number;
typedef struct fraction fraction;
typedef struct time time;
typedef struct date date;
typedef struct database database;
typedef struct symbol symbol;
typedef struct process process;
process p_1;
process p_2;
symbol s_1;
symbol s_2;
database data_1;
database data_2;
database data_3;
date d_1;
date d_2;
time t_1;
time t_2;
complex_number c_1;
complex_number c_2;
fraction first;
fraction second;
fraction fraction_sum(fraction,fraction);
fraction fraction_div(fraction,fraction);
fraction fraction_multiply(fraction,fraction);
fraction fraction_minus(fraction,fraction);
complex_number complex_sum(complex_number,complex_number);
complex_number complex_minus(complex_number,complex_number);
complex_number complex_div(complex_number,complex_number);
complex_number complex_multiply(complex_number,complex_number);
time time_sum (int,time);
int time_difference (time,time);
date date_sum(date,int);
int date_difference(date,date);
int comp(database,database,int,char);
void qs(database* ,int,int,int,char,int (*comp)(database,database,int,char));
int delete_file(file_r*,char*,char*,int);


#endif // STRUCTS_H_INCLUDED
