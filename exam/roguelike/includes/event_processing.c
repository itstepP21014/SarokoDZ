#include "M_D_H_E.h"

int battle_processing(hero*hero_main,enemy*enemy_main,Mix_Chunk* spell_wav,Mix_Chunk* battle_wav)
{
    Mix_FreeChunk(battle_wav);
    battle_wav = Mix_LoadWAV("sound/mus_combat_f.wav");
    if (battle_wav == NULL)
    {
        printf("wav Error\n");
        exit(-1);
    }
    spell_wav = Mix_LoadWAV("sound/voice_set_thaos_0008.wav");
    if (spell_wav == NULL)
    {
        printf("wav Error\n");
        exit(-1);
    }
    if ( Mix_PlayChannel(1, battle_wav, 0) == -1 )
    {
        printf("Mix_PlayChannel Error\n");
        exit(-1);
    }
    char check_input=0;
    int swi=1,dobge_chance,alive_dead=1,damage_result_hero=1,damage_result_enemy=1;

    while (swi>0)
    {
        clear();
        attron(COLOR_PAIR(6));
        printw("\tВы вступили в сражение:\n");
        printw("\t%-10s\tскелет воин\n",hero_main->name);
        printw("\tЖизнь  %d\tЖизнь  %d\n",hero_main->hit_points,enemy_main->hit_points);
        printw("\tМана   %d\tМана   %d\n",hero_main->mana_points,enemy_main->mana_points);
        printw("\tУрон   %d\tУрон   %d\n",hero_main->damage,enemy_main->damage);
        printw("\tЗащита %d\tЗащита %d\n\n",hero_main->armor,enemy_main->armor);
        printw("\tВаши действия:\n");
        printw("\n\t1-Атаковать.\n");
        if (hero_main->specialization==3)
            printw("\t2-Прочитать заклинание 'Огненный шар'.\n");
        if (swi!=2)
            printw("\t3-Попытаться убежать.\n");
        refresh();
        dobge_chance=rand()%101;
        check_input=getch();
        switch(check_input)
        {
        case 49:
            if (hero_main->damage>enemy_main->armor)
            {
                damage_result_hero=hero_main->damage-enemy_main->armor;
            }
            enemy_main->hit_points-=damage_result_hero;
            if ((dobge_chance+hero_main->dexterity)>100 && enemy_main->hit_points>0)
            {
                attron(COLOR_PAIR(2));
                printw("\n\tВы наносите противнику %d ед. урона и уклоняетесь от ответного удара.\n",damage_result_hero);
                refresh();
                getch();
            }
            else if (enemy_main->hit_points>0)
            {
                if (enemy_main->damage>hero_main->armor)
                {
                    damage_result_enemy=enemy_main->damage-hero_main->armor;
                }
                attron(COLOR_PAIR(2));
                printw("\n\tВы наносите противнику %d ед. урона. Ответный удар наносит вам %d ед. урона.\n",damage_result_hero,damage_result_enemy);
                hero_main->hit_points-=damage_result_enemy;
                if (hero_main->hit_points<1)
                {
                    attron(COLOR_PAIR(2));
                    printw("\n\tВы умерли...\n");
                    alive_dead=0;
                    refresh();
                    getch();
                    swi=0;
                }
                refresh();
                getch();
            }
            else
            {
                attron(COLOR_PAIR(2));
                printw("\n\tВы наносите противнику %d ед. урона и уничтожаете его.\n");
                refresh();
                getch();
                swi=0;
            }
            break;
        case 50:
            if (hero_main->specialization==3)
            {
                if ( Mix_PlayChannel(2, spell_wav, 0)==-1)
                {
                    printf("Mix_PlayChannel Error\n");
                    exit(-1);
                }
                enemy_main->hit_points-=15;
                attron(COLOR_PAIR(2));
                hero_main->mana_points-=5;
                printw("\n\tВы произносите заклинание и от вашего противника остается лишь кучка золы\n");
                refresh();
                getch();
                swi=0;
            }
            break;
        case 51:
            if (hero_main->dexterity>10)
            {
                alive_dead=2;
                attron(COLOR_PAIR(2));
                printw("\n\t(Успех) Вы достаточно быстры и скоро вам удается оторваться от вашего противника.\n");
                refresh();
                getch();
                swi=0;
            }
            else
            {
                attron(COLOR_PAIR(2));
                printw("\n\t(Неудача) Вы слишком медленно передвигаетесь и вам не удается уйти от преследования.\n");
                refresh();
                getch();
                swi=2;
            }
            break;
        }
    }
    Mix_FreeChunk(spell_wav);
    Mix_FreeChunk(battle_wav);
    battle_wav = Mix_LoadWAV("sound/mus_dungeon_temple_of_skean.wav");
    getch();
    return alive_dead;
}
