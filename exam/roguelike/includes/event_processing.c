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
        printw("\n\t�� �������� � ��������:\n");
        printw("\t%-10s\t������ ����\n",hero_main->name);
        printw("\t�����  %d\t�����  %d\n",hero_main->hit_points,enemy_main->hit_points);
        printw("\t����   %d\t����   %d\n",hero_main->mana_points,enemy_main->mana_points);
        printw("\t����   %d\t����   %d\n",hero_main->damage,enemy_main->damage);
        printw("\t������ %d\t������ %d\n\n",hero_main->armor,enemy_main->armor);
        printw("\t���� ��������:\n");
        printw("\n\t1-���������.\n");
        if (hero_main->specialization==3)
            printw("\t2-��������� ���������� '�������� ���'.\n");
        if (swi!=2)
            printw("\t3-���������� �������.\n");
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
                printw("\n\t�� �������� ���������� %d ��. ����� � ����������� �� ��������� �����.\n",damage_result_hero);
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
                printw("\n\t�� �������� ���������� %d ��. �����. �������� ���� ������� ��� %d ��. �����.\n",damage_result_hero,damage_result_enemy);
                hero_main->hit_points-=damage_result_enemy;
                if (hero_main->hit_points<1)
                {
                    attron(COLOR_PAIR(2));
                    printw("\n\t�� ������...\n");
                    alive_dead=0;
                    swi=0;
                }
                refresh();
                getch();
            }
            else
            {
                attron(COLOR_PAIR(2));
                printw("\n\t�� �������� ���������� %d ��. ����� � ����������� ���.\n",damage_result_hero);
                hero_main->experience+=(25+hero_main->exp_bonus);
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
                printw("\n\t�� ����������� ���������� � �� ������ ���������� �������� ���� ����� ����\n");
                hero_main->experience+=(25+hero_main->exp_bonus);
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
                printw("\n\t(�����) �� ���������� ������ � ����� ��� ������� ���������� �� ������ ����������.\n");
                refresh();
                getch();
                swi=0;
            }
            else
            {
                attron(COLOR_PAIR(2));
                printw("\n\t(�������) �� ������� �������� �������������� � ��� �� ������� ���� �� �������������.\n");
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
    return alive_dead;
}


int trap_processing(hero*hero_main)
{
    char check_input;
    clear();
    if (hero_main->mechanics<=10)
    {
            hero_main->hit_points-=5;
            printw("\n\n\t����������� ������� � �� ��������� 5 ��. �����.\n");
            if (hero_main->hit_points<1)
            {
                attron(COLOR_PAIR(2));
                printw("\n\t�� ������...\n");
                refresh();
                getch();
                return 2;
            }
            refresh();
            getch();
            return 1;
    }
    attron(COLOR_PAIR(2));
    printw("\n\t�� ������ ����� ����� �������.\n");
    attron(COLOR_PAIR(3));
    printw("\n\t1-(��������) ���������� ����������� �������.\n");
    printw("\n\t2-������ ������. (������������ �������.)\n");
    printw("\n\t3-������.\n");
    refresh();
    while (1)
    {
        check_input=getch();
        if (check_input>48 && check_input<52)
            clear();
        switch(check_input)
        {
        case 49:
            if (hero_main->mechanics>15)
            {
                printw("\n\n\t(�����) ����������� ��������� ����� - �� �������������� �������.\n");
                refresh();
                getch();
                return 1;
            }
            else
            {
                if (hero_main->mechanics<13)
                {
                    hero_main->hit_points-=5;
                    printw("\n\n\t(����������� �������) ������� ����������� - �� ��������� 5 ��. �����.\n");
                    if (hero_main->hit_points<1)
                    {
                        attron(COLOR_PAIR(2));
                        printw("\n\t�� ������...\n");
                        refresh();
                        getch();
                        return 2;
                    }
                    refresh();
                    getch();
                    return 1;
                }
                else
                {
                    printw("\n\n\t(�������) ��� �� ������� ����������� �������.\n");
                    refresh();
                    getch();
                    return 0;
                }
            }
            break;
        case 50:
            hero_main->hit_points-=5;
            printw("\n\n\t������� ����������� - �� ��������� 5 ��. �����.\n");
            if (hero_main->hit_points<1)
            {
                attron(COLOR_PAIR(2));
                printw("\n\t�� ������...\n");
                refresh();
                getch();
                return 2;
            }
            refresh();
            getch();
            return 1;
            break;
        case 51:
            return 0;
            break;
        }
    }
}


void level_up(hero*hero_main)
{
    int points=0;
    char check_input=0;
    hero_main->level+=1;
    if (hero_main->level%2!=0)
    {
        points=1;
    while (points>0)
    {
        clear();
        attron(COLOR_PAIR(5));
        printw("\n\t�� �������� ���������� ������!");
        attron(COLOR_PAIR(2));
        printw("\n\n\t�������� �����: %d",points);
        attron(COLOR_PAIR(3));
        printw("\n\n\t1-����         %d",hero_main->strength);
        printw("\n\t2-��������     %d",hero_main->dexterity);
        printw("\n\t3-���������    %d",hero_main->intellect);
        printw("\n\t4-�������      %d",hero_main->charisma);
        printw("\n\t5-������������ %d",hero_main->endurance);
        printw("\n\t6-��������     %d",hero_main->wisdom);
        //printw("\n\t������ - ������� 0: %d\n\n");
        refresh();
        check_input=0;
        check_input=getch();
        switch (check_input)
        {
        case 49:
            --points;
            hero_main->damage+=1;
            hero_main->strength+=1;
            break;
        case 50:
            --points;
            hero_main->dexterity+=1;
            break;
        case 51:
            --points;
            hero_main->mana_points_max+=1;
            hero_main->intellect+=1;
            break;
        case 52:
            --points;
            hero_main->charisma+=1;
            break;
        case 53:
            --points;
            hero_main->hit_points_max+=1;
            hero_main->endurance+=1;
            break;
        case 54:
            --points;
            hero_main->exp_bonus+=1;
            hero_main->wisdom+=1;
            break;
        }
        if (points>0)
            clear();
        else
        {
            clear();
            attron(COLOR_PAIR(5));
            printw("\n\t�� �������� ���������� ������!");
            attron(COLOR_PAIR(2));
            printw("\n\n\t�������� �����: %d",points);
            attron(COLOR_PAIR(3));
            printw("\n\n\t1-����         %d",hero_main->strength);
            printw("\n\t2-��������     %d",hero_main->dexterity);
            printw("\n\t3-���������    %d",hero_main->intellect);
            printw("\n\t4-�������      %d",hero_main->charisma);
            printw("\n\t5-������������ %d",hero_main->endurance);
            printw("\n\t6-��������     %d",hero_main->wisdom);
            attron(COLOR_PAIR(5));
            printw("\n\n\t������� ����� �������...");
            refresh();
            getch();
            clear();
        }

    }
    }
    points=1+hero_main->intellect/2;
    while (points>0)
    {
        clear();
        attron(COLOR_PAIR(5));
        printw("\n\t�� �������� ���������� ������!",points);
        attron(COLOR_PAIR(2));
        printw("\n\n\t�������� �����: %d",points);
        attron(COLOR_PAIR(3));
        printw("\n\n\t1-����������  %d",hero_main->stealth);
        printw("\n\t2-��������    %d",hero_main->athletics);
        printw("\n\t3-��������    %d",hero_main->mechanics);
        printw("\n\t4-���������   %d",hero_main->survival);
        printw("\n\t5-������      %d",hero_main->knowledge);
        //printw("\n\t������ - ������� 0: %d\n\n");
        refresh();
        check_input=0;
        check_input=getch();
        switch (check_input)
        {
        case 49:
            --points;
            hero_main->stealth+=1;
            break;
        case 50:
            --points;
            hero_main->athletics+=1;
            break;
        case 51:
            --points;
            hero_main->mechanics+=1;
            break;
        case 52:
            --points;
            hero_main->survival+=1;
            break;
        case 53:
            --points;
            hero_main->knowledge+=1;
            break;
        }
        if (points>0)
            clear();
        else
        {
            clear();
            attron(COLOR_PAIR(5));
            printw("\n\t�� �������� ���������� ������!",points);
            attron(COLOR_PAIR(2));
            printw("\n\n\t�������� �����: %d",points);
            attron(COLOR_PAIR(3));
            printw("\n\n\t1-����������  %d",hero_main->stealth);
            printw("\n\t2-��������    %d",hero_main->athletics);
            printw("\n\t3-��������    %d",hero_main->mechanics);
            printw("\n\t4-���������   %d",hero_main->survival);
            printw("\n\t5-������      %d",hero_main->knowledge);
            attron(COLOR_PAIR(5));
            printw("\n\n\t������� ����� �������...",hero_main->wisdom);
            refresh();
            getch();
            clear();
        }
    }
    hero_main->experience-=hero_main->next_level;
    hero_main->next_level*=2;
    hero_main->hit_points=hero_main->hit_points_max;
    hero_main->mana_points=hero_main->mana_points_max;
}
