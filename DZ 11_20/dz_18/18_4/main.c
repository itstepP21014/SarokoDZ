#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"
#include "../../../modules/compatibility.h"
#include "../../../modules/string_func.h"

#define size_max 1000
int main()
{
    char great[size_max]="кулак кулак зерно пуп пуп топор рор рор лол лол";
    string_print_words(great," ");
    system("pause");
    return 0;
}
