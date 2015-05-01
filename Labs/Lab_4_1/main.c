#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Реализовано через общую память.

typedef struct request
{
    int check;
    int number;
    int result;
}request;
void server(request*);
void controller(request*);

int main()
{
    srand(time(NULL));
    int counter=100;
    request Request;
    Request.check=0;
    //Клиент
    while (counter>0)
    {
        Request.number=rand()%10;
        controller(&Request);
        --counter;
    }
    return 0;
}
    //Контроллер
void controller(request*main_frame)
{
    if (main_frame->check==0)
    {
        main_frame->check=1;
        server(main_frame);
        main_frame->check=0;
    }
    else
    printf("\nPlease wait...\n");
}

    //Сервер
void server(request*main_frame)
{
    int array[10];
    main_frame->result=array[main_frame->number];
}
