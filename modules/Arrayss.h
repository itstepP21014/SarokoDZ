#ifndef ARRAYSS_H_INCLUDED
#define ARRAYSS_H_INCLUDED

#define size_max 1000
extern int sta_m, fin_m;


void array_input (int [size_max],int);
void array_input_random (int [size_max],int);
void array_output (int [size_max],int);
int array_search_Element (int [size_max],int,int);
int array_search_Max (int [size_max],int);
int array_search_Min (int [size_max],int);
int array_search_positive (int [size_max],int);
int array_search_negative (int [size_max],int);
int array_search_Max_parity (int [size_max],int);
int array_search_Min_parity (int [size_max],int);
int array_search_same(int [size_max],int,int);
int array_replacement (int [size_max],int,int,int);
int array_search_MP_dif (int [size_max],int,int);
void array_replacement_2 (int [size_max],int,int,int);
int array_search_same_lenght (int [size_max],int,int);
int array_search_max_one (int [size_max],int);
int array_search_Element_more (int [size_max],int,int);

#endif // ARRAYSS_H_INCLUDED

