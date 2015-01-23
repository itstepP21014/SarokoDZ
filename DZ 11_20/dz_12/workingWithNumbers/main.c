#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../../modules/numbers.h"

int main()
{
    int number,digit,cycles;
    printf("Please enter an integer:\n");
    scanf("%d",&number);
    printf("Please enter digit:\n");
    scanf("%d",&digit);
    printf("\nNumber of digits: %d\n\n",numberOfDigits(number));
    printf("new number (-first digit): %d\n\n",firstNumber(number));
    printf("new number (-all digits, except first ): %d\n\n",exceptFirst(number));
    printf("new number (number+digit): %d\n\n",plusDigit(number,digit));
    printf("please enter number of cycles for shift:\n");
    scanf("%d",&cycles);
    printf("new number (shift): %d\n\n",cycle(number,cycles));

    return 0;
}
