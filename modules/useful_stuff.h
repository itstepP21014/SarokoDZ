#ifndef USEFUL_STUFF_H_INCLUDED
#define USEFUL_STUFF_H_INCLUDED

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE_MAX 1000

void maze_generator(char*,int,int);
void graf_deep(int*,int,int*);
void graf_width(int*,int,int*);
int UTF8_count_symbols(char*);
void UTF8_codes_of_symbols(char*);
int return_symbol_number(char*,int);

#endif // USEFUL_STUFF_H_INCLUDED
