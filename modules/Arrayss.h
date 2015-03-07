#ifndef ARRAYSS_H_INCLUDED
#define ARRAYSS_H_INCLUDED

#define size_max 1000
#define mas_col 30
#define mas_str 30
extern int sta_m, fin_m;


void array_input (int *,int);
void array_input_random (int *,int);
void array_output (int *,int);
int array_search_Element (int *,int,int);
int array_search_Max (int *,int);
int array_search_Min (int *,int);
int array_search_positive (int *,int);
int array_search_negative (int *,int);
int array_search_Max_parity (int *,int);
int array_search_Min_parity (int *,int);
int array_search_same(int *,int,int);
int array_replacement (int *,int,int,int);
int array_search_MP_dif (int *,int,int);
void array_replacement_2 (int *,int,int,int);
int array_search_same_lenght (int *,int,int);
int array_search_max_one (int *,int);
int array_search_Element_more (int *,int,int);
int array_search_min_many (int *,int);
int array_search_same_x (int *, int);
int array_search_same_lenght_x (int *,int);
int array_sum (int *, int);
void checking_brackets (int *);
int array_input_char (char *, int);
int array_input_char_BF (unsigned char *, int);
int array_BF_processing (unsigned char *,int *,int *, int);
int array_BF_BRACKETS (unsigned char *,int);
void array_index_BRACKETS (unsigned char *,int *, int);
int array_BF_chars (unsigned char *, int);
void array_input_reg (int *, int);
void array_output_reg (int *, int);
void array_elements_mustBe_0 (int *, int);
int count_numbers (int *,int);
int search_min_easy (int *,int);
void mergesort(int *,int);
void check_sortirovka_foolish (int *,int);
void heapSort (int *,int);
void quickSort (int *,int,int);
void insertion_sort (int *,int);
void bubble_sort (int *,int);
void selection_sort (int *,int);
void push (int *,int *,int,int);
void pop (int *);
void onTop (int *,int);
void isEmpty (int *);


void two_dimensional_array_input_one_element_char(char *,int,int,int,char);
void two_dimensional_array_x0_reaction (char *,int,int);
void two_dimensional_array_output (char *,int,int);
void two_dimensional_array_input_elements (char *,int,int,char);
int check_win_x0 (char *,int,int);
int check_win_x0_5_20 (char *,int,int);
void x0_20x20_player_turn (char *,int,int);
void two_in_one (int *,int, int, int *,int);
void two_dimensional_array_input (int *,int,int);
void two_dimensional_array_output_int (int **,int,int);
void two_dimensional_array_output_int_1 (int *,int,int);
void two_dimensional_array_sdvig_horizont (int *,int,int,int);
void two_dimensional_array_sdvig_column (int *,int,int,int);
void two_dimensional_array_x0_reaction_20x20 (char *,int,int);
void two_dimensional_array_input_rand_1 (int *,int,int,int);
void two_dimensional_array_input_rand_2 (int **,int,int,int);
int two_dimensional_array_saddle_point_2 (int **,int *,int,int);
int two_dimensional_array_saddle_point_1 (int *,int *,int,int);

#endif // ARRAYSS_H_INCLUDED

