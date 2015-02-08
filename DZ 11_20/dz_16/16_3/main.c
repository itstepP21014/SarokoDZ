#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/Arrayss.h"
#include "../../../modules/funcRand.h"

#define size_max 1000

int main()
{
    int memory[size_max];
    int memory_size=100,operatingCode=0,operand=0,instruction_register=0;
    int swi=1,bias=0,top=100,accumulator=0,instruction_counter=0,top_2=0;
    printf("***Стекплетрон приветствует вас!***\nПожалуйста введите вашу программу по одной команде (или слову данных) за раз.\n");
    printf("Я буду выводить в качестве подсказки текущий адрес и знак вопроса (?).\n");
    printf("Введенное вами слово буде размещено по указанному адресу.\n");
    printf("Для прекращения ввода программы  введите число -99999.\n");
    array_elements_mustBe_0(memory, memory_size);
    array_input_reg(memory,memory_size);
    printf("Выполнение:\n");
    while (swi)
    {
       instruction_register=memory[instruction_counter];
       operatingCode=instruction_register/100;
       operand=instruction_register%100;
       switch (operatingCode)
       {
        case 0:
        break;
        case 10:
        printf("(?)");
        scanf("%d",&memory[operand+bias]);
        break;
        case 11:
        printf("%d",memory[operand+bias]);
        break;
        case 20:
        accumulator=memory[operand+bias];
        break;
        case 21:
        memory[operand+bias]=accumulator;
        break;
        case 22:
        accumulator=top;
        break;
        case 23:
        top=accumulator;
        break;
        case 24:
        accumulator=bias;
        break;
        case 25:
        bias=accumulator;
        break;
        case 26:
        --top;
        memory[top]=accumulator;
        break;
        case 27:
        accumulator=memory[top];
        memory[top]=0;
        ++top;
        break;
        case 30:
        accumulator+=memory[operand+bias];
        break;
        case 31:
        accumulator-=memory[operand+bias];
        break;
        case 32:
        accumulator/=memory[operand+bias];
        break;
        case 33:
        accumulator*=memory[operand+bias];
        break;
        case 34:
        accumulator=operand;
        break;
        case 40:
        instruction_counter=(operand+bias)-1;
        break;
        case 41:
        if (accumulator<0)
        {
        instruction_counter=(operand+bias)-1;
        }
        break;
        case 42:
        if (accumulator==0)
        {
        instruction_counter=(operand+bias)-1;
        }
        break;
        case 43:
        printf("\nПрограмма завершена!\nРегистры:\n");
        printf("accumulator\t\t+%04d\ninstruction_counter\t%02d\ninstruction_register\t+%04d\noperatingCode\t\t%02d\noperand\t\t\t%02d\n",accumulator,instruction_counter,instruction_register,operatingCode,operand);
        array_output_reg (memory,memory_size);
        system ("pause");
        return 1;
        break;
        case 44:
        --top;
        memory[top]=instruction_counter;
        instruction_counter=operand-1;
        break;
        case 45:
        top_2=top-1;
        while (operand>0)
        {
            memory[top_2]=memory[top];
            memory[top]=0;
            --top_2;
            ++top;
            --operand;
        }
        instruction_counter=memory[top];
        while (memory[top_2]!=0)
        {
            memory[top]=memory[top_2];
            --top;
            ++top_2;
        }
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
