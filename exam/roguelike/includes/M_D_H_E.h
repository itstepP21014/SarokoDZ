#ifndef ALL_ARRAYS_H_INCLUDED
#define ALL_ARRAYS_H_INCLUDED

#if defined(__linux__)
#include <ncurses.h>
#endif

#if defined(_WIN32) || defined(_WIN64)
#include <curses.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <string.h>
#include "../../../modules/compatibility.h"

typedef struct hero
{
    char name[11];
    int specialization;
    int experience;
    int exp_bonus;
    int level;
    int next_level;
    int hit_points;
    int mana_points;
    int damage;
    int armor;
    int stealth;
    int mechanics;
    int knowledge;
    int athletics;
    int strength;
    int intellect;
    int dexterity;
    int keys;
    int charisma;
    int wisdom;
    int perception;
    int survival;
    int endurance;
}hero;

typedef struct enemy
{
    int experience;
    int hit_points;
    int mana_points;
    int damage;
    int armor;
}enemy;

typedef struct coordinates
{
    int y_begin;
    int x_begin;
    int y_end;
    int x_end;
}coordinates;

typedef struct maze
{
    char square;
    int visibility;
    int event_search;
    int event_enter;
    int enemy_enter;
    int door;
}maze;

coordinates maze_generator(maze*,int,int,coordinates);
void event_generator(int*,int,int);
void create_hero(hero*);
int doors(int,hero*,Mix_Chunk*);
int battle_processing(hero*,enemy*,Mix_Chunk*,Mix_Chunk*);

#endif // ALL_ARRAYS_H_INCLUDED
