#ifndef ARRAYSS_H_INCLUDED
#define ARRAYSS_H_INCLUDED

#define size_max 1000
#define mas_col 100
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
int array_search_min_many (int [size_max],int);
int array_search_same_x (int [size_max], int);
int array_search_same_lenght_x (int [size_max],int);
int array_sum (int [size_max], int);
void checking_brackets (int [size_max]);
int array_input_char (char [size_max], int);
int array_input_char_BF (unsigned char [size_max], int);
int array_BF_processing (unsigned char [size_max],int [size_max],int [size_max], int);
int array_BF_BRACKETS (unsigned char [size_max],int);
void array_index_BRACKETS (unsigned char [size_max],int [size_max], int);
int array_BF_chars (unsigned char [size_max], int);
void array_input_reg (int [size_max], int);
void array_output_reg (int [size_max], int);
void array_elements_mustBe_0 (int [size_max], int);

void two_dimensional_array_input_one_element_char(char [][mas_col],int,int,char);
void two_dimensional_array_x0_reaction (char [][mas_col],int,int);
void two_dimensional_array_output (char [][mas_col],int,int);
void two_dimensional_array_input_elements (char [][mas_col],int,int,char);
int check_win_x0 (char [][mas_col],int,int);

#endif // ARRAYSS_H_INCLUDED

