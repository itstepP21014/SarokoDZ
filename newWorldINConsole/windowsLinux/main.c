#include <stdio.h>
#include <stdlib.h>
#include "../../modules/compatibility.h"


int main()
{
    printf("Great World!");
    char enter;
    scanf("%c", &enter);
    universalClear();
    printf("Good bye.");
    universalSleep(1.5);
    universalClear();
    return 0;
}
