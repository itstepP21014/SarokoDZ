#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000
int main()
{
    int memory[size_max];
    int memory_size=100,accumulator=0,instruction_counter=0,operatingCode=0,operand=0,instruction_register=0;
    int swi=1;
    printf("***Симплетрон приветствует вас!***\nПожалуйста введите вашу программу по одной команде (или слову данных) за раз.\n");
    printf("Я буду выводить в качестве подсказки текущий адрес и знак вопроса (?).\n");
    printf("Введенное вами слово буде размещено по указанному адресу.\n");
    printf("Для прекращения ввода программы  введите число -99999.\n");
    array_input_reg(memory,memory_size);
    printf("Выполнение:\n");
    while (swi)
    {
       instruction_register=memory[instruction_counter];
       operatingCode=instruction_register/100;
       operand=instruction_register%100;
       switch (operatingCode)
       {
        case 10:
        printf("(?)");
        scanf("%d",&memory[operand]);
        break;
        case 11:
        printf("%d",memory[operand]);
        break;
        case 20:
        accumulator=memory[operand];
        break;
        case 21:
        memory[operand]=accumulator;
        break;
        case 30:
        accumulator+=memory[operand];
        break;
        case 31:
        accumulator-=memory[operand];
        break;
        case 32:
        accumulator/=memory[operand];
        break;
        case 33:
        accumulator*=memory[operand];
        break;
        case 40:
        instruction_counter=operand-1;
        break;
        case 41:
        if (accumulator<0)
        {
        instruction_counter=operand-1;
        }
        break;
        case 42:
        if (accumulator==0)
        {
        instruction_counter=operand-1;
        }
        break;
        case 43:
        printf("\nПрограмма завершена!\nРегистры:\n");
        printf("accumulator\t\t+%04d\ninstruction_counter\t%02d\ninstruction_register\t+%04d\noperatingCode\t\t%02d\noperand\t\t\t%02d\n",accumulator,instruction_counter,instruction_register,operatingCode,operand);
        array_output_reg (memory,memory_size);
        system ("pause");
        return 1;
        break;
        default:
        printf("\nОбнаружена ошибка в программе!\n");
        system ("pause");
        exit (2);
       }
       ++instruction_counter;
    }
    return 0;
}
