#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
int dice100();
int dice30();
int dice20();
int dice12();
int dice10();
int dice8();
int dice6();
int dice4();
int temperateClimate();
int jungleClimate();
int desertClimate();





int main()
{
    //character........................
    //gender...........................
    int gender;
    //races............................
    int human=0,  dwarf=0, gnome=0, elf=0, halfElf=0, halfling=0, halfOrc=0, lizardman=0, tiefling=0, aasimar=0, purebludedYuanti=0;
    //classes..........................
    int barbarian=0, bard=0, priest=0, druid=0, warrior=0, monk=0, paladin=0, pathfinder=0, thief=0, wizard=0, sorcerer=0;
    //alignment........................
    int lawfulGood=0, neutralGood=0, chaoticGood=0, lawfulNeutral=0, trueNeutral=0, chaoticNeutral=0, lawfulEvil=0, neutralEvil=0, chaoticEvil=0;
    //main.............................
    int healthMax, skillPoints, numberOfSpells;
    //saves............................
    int fortitude=0, reflex=0, will=0;
    //Stats............................
    int strength, dexterity, constitution, wisdom, intelligence, charisma;
    int armorClass=0, attack=0;
    //skills...........................
    int diplomacy=0, bluff=0, appraise=0, balance=0, climb=0, concentration=0, craft=0, decipherScript=0, disableDevice=0, disguise=0, escapeArtist=0, forgery=0;
    int gatherInformation=0, handleAnimal=0, heal=0, hide=0, intimidate=0, jump=0, knowledge=0, listen=0, moveSilently=0, openLock=0, perform=0, profession=0;
    int ride=0, search=0, senseMotive=0, sleightOfHand=0, speakLanguage=0, spellcraft=0, spot=0, survival=0, swim=0, tumble=0, useMagicDevice=0, useRope=0;
    //the number of valid spells of different levels
    int level_0=0,level_1=0,level_2=0,level_3=0,level_4=0,level_5=0,level_6=0,level_7=0,level_8=0,level_9=0;
    //control components...............
    //switches.........................
    int swi1=1,swi2=1,swi3=1,swi4=1,swi5=1;
    int inpoutReflection, input, counter;
    //times of day.....................
    int day,night,timeHours;
    //lighting.........................
    int dark,light;
    //the weather......................
    int rain=0, hurricane=0, snow=0, blizzard=0, tC, jC, dC;
    int underground;
    //imitation die rolls..............
    int dice_4, dice_6, dice_8, dice_10, dice_12, dice_20, dice_30, dice_100;
    //check (skills)............................
    int check, checkDouble1, checkDouble2, enemyCheck, checkLanguage=0;
    //the results of the main action............
    int damage=0,chanceToHit=0,movingSpeed=1,rangeSight=10, kindleFire=10,fatigue=0,enemyDamage=0,enemyChanceToHit=0,enemyMovingSpeed=0,enemyHealth=0,damageMax=0,enemyDamageMax=0;
    int disease=0, poisoning=0, restInTavern=0, health, enemyHealthMax;
    //dependent parameters......................
    int carriedWeight=0, sizeCharacter=0, modifierStrength=0,modifierDexterity=0,modifierConstitution=0,modifierWisdom=0,modifierIntelligence=0,modifierCharisma=0;
    //resistance................................
    int elementalResist=0, physicalResist=0, fireResist=0, lightningResist=0, acidResist=0, poisonResist=0,coldResist=0;
    //damage absorption.........................
    int damageAbsorption=0, daAdamantine=0,daSilver=0,daColdIron=0,daSlash=0,daPiercing=0,daMaces=0;
    //Основные обозначения
    char genderM[15]="Мужчина", genderW[15]="Женщина",yourGender[15];

    //utf-8
     system("chcp 1251");
     system("cls");


    //gender choice

    printf ("Выберите пол своего персонажа:\n Пол персонажа это скорее эстетический выбор, который никак не влияет на ваши параметры. Однако он определяет какие именно персонажи (не принадлежащие игроку) будут заинтересованы в романтических отношениях с вашим героем.\n");
    printf ("--Мужчина-- (0)\n Мужчины Королевств могут преуспеть в любой выбранной ими специальности, будь-то волшебство, воровство или боевые искусства.\n --Женщина-- (1)\n Женщины Королевств могут преуспеть в любой сфере деятельности по желанию и не уступают мужчинам по способностям и другим характеристикам.\n");
    while (swi1)
    {
     scanf("%d",&gender);
     fflush(stdin);
     switch (gender)
     {
     case 0:
     printf("Вы выбрали мужской пол.\n");
     swi1=0;
     break;
     case 1:
     printf("Вы выбрали женский пол.\n");
     swi1=0;
     swi2=0;
     break;
     default:
     printf("Выберите пол персонажа (введите 0 или 1)\n");
     break;
    }
    }
    swi1=1;

    if (swi2==1)
    {
      strcpy(yourGender, genderM);
      printf ("Пол: %s\n",yourGender);
    }
    else
    {
      strcpy(yourGender, genderW);
      printf ("Пол: %s\n",yourGender);  //swi2=0
    }






    //battle test
    srand(time(NULL));
    printf ("\n");
    printf ("Fight test Проверка:\n");
    healthMax=100;
    health=100;
    enemyHealthMax=50;
    enemyHealth=50;
    chanceToHit=95;
    enemyChanceToHit=80;
    printf("fight (you-100 hit points,1-8 damage; enemy-50 hit points,1-10 damage\n");
    damageMax=8;
    enemyDamageMax=10;
    while (swi1)
    {
       printf ("you:\t\t\tenemy:\nhealth %d\\%d\t\thealth %d\\%d\ndamage 1-%d\t\tdamage 1-%d\nchanceToHit %d\t\tchanceToHit %d\n",health ,healthMax, enemyHealth, enemyHealthMax, damageMax, enemyDamageMax,chanceToHit,enemyChanceToHit);
       printf("Press (1) to next round\n");
       scanf("%d",&input);
       switch (input)
       {
       case 1:
       damage=dice8();
       enemyDamage=dice10();
       check=dice100();
       enemyCheck=dice100();
       if (enemyChanceToHit>=enemyCheck)
       {
         checkDouble1=1+rand()%20;
         if (checkDouble1>18)
         {
          enemyDamage*=2;
          health-=enemyDamage;
          printf ("The enemy causes you critical hit: %d points of damage\n",enemyDamage);
          if (health<=0)
          {
             printf ("you died\n");
             swi1=0;
          }
         }
         else
         {
          health-=enemyDamage;
          printf ("The enemy causes you %d points of damage\n",enemyDamage);
          if (health<=0)
          {
             printf ("you died\n");
             swi1=0;
          }
         }
       }
       else
       {
           printf ("enemy misses\n");
       }
       if (chanceToHit>=check)
       {
         checkDouble2=1+rand()%20;
         if (checkDouble2>18)
         {
         damage*=2;
         enemyHealth-=damage;
         printf ("You cause critical hit: %d points of damage to the enemy\n",damage);
         if (enemyHealth<=0)
         {
             printf ("you won\n");
             printf ("you:\t\t\tenemy:\nhealth %d\\%d\t\thealth %d\\%d\ndamage 1-%d\t\tdamage 1-%d\nchanceToHit %d\t\tchanceToHit %d\n",health ,healthMax, enemyHealth, enemyHealthMax, damageMax, enemyDamageMax,chanceToHit,enemyChanceToHit);
             swi1=0;
         }
         }
         else
         {
         enemyHealth-=damage;
         printf ("You cause %d points of damage to the enemy\n",damage);
         if (enemyHealth<=0)
         {
             printf ("you won\n");
             printf ("you:\t\t\tenemy:\nhealth %d\\%d\t\thealth %d\\%d\ndamage 1-%d\t\tdamage 1-%d\nchanceToHit %d\t\tchanceToHit %d\n",health ,healthMax, enemyHealth, enemyHealthMax, damageMax, enemyDamageMax,chanceToHit,enemyChanceToHit);
             swi1=0;
         }
         }
       }
       else
       {
           printf ("you missed\n");
       }
       break;
       default:
       printf ("incorrect input\n");
       break;
       }
    }
    swi1=1;

    //fatigue test
    printf ("You want to relax 8 hours?\n(1)-yes,(2)-no\n");
    scanf("%d",&input);
    if (input==1)
    {
      printf ("You want to relax in a tavern or in the field?\n(1)-tavern,(2)-field\n");
      scanf ("%d",&restInTavern);
      check=dice100();
      if (check<=10)
      {
       if (restInTavern==1)
         {
           counter=10;
           while (counter)
           {
               if (health==healthMax)
               {
                   counter=0;
               }
               else
               {
                   ++health;
                   --counter;
               }
           }
           printf("You rested 8 hours.\n You have restored 10 health points.\n You remember the spells.\n Your saves restored.\n");
         }
       else
         {
           printf("Monsters attacked you while you sleep.\n");
         }
      }
      else
         if (restInTavern==1)
         {
            counter=10;
            while (counter)
            {
             if (health==healthMax)
             {
             counter=0;
             }
             else
             {
              ++health;
              --counter;
             }
            }
           printf("You rested 8 hours.\n You have restored 10 health points.\n You remember the spells.\n Your saves restored.\n");
         }
         else
         {
            if (health==healthMax)
            {
             printf("You rested 8 hours.\n You remember the spells.\n Your saves restored.\n");
            }
            else
            {
             ++health;
             printf("You rested 8 hours.\n You have restored 1 health point.\n You remember the spells.\n Your saves restored.\n");
            }
         }
    }
    else
    {
      printf ("You have decided not to rest.\n");
    }
    printf ("Your heath: %d\\%d\n",health,healthMax);



    //weather test
    int temperateClimate()
    {
        int numberCheck, weather;
        numberCheck=dice100();
        if (numberCheck<=10)
        {
           weather=1; //rain
        }
        else
        {
            if (numberCheck<=95)
            {
               weather=0; //good weather
            }
            else
            {
               weather=2; //fog
            }
        }
      return (weather);
    }
    //..............................
    int jungleClimate()
    {
      int numberCheck, weather;
        numberCheck=dice100();
        if (numberCheck<=40)
        {
           weather=1; //rain
        }
        else
        {
            if (numberCheck<=95)
            {
               weather=0; //good weather
            }
            else
            {
               weather=2; //tornado
            }
        }
      return (weather);
    }
    //...............................
    int desertClimate()
    {
      int numberCheck, weather;
        numberCheck=dice100();
        if (numberCheck<=90)
        {
           weather=1; //sun
        }
        else
        {
           weather=0; //sandstorm
        }
      return (weather);
    }





    //function test
    printf ("\n\nTest of dices:\n");
    dice_4=dice4();
    dice_6=dice6();
    dice_8=dice8();
    dice_10=dice10();
    dice_12=dice12();
    dice_20=dice20();
    dice_30=dice30();
    dice_100=dice100();
    printf ("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",dice_4,dice_6,dice_8,dice_10,dice_12,dice_20,dice_30,dice_100);
    system ("pause");
    return 0;
}

int dice4()
{int d_4;
srand(time(NULL));
d_4=1+rand()%4;
return (d_4);
}

int dice6()
{int d_6;
srand(time(NULL));
d_6=1+rand()%6;
return (d_6);
}

int dice8()
{int d_8;
srand(time(NULL));
d_8=1+rand()%8;
return (d_8);
}

int dice10()
{int d_10;
srand(time(NULL));
d_10=1+rand()%10;
return (d_10);
}

int dice12()
{int d_12;
srand(time(NULL));
d_12=1+rand()%12;
return (d_12);
}

int dice20()
{int d_20;
srand(time(NULL));
d_20=1+rand()%20;
return (d_20);
}

int dice30()
{int d_30;
srand(time(NULL));
d_30=1+rand()%30;
return (d_30);
}

int dice100()
{int d_100;
srand(time(NULL));
d_100=1+rand()%100;
return (d_100);
}


