#include "M_D_H_E.h"

coordinates maze_generator(maze*maze_,int y_size,int x_size,coordinates start_end_loc)
{
    srand(time(NULL));
    int first=0,second=0,x_enter,y_enter,right_left,y_move,x_move,counter_maze=0,counter,swi=0,check=0,count;
    int door_chance,trap_chance,skeleton_warrior_chance;
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
    skeleton_warrior_chance=rand()%20;
    trap_chance=rand()%25;
    if (trap_chance==24)
        maze_[x_size*y_move+x_move].square='t';
    else if (skeleton_warrior_chance==19)
        maze_[x_size*y_move+x_move].square='s';
    else
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
                    trap_chance=rand()%25;
                    skeleton_warrior_chance=rand()%20;
                    if (trap_chance==24)
                        maze_[x_size*y_move+x_move].square='t';
                    else if (skeleton_warrior_chance==19)
                        maze_[x_size*y_move+x_move].square='s';
                    else
                        maze_[x_size*y_move+x_move].square=' ';
                }
            }
            else
            {
                trap_chance=rand()%25;
                skeleton_warrior_chance=rand()%20;
                if (trap_chance==24)
                    maze_[x_size*y_move+x_move].square='t';
                else if (skeleton_warrior_chance==19)
                    maze_[x_size*y_move+x_move].square='s';
                else
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
    maze_[x_size*start_end_loc.y_begin+start_end_loc.x_begin].square=' ';
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
        printw("\n\tПеред вами деревянная дверь\n");
        attron(COLOR_PAIR(3));
        printw("\n\t1-Попытаться открыть дверь.\n");
        printw("\n\t2-(Сила) Попытаться выломать дверь.\n");
        printw("\n\t3-(Механика) Попытаться взломать дверь.\n");
        if (hero_main->specialization==3)
            printw("\n\t4-(Маг) Попытаться сжечь дверь огненным шаром.\n");
        if (hero_main->keys>0)
            printw("\n\t5-Попытаться отпереть дверь найденным ключом.\n");
        printw("\n\t6-Отойти.\n");
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
                    printw("\n\n\tЭта дверь не заперта и вы легко открываете ее.\n");
                    refresh();
                    getch();
                    return 1;
                }
                else
                {
                    printw("\n\n\tДверь заперта.\n");
                    refresh();
                    getch();
                    return 0;
                }
                break;
            case 50:
                if (hero_main->strength>4)
                {
                    printw("\n\n\t(Успех) Несколькими мощными ударами вы вышибаете дверь.\n");
                    refresh();
                    getch();
                    return 1;
                }
                else
                {
                    printw("\n\n\t(Неудача) Сколько бы вы не колотили по двери - она не поддается.\n");
                    refresh();
                    getch();
                    return 0;
                }
                break;
            case 51:
                if (hero_main->mechanics>4)
                {
                    printw("\n\n\t(Успех) Вы возитесь с замком пока наконец не слышите щелчок.\n");
                    refresh();
                    getch();
                    return 1;
                }
                else
                {
                    printw("\n\n\t(Неудача) У вас не получается взломать замок\n");
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
                    printw("\n\n\t(Успех) Вы произносите заклинание и с ваших рук срывается огненная сфера. После взрыва от двери остается лишь несколько железных прутьев и куча золы.\n");
                    hero_main->mana_points-=5;
                    refresh();
                    getch();
                    Mix_FreeChunk(door_wave);
                    return 1;
                }
                else
                {
                    printw("\n\n\t(У вас недостаточно маны, чтобы произнести заклинание).\n");
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
                        printw("\n\n\t(Успех) Ключ подходит к двери и вы отпираете ее.\n");
                        refresh();
                        getch();
                        return 1;
                    }
                    else
                    {
                        printw("\n\n\t(Неудача) Все ваши старания по открытию двери завершаются лишь тем, что ключ застревает в замке.\n");
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
    int points=1,points_copy,attr_p=10,attr_copy=10;
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
    printw("\tНажмите любую клавишу чтобы продолжить...");

    refresh();
    getch();
    clear();

    //******************
    char check_input;
    int swi=1;
    attron(COLOR_PAIR(2));
    printw ("\nВыберите специализацию своего персонажа:\n\n");
    attron(COLOR_PAIR(3));
    printw("\n1-Воин\t\t\t2-Авантюрист\t\t3-Маг\n");
    printw("\nсила +5\t\t\tЛовкость +5\t\tИнтеллект +5\n");
    printw("\nатлетика +5\t\tмеханика +5\t\tзнание +5\n");
    printw("\nзащита +3\t\tскрытность +5\t\tмана +20\n");
    printw("\nЖизнь +20\t\tЖизнь +10\t\tЖизнь +5\n");
    printw("\n\t\t\t\t\t\tзаклинание 'Огненный шар'(наносит 15 единиц урона огнем)");
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
    while (attr_p>0)
    {
        attron(COLOR_PAIR(2));
        printw("\n\tОсталось очков: %d\n\n",attr_p);
        attron(COLOR_PAIR(3));
        printw("\t1-Сила         %d\n",hero_main->strength);
        printw("\t2-Ловкость     %d\n",hero_main->dexterity);
        printw("\t3-Интеллект    %d\n",hero_main->intellect);
        printw("\t4-Харизма      %d\n",hero_main->charisma);
        printw("\t5-Выносливость %d\n",hero_main->endurance);
        printw("\t6-Мудрость     %d\n",hero_main->wisdom);
        //printw("\n\tОтмена - клавиша 0: %d\n\n");
        refresh();
        check_input=0;
        check_input=getch();
        switch (check_input)
        {
        case 49:
            --attr_p;
            hero_main->damage+=1;
            hero_main->strength+=1;
            break;
        case 50:
            --attr_p;
            hero_main->dexterity+=1;
            break;
        case 51:
            --attr_p;
            hero_main->mana_points+=1;
            hero_main->intellect+=1;
            break;
        case 52:
            --attr_p;
            hero_main->charisma+=1;
            break;
        case 53:
            --attr_p;
            hero_main->hit_points+=1;
            hero_main->endurance+=1;
            break;
        case 54:
            --attr_p;
            hero_main->exp_bonus+=1;
            hero_main->wisdom+=1;
            break;
        }
        if (attr_p>0)
            clear();
        else
        {
            clear();
            attron(COLOR_PAIR(2));
            printw("\n\tОсталось очков: %d\n\n",attr_p);
            attron(COLOR_PAIR(3));
            printw("\t1-Сила         %d\n",hero_main->strength);
            printw("\t2-Ловкость     %d\n",hero_main->dexterity);
            printw("\t3-Интеллект    %d\n",hero_main->intellect);
            printw("\t4-Харизма      %d\n",hero_main->charisma);
            printw("\t5-Выносливость %d\n",hero_main->endurance);
            printw("\t6-Мудрость     %d\n",hero_main->wisdom);
            attron(COLOR_PAIR(5));
            printw("\n   Нажмите любую клавишу...",hero_main->wisdom);
            refresh();
            getch();
            clear();
        }

    }

    points+=hero_main->intellect;
    points_copy=points;
    while (points>0)
    {
        attron(COLOR_PAIR(2));
        printw("\n\tОсталось очков: %d\n\n",points);
        attron(COLOR_PAIR(3));
        printw("\t1-Скрытность  %d\n",hero_main->stealth);
        printw("\t2-Атлетика    %d\n",hero_main->athletics);
        printw("\t3-Механика    %d\n",hero_main->mechanics);
        printw("\t4-Выживание   %d\n",hero_main->survival);
        printw("\t5-Знание      %d\n",hero_main->knowledge);
        //printw("\n\tОтмена - клавиша 0: %d\n\n");
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
            attron(COLOR_PAIR(2));
            printw("\n\tОсталось очков: %d\n\n",points);
            attron(COLOR_PAIR(3));
            printw("\t1-Скрытность  %d\n",hero_main->stealth);
            printw("\t2-Атлетика    %d\n",hero_main->athletics);
            printw("\t3-Механика    %d\n",hero_main->mechanics);
            printw("\t4-Выживание   %d\n",hero_main->survival);
            printw("\t5-Знание      %d\n",hero_main->knowledge);
            attron(COLOR_PAIR(5));
            printw("\n   Нажмите любую клавишу...",hero_main->wisdom);
            refresh();
            getch();
            clear();
        }
    }
    int counter=254;
    char buf[255];
    while (counter>=0)
    {
        buf[counter]='\0';
        --counter;
    }
    swi=1;
    while (swi)
    {
        attron(COLOR_PAIR(6));
        printw("\n\tВведите имя своего персонажа (не более 10 символов):\n\t");
        refresh();
        scanw("%s",&buf);
        fflush(stdin);
        if (strlen(buf)>10)
        {
            attron(COLOR_PAIR(4));
            printw("\n\tСлишком длинное имя - повторите попытку.\n");
            refresh();
            getch();
        }
        else
        {
            strcpy(hero_main->name,buf);
            swi=0;
        }
    }
    clear();
    attron(COLOR_PAIR(2));
    printw("\n\tВаше имя: %s\n",hero_main->name);
    attron(COLOR_PAIR(5));
    printw("\n   Нажмите любую клавишу...",hero_main->wisdom);
    refresh();
    getch();
    clear();
    Mix_FreeChunk(wave);
}
