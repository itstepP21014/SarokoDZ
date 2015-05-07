#include "M_D_H_E.h"

coordinates maze_generator(maze*maze_,int y_size,int x_size,coordinates start_end_loc)
{
    srand(time(NULL));
    int first=0,second=0,x_enter,y_enter,right_left,y_move,x_move,counter_maze=0,counter,swi=0,check=0,count;
    int door_chance,trap_chance;
    while (first<y_size)
    {
        while (second<x_size)
        {
            maze_[x_size*first+second].square='#';
            ++second;
        }
        second=0;
        ++first;
    }

    second=0;
    first=0;
    printf("\n");
    y_enter=rand()%y_size;
    if (y_enter==0 || y_enter==69)
        x_enter=rand()%x_size;
    else
    {
        right_left=rand()%2;
        if (right_left==0)
            x_enter=0;
        else
            x_enter=x_size-1;
    }
    maze_[x_size*y_enter+x_enter].square='x';

    start_end_loc.y_end=y_enter;
    start_end_loc.x_end=x_enter;

    printf ("\ny_enter:%d\n",y_enter);
    if (y_enter==0)
    {
        y_move=y_enter+1;
        x_move=x_enter;
    }
    else if (y_enter==y_size-1)
    {
        y_move=y_enter-1;
        x_move=x_enter;
    }
    else
    {
        y_move=y_enter;
        if (right_left==0)
            x_move=1;
        else
            x_move=x_size-2;
    }
    maze_[x_size*y_move+x_move].square=' ';

    trap_chance=rand()%20;
    if (trap_chance==19)
        maze_[x_size*y_move+x_move].event_enter=1;
    count=x_size*y_size;

    counter=(rand()%151)+count/20;
    while (counter_maze<counter)
    {
        first=rand()%4;
        if (first==0)
        {
            if (x_move-3>0)
            {
                swi=1;
                --x_move;
            }
        }
        if (first==1)
        {
            if (x_move+3<x_size-1)
            {
                swi=1;
                ++x_move;
            }
        }
        if (first==2)
        {
            if (y_move-3>0)
            {
                swi=1;
                --y_move;
            }
        }
        if (first==3)
        {
            if (y_move+3<y_size-1)
            {
                swi=1;
                ++y_move;
            }
        }
        while(check<3 && swi==1)
        {
            if (check==1)
            {
                door_chance=rand()%10;
                if (door_chance==9)
                {
                    if (first==0 || first==1)
                        maze_[x_size*y_move+x_move].square='|';
                    if (first==2 || first==3)
                        maze_[x_size*y_move+x_move].square='_';
                    maze_[x_size*y_move+x_move].door=(rand()%10)+1;
                }
                else
                {
                    trap_chance=rand()%20;
                    if (trap_chance==19)
                        maze_[x_size*y_move+x_move].event_enter=1;
                    maze_[x_size*y_move+x_move].square=' ';
                }
            }
            else
            {
                trap_chance=rand()%20;
                if (trap_chance==19)
                    maze_[x_size*y_move+x_move].event_enter=1;
                maze_[x_size*y_move+x_move].square=' ';
            }
            start_end_loc.y_begin=y_move;
            start_end_loc.x_begin=x_move;
            ++check;
            if (check<3)
            {
                if (first==0)
                {
                    --x_move;
                }
                if (first==1)
                {
                    ++x_move;
                }
                if (first==2)
                {
                    --y_move;
                }
                if (first==3)
                {
                    ++y_move;
                }
            }
        }
        check=0;

        if (swi==1)
        {
            swi=0;
            ++counter_maze;
        }
    }
    return start_end_loc;
}

int doors (int door_check,hero* hero_main,Mix_Chunk*door_wave)
{
    door_wave = Mix_LoadWAV("sound/voice_set_thaos_0008.wav");
    if (door_wave == NULL)
    {
        printf("wave Error\n");
        exit(-1);
    }

    char check_input;
    int chance;
    if (door_check>0)
    {
        clear();
        attron(COLOR_PAIR(2));
        printw("\n\t����� ���� ���������� �����\n");
        attron(COLOR_PAIR(3));
        printw("\n\t1-���������� ������� �����.\n");
        printw("\n\t2-(����) ���������� �������� �����.\n");
        printw("\n\t3-(��������) ���������� �������� �����.\n");
        if (hero_main->specialization==3)
            printw("\n\t4-(���) ���������� ����� ����� �������� �����.\n");
        if (hero_main->keys>0)
            printw("\n\t5-���������� �������� ����� ��������� ������.\n");
        printw("\n\t6-������.\n");
        refresh();
        while (1)
        {
            check_input=getch();
            if (check_input>48 && check_input<55)
            clear();
            switch(check_input)
            {
            case 49:
                if (door_check==10)
                {
                    printw("\n\n\t��� ����� �� ������� � �� ����� ���������� ��.\n");
                    refresh();
                    getch();
                    return 1;
                }
                else
                {
                    printw("\n\n\t����� �������.\n");
                    refresh();
                    getch();
                    return 0;
                }
                break;
            case 50:
                if (hero_main->strength>4)
                {
                    printw("\n\n\t(�����) ����������� ������� ������� �� ��������� �����.\n");
                    refresh();
                    getch();
                    return 1;
                }
                else
                {
                    printw("\n\n\t(�������) ������� �� �� �� �������� �� ����� - ��� �� ���������.\n");
                    refresh();
                    getch();
                    return 0;
                }
                break;
            case 51:
                if (hero_main->mechanics>4)
                {
                    printw("\n\n\t(�����) �� �������� � ������ ���� ������� �� ������� ������.\n");
                    refresh();
                    getch();
                    return 1;
                }
                else
                {
                    printw("\n\n\t(�������) � ��� �� ���������� �������� �����\n");
                    refresh();
                    getch();
                    return 0;
                }
                break;
            case 52:
                if (hero_main->mana_points>=5)
                {
                    if ( Mix_PlayChannel(2, door_wave, 0) == -1 )
                    {
                        printf("Mix_PlayChannel Error\n");
                        exit(-1);
                    }
                    printw("\n\n\t(�����) �� ����������� ���������� � � ����� ��� ��������� �������� �����. ����� ������ �� ����� �������� ���� ��������� �������� ������� � ���� ����.\n");
                    hero_main->mana_points-=5;
                    refresh();
                    getch();
                    Mix_FreeChunk(door_wave);
                    return 1;
                }
                else
                {
                    printw("\n\n\t(� ��� ������������ ����, ����� ���������� ����������).\n");
                    refresh();
                    getch();
                    return 0;
                }
                break;
            case 53:
                if (hero_main->keys>0)
                {
                    chance=rand()%10;
                    hero_main->keys-=1;
                    if (chance==9)
                    {
                        printw("\n\n\t(�����) ���� �������� � ����� � �� ��������� ��.\n");
                        refresh();
                        getch();
                        return 1;
                    }
                    else
                    {
                        printw("\n\n\t(�������) ��� ���� �������� �� �������� ����� ����������� ���� ���, ��� ���� ���������� � �����.\n");
                        refresh();
                        getch();
                        return 0;
                    }
                }
                break;
            case 54:
                return 0;
                break;
            }
        }
    }
    return 0;
}

void create_hero(hero*hero_main)
{
    Mix_Chunk *wave = NULL;

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf("SDL_init Error\n");
        exit(-1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        printf("Mix_OpenAudio Error\n ");
        exit(-1);
    }

    wave = Mix_LoadWAV("sound/The_Drakalor_Oddisey.wav");
    if (wave == NULL)
    {
        printf("wave Error\n");
        exit(-1);
    }

    if ( Mix_PlayChannel(1, wave, 0) == -1 )
    {
        printf("Mix_PlayChannel Error\n");
        exit(-1);
    }
    attron(COLOR_PAIR(6));
    printw("\n\n\t++++++++++++++++++++\n");
    attron(COLOR_PAIR(2));
    printw("\t  welcome to world\n");
    printw("\t      of\n");
    printw("\t  FORGOTTEN REALMS\n");
    attron(COLOR_PAIR(6));
    printw("\t++++++++++++++++++++");
    attron(COLOR_PAIR(4));
    printw("\tbeta v1.0\n\n\n");
    attron(COLOR_PAIR(5));
    printw("\t������� ����� ������� ����� ����������...");
    refresh();
    getch();
    clear();

    //******************
    char check_input;
    int swi=1;
    attron(COLOR_PAIR(2));
    printw ("\n�������� ������������� ������ ���������:\n\n");
    attron(COLOR_PAIR(3));
    printw("\n1-����\t\t2-����������\t3-���\n");
    printw("\n���� +5\t\t�������� +5\t��������� +5\n");
    printw("\n�������� +5\t�������� +5\t������ +5\n");
    printw("\n������ +3\t���������� +5\t���� +20\n");
    printw("\n����� +20\t����� +10\t����� +5\n");
    printw("\n\t\t\t\t���������� '�������� ���'(������� 15 ������ ����� �����)");
    refresh();
    while (swi==1)
    {
        check_input=getch();
        switch(check_input)
        {
        case 49:
            hero_main->specialization=1;
            hero_main->athletics+=5;
            hero_main->hit_points+=20;
            hero_main->strength+=5;
            hero_main->armor+=3;
            hero_main->damage+=5;
            swi=0;
            break;
        case 50:
            hero_main->specialization=2;
            hero_main->hit_points+=10;
            hero_main->dexterity+=5;
            hero_main->mechanics+=5;
            hero_main->stealth+=5;
            swi=0;
            break;
        case 51:
            hero_main->specialization=3;
            hero_main->hit_points+=5;
            hero_main->intellect+=5;
            hero_main->knowledge+=5;
            hero_main->mana_points+=20;
            swi=0;
            break;
        }
    }
    swi=1;
    clear();
    refresh();
    Mix_FreeChunk(wave);
}
