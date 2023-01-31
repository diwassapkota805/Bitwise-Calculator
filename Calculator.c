// Name: DIWAS SAPKOTA 
void ConvertDecimalToBinary(int DecVal, char array[]);
#include <stdio.h>
#define BITS 8
int main(void)
{
    //print instruction
    printf("Bitwise Calculator\n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal\n result and the bnary result. The format is\n\n");
    printf("First Number Bitwise Operator SecondNumber\n\n");
    printf("For example, enter the expression\n\n");
    printf("2 & 3\n\n");
    printf("The calculator can be used with &, |, ^, <<and>>\n\n");
    printf("Please note that the space between numbers and operator is essential\n and the two entered values must be between 0 and 255\n\n");
    int first_num, second_num, cal_val;
    char operator[3];

    //prompt the user
    scanf("%d %s%d", &first_num, operator, &second_num);
    while ((first_num < 0) || (first_num > 225) || (second_num < 0) ||
        (second_num > 255))
        scanf("%d %s%d", &first_num, operator, &second_num);

    //check the condition for operators and perform calculation
    if ((operator[0] == '&') || (operator[0] == '|') || (operator[0] == '^') ||
        (operator[0] == '<') || (operator[0] == '>'))
    {
        printf("In base 10...\n\n");
        if (operator[0] == '&')
        {
            cal_val = first_num &second_num;
            printf("%d %c %d = %d\n\n", first_num, operator[0], second_num,
                cal_val);
        }
        else if (operator[0] == '|')
        {
            cal_val = first_num | second_num;
            printf("%d %c %d = %d\n\n", first_num, operator[0], second_num,
                cal_val);
        }
        else if (operator[0] == '^')
        {
            cal_val = first_num ^ second_num;
            printf("%d %c %d = %d\n\n", first_num, operator[0], second_num,
                cal_val);
        }
        else if (operator[0] == '<')
        {
            cal_val = first_num << second_num;
            printf("%d %c%c %d = %d\n\n", first_num, operator[0], operator[1],
                second_num, cal_val);
        }
        else if (operator[0] == '>')
        {
            cal_val = first_num >> second_num;
            printf("%d %c%c %d = %d\n\n", first_num, operator[0], operator[1],
                second_num, cal_val);
        }

        //call the function to convert decimal numbers to binary
        printf("In 8-bit base 2...\n\n");
        char BinArray[100];
        ConvertDecimalToBinary(first_num, BinArray);
        for (int a = 0; a < BITS; a++)
        {
            printf("%c", BinArray[a]);
        }
        printf("\n%c\n", operator[0]);
        ConvertDecimalToBinary(second_num, BinArray);
        for (int b = 0; b < BITS; b++)
        {
            printf("%c", BinArray[b]);
        }
        printf("\n========\n");
        ConvertDecimalToBinary(cal_val, BinArray);
        for (int c = 0; c < BITS; c++)
        {
            printf("%c", BinArray[c]);
        }
    }

    //do this if "invalid operator"
    else
        printf("Operator x is not supported by this calculator");
    return 0;
}

void ConvertDecimalToBinary(int DecVal, char array[])
{
    int ResultOfDivide[100];
    ResultOfDivide[0] = DecVal;
    //bitshift to divide by 2
    for (int x = 1; x < BITS; x++)
    {
        ResultOfDivide[x] = ResultOfDivide[x - 1] >> 1;
    }
    int index = 0;
    //(for loop) to put '0's and '1's.
    for (int y = BITS - 1; y >= 0; y--)
    {
        if (ResultOfDivide[y] &1)
            array[index] = '1';
        else
            array[index] = '0';
        index++;
    }
}
