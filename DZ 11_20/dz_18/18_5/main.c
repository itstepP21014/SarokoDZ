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
    char great[size_max]="Wondering how to get started with Grasshopper? Look no further. Spend an some time with the creator of Grasshopper, David Rutten, to learn the fundamental of Grasshopper. No experience necessary.";
    string_vowels_consonants(great);
    system("pause");
    return 0;
}
