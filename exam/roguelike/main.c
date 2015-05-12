
#include "includes/M_D_H_E.h"


int main(int argc,char* argv[])
{
    /*  int ttt=0;
      scanf("%d",&ttt);
      if (SDL_Init(SDL_INIT_VIDEO) != 0)
      {
          printf("SDL_Init Error!\n");
          return 1;
      }



      SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 210, 330, SDL_WINDOW_SHOWN);
      if (win==NULL)
      {
          printf("SDL_CreateWindow Error!\n");
          SDL_Quit();
          return 1;
      }

      SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (ren==NULL)
      {
          SDL_DestroyWindow(win);
          printf("SDL_CreateRenderer Error!\n");
          SDL_Quit();
          return 1;
      }

      SDL_Surface *bmp = SDL_LoadBMP("pics/EDWINL.bmp");

      if(bmp == NULL)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
          SDL_Quit();
          exit(1);
      }

      SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
      SDL_FreeSurface(bmp);

      if(tex == NULL)
      {
          SDL_DestroyRenderer(ren);
          SDL_DestroyWindow(win);
          fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n",
                  SDL_GetError());
          SDL_Quit();
          exit(1);
      }

      SDL_RenderClear(ren);
      SDL_Rect srcrect;
      SDL_Rect dstrect;

      srcrect.x = 50;
      srcrect.y = 50;
      srcrect.w = 60;
      srcrect.h = 60;
      dstrect.x = 110;
      dstrect.y = 110;
      dstrect.w = 60;
      dstrect.h = 60;

      //Draw the texture
      SDL_RenderCopy(ren, tex, NULL, NULL);
      //Update the screen
      SDL_RenderPresent(ren);
      //Have the program wait for 2000ms so we get a chance to see the screen
      while (ttt=0)
      {
          SDL_Delay(100);
      }
      scanf("%d",&ttt);

      SDL_DestroyTexture(tex);
      SDL_DestroyRenderer(ren);
      SDL_DestroyWindow(win);
      SDL_Quit();*/
    // ******************************************************************************

    char key_=0;
    int key_i=1;

    printf("\tПредупреждение!\n\n\tНастройте размер терминала сейчас, так как вы не сможете изменить его после запуска игры.\n");
    printf("\t(От размера терминала будет зависеть - насколько большим может быть поле игры.)\n\n");
    printf("\tВажно!\n");
    printf("\tВсе управление в игре осуществляется с клавиатуры. Передвижение персонажа - wasd, выбор варианта действия - название клавиши будет написано рядом с действием.\n");
    printf("\n\tОсобые обозначения:\n");
    printf("\t'@' - ваш персонаж.\n");
    printf("\t'#' - стена.\n");
    printf("\t'x' - выход из лабиринта.\n");
    printf("\t'|' '_' - дверь.\n");
    printf("\t'\\' - открытая дверь.\n");
    printf("\t't' - ловушка.\n");
    printf("\t's' - скелет воин.\n");
    printf("\n\t(Когда будете готовы - просто нажмите Enter)\n");

    getchar();


    initscr();

    start_color();

    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    hero hero_main;
    enemy skeleton_warrior;

    skeleton_warrior.armor=3;
    skeleton_warrior.damage=8;
    skeleton_warrior.experience=25;
    skeleton_warrior.hit_points=15;
    skeleton_warrior.mana_points=0;

    int counter=10;
    while (counter>=0)
    {
        hero_main.name[counter]='\0';
        --counter;
    }
    hero_main.specialization=0;
    hero_main.armor=0;
    hero_main.damage=1;
    hero_main.hit_points=5;
    hero_main.mana_points=0;
    hero_main.athletics=0;
    hero_main.experience=0;
    hero_main.knowledge=0;
    hero_main.mechanics=0;
    hero_main.stealth=0;
    hero_main.keys=0;
    hero_main.intellect=1;
    hero_main.dexterity=1;
    hero_main.strength=1;
    hero_main.endurance=1;
    hero_main.charisma=1;
    hero_main.wisdom=1;
    hero_main.survival=0;
    hero_main.next_level=50;
    hero_main.level=1;
    hero_main.exp_bonus=0;
    hero_main.hit_points_max=5;
    hero_main.mana_points_max=0;

    int first=0,second=0,swi=1,open_close=0,battle=3,result_trap=0;
    int y_size_of_map=0,x_size_of_map=0,y_max=0,x_max=0;
    coordinates start_end_location;

    /*
        while(counter<100)
        {
            key_=getch();
            printf ("%d\n",key_);
            ++counter;
        }
    */

    create_hero(&hero_main,&y_max,&x_max);

    Mix_Chunk *wave = NULL;
    Mix_Chunk *door_wave=NULL;

    attron(COLOR_PAIR(6));
    while(y_size_of_map<20 || y_size_of_map>y_max)
    {
        printw("\n\tВведите размеры карты \n\t(максимальная высота(Y):%d максимальная ширина(X):%d минимальный размер - 20/20)\n",y_max,x_max);
        printw("\n\tY:");
        refresh();
        scanw("%d",&y_size_of_map);
        fflush(stdin);
        clear();
    }
    while(x_size_of_map<20 || x_size_of_map>x_max)
    {
        printw("\n\tВведите размеры карты \n\t(максимальная высота(Y):%d максимальная ширина(X):%d минимальный размер - 20/20)\n",y_max,x_max);
        printw("\n\tY:%d",y_size_of_map);
        printw("\n\tX:");
        refresh();
        scanw("%d",&x_size_of_map);
        fflush(stdin);
        clear();
    }

    noecho();

    wave = Mix_LoadWAV("sound/mus_dungeon_temple_of_skean.wav");
    if (wave == NULL)
    {
        printf("wave error");
        exit(-1);
    }





    int events[y_size_of_map][x_size_of_map];
    maze dungeon[y_size_of_map][x_size_of_map];

    while (first<y_size_of_map)
    {
        while (second<x_size_of_map)
        {
            dungeon[first][second].visibility=0;
            dungeon[first][second].door=0;
            dungeon[first][second].event_enter=0;
            ++second;
        }
        printw("\n");
        second=0;
        ++first;
    }
    refresh();

    start_end_location=maze_generator(&dungeon[0][0],y_size_of_map,x_size_of_map,start_end_location);

    while (1)
    {
        if (hero_main.experience>=hero_main.next_level)
        level_up(&hero_main);

        if(Mix_Playing(1)==0)
        {
            if ( Mix_PlayChannel(1, wave, 0) == -1 )
            {
                printf("Mix_PlayChannel Error\n");
                exit(-1);
            }
        }

        dungeon[start_end_location.y_begin][start_end_location.x_begin].visibility=2;
        dungeon[start_end_location.y_begin-1][start_end_location.x_begin-1].visibility=1;
        dungeon[start_end_location.y_begin-1][start_end_location.x_begin].visibility=1;
        dungeon[start_end_location.y_begin-1][start_end_location.x_begin+1].visibility=1;
        dungeon[start_end_location.y_begin][start_end_location.x_begin+1].visibility=1;
        dungeon[start_end_location.y_begin+1][start_end_location.x_begin+1].visibility=1;
        dungeon[start_end_location.y_begin+1][start_end_location.x_begin].visibility=1;
        dungeon[start_end_location.y_begin+1][start_end_location.x_begin-1].visibility=1;
        dungeon[start_end_location.y_begin][start_end_location.x_begin-1].visibility=1;

        skeleton_warrior.armor=3;
        skeleton_warrior.damage=8;
        skeleton_warrior.experience=25;
        skeleton_warrior.hit_points=15;
        skeleton_warrior.mana_points=0;

        clear();

        second=0;
        first=0;
        while (first<y_size_of_map)
        {
            while (second<x_size_of_map)
            {
                if (first==start_end_location.y_begin && second==start_end_location.x_begin)
                {
                    attron(COLOR_PAIR(2));
                    printw("@");
                }
                else
                {
                    if (dungeon[first][second].visibility==1)
                    {
                        if (dungeon[first][second].square=='x')
                        {
                            attron(COLOR_PAIR(7));
                            printw("%c",dungeon[first][second].square);
                        }
                        else
                        {
                            if (dungeon[first][second].square=='_' || dungeon[first][second].square=='|' || dungeon[first][second].square=='\\')
                            {
                                attron(COLOR_PAIR(3));
                                printw("%c",dungeon[first][second].square);
                            }
                            else
                            {
                                if (dungeon[first][second].square=='s')
                                {
                                    attron(COLOR_PAIR(6));
                                    printw("%c",dungeon[first][second].square);
                                }
                                else
                                {
                                    if (dungeon[first][second].square=='t')
                                    {
                                        if (hero_main.mechanics>10)
                                        {
                                            attron(COLOR_PAIR(7));
                                            printw("%c",dungeon[first][second].square);
                                        }
                                        else
                                            printw(" ");
                                    }
                                    else
                                    {
                                        attron(COLOR_PAIR(4));
                                        printw("%c",dungeon[first][second].square);
                                    }
                                }
                            }
                        }
                    }
                    else
                        printw(" ");
                }
                ++second;
            }
            second=0;
            printw("\n");
            ++first;
        }

        attron(COLOR_PAIR(6));
        printw("\t%s\n",hero_main.name);
        printw("Жизнь   %3d/%3d    Сила         %3d Атлетика   %3d Уровень %3d Опыт %d/%d\n",hero_main.hit_points,hero_main.hit_points_max,hero_main.strength,hero_main.athletics,hero_main.level,hero_main.experience,hero_main.next_level);
        printw("Мана    %3d/%3d    Ловкость     %3d Механика   %3d\n",hero_main.mana_points,hero_main.mana_points_max,hero_main.dexterity,hero_main.mechanics);
        printw("Урон    %3d        Интеллект    %3d Знание     %3d\n",hero_main.damage,hero_main.intellect,hero_main.knowledge);
        printw("Защита  %3d        Харизма      %3d Выживание  %3d\n",hero_main.armor,hero_main.charisma,hero_main.survival);
        printw("                   Мудрость     %3d Скрытность %3d\n",hero_main.wisdom,hero_main.stealth);
        printw("                   Выносливость %3d\n",hero_main.endurance);
        refresh();
        if (start_end_location.y_begin==start_end_location.y_end && start_end_location.x_begin==start_end_location.x_end)
        {
            attron(COLOR_PAIR(5));
            printw("\nПоздравляем! Вам удалось выбраться из подземелья!\n");
            refresh();
            getch();
            endwin();
            Mix_FreeChunk(wave);
            Mix_FreeChunk(door_wave);
            Mix_CloseAudio();
            return 1;
        }

        while(swi==1)
        {
            key_=getch();
            switch (key_)
            {
            case 'w':
                if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square=='|' || dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square=='_' )
                {
                    open_close=doors(dungeon[start_end_location.y_begin-1][start_end_location.x_begin].door,&hero_main,door_wave);
                    if (open_close>0)
                    {
                        dungeon[start_end_location.y_begin-1][start_end_location.x_begin].door=0;
                        dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square='\\';
                        start_end_location.y_begin-=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square=='s')
                {
                    battle=battle_processing(&hero_main,&skeleton_warrior,door_wave,wave);
                    if (battle==0)
                        return 1;
                    else if(battle==2)
                    {
                        if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square==' ')
                            start_end_location.y_begin+=1;
                        else if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square==' ')
                            start_end_location.x_begin-=1;
                        else if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square==' ')
                            start_end_location.x_begin+=1;
                    }
                    else
                    {
                        dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square=' ';
                        start_end_location.y_begin-=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square=='t')
                {
                    result_trap=trap_processing(&hero_main);
                    if (result_trap==1)
                    {
                        dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square=' ';
                        start_end_location.y_begin-=1;
                    }
                    else if (result_trap==2)
                        return 1;
                }
                else
                {
                    if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square!='#' && dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square!='_' && dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square!='|')
                        start_end_location.y_begin-=1;
                }
                swi=0;
                break;
            case 'a':
                if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square=='|' || dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square=='_' )
                {
                    open_close=doors(dungeon[start_end_location.y_begin][start_end_location.x_begin-1].door,&hero_main,door_wave);
                    if (open_close>0)
                    {
                        dungeon[start_end_location.y_begin][start_end_location.x_begin-1].door=0;
                        dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square='\\';
                        start_end_location.x_begin-=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square=='s')
                {
                    battle=battle_processing(&hero_main,&skeleton_warrior,door_wave,wave);
                    if (battle==0)
                        return 1;
                    else if(battle==2)
                    {
                        if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square==' ')
                            start_end_location.y_begin+=1;
                        else if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square==' ')
                            start_end_location.y_begin-=1;
                        else if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square==' ')
                            start_end_location.x_begin+=1;
                    }
                    else
                    {
                        dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square=' ';
                        start_end_location.x_begin-=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square=='t')
                {
                    result_trap=trap_processing(&hero_main);
                    if (result_trap==1)
                    {
                        dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square=' ';
                        start_end_location.x_begin-=1;
                    }
                    else if (result_trap==2)
                        return 1;
                }
                else
                {
                    if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square!='#' && dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square!='_' && dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square!='|')
                        start_end_location.x_begin-=1;
                }
                swi=0;
                break;
            case 's':
                if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square=='|' || dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square=='_' )
                {
                    open_close=doors(dungeon[start_end_location.y_begin+1][start_end_location.x_begin].door,&hero_main,door_wave);
                    if (open_close>0)
                    {
                        dungeon[start_end_location.y_begin+1][start_end_location.x_begin].door=0;
                        dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square='\\';
                        start_end_location.y_begin+=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square=='s')
                {
                    battle=battle_processing(&hero_main,&skeleton_warrior,door_wave,wave);
                    if (battle==0)
                        return 1;
                    else if(battle==2)
                    {
                        if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square==' ')
                            start_end_location.x_begin-=1;
                        else if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square==' ')
                            start_end_location.y_begin-=1;
                        else if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square==' ')
                            start_end_location.x_begin+=1;
                    }
                    else
                    {
                        dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square=' ';
                        start_end_location.y_begin+=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square=='t')
                {
                    result_trap=trap_processing(&hero_main);
                    if (result_trap==1)
                    {
                        dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square=' ';
                        start_end_location.y_begin+=1;
                    }
                    else if (result_trap==2)
                        return 1;
                }
                else
                {
                    if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square!='#' && dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square!='_' && dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square!='|')
                        start_end_location.y_begin+=1;
                }
                swi=0;
                break;
            case 'd':
                if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square=='|' || dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square=='_' )
                {
                    open_close=doors(dungeon[start_end_location.y_begin][start_end_location.x_begin+1].door,&hero_main,door_wave);
                    if (open_close>0)
                    {
                        dungeon[start_end_location.y_begin][start_end_location.x_begin+1].door=0;
                        dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square='\\';
                        start_end_location.x_begin+=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square=='s')
                {
                    battle=battle_processing(&hero_main,&skeleton_warrior,door_wave,wave);
                    if (battle==0)
                        return 1;
                    else if(battle==2)
                    {
                        if (dungeon[start_end_location.y_begin][start_end_location.x_begin-1].square==' ')
                            start_end_location.x_begin-=1;
                        else if (dungeon[start_end_location.y_begin-1][start_end_location.x_begin].square==' ')
                            start_end_location.y_begin-=1;
                        else if (dungeon[start_end_location.y_begin+1][start_end_location.x_begin].square==' ')
                            start_end_location.y_begin+=1;
                    }
                    else
                    {
                        dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square=' ';
                        start_end_location.x_begin+=1;
                    }
                }
                else if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square=='t')
                {
                    result_trap=trap_processing(&hero_main);
                    if (result_trap==1)
                    {
                        dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square=' ';
                        start_end_location.x_begin+=1;
                    }
                    else if (result_trap==2)
                        return 1;
                }
                else
                {
                    if (dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square!='#' && dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square!='_' && dungeon[start_end_location.y_begin][start_end_location.x_begin+1].square!='|')
                        start_end_location.x_begin+=1;
                }
                swi=0;
            }
        }
        open_close=0;
        swi=1;
    }
    endwin();
    Mix_FreeChunk(wave);
    Mix_FreeChunk(door_wave);
    Mix_CloseAudio();
    return 0;
}
