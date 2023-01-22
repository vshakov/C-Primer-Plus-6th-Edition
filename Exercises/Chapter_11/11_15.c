/* 11_15.c */

// C Primer Plus
// Chapter 11 Exercise 15:

// Use the character classification functions to prepare an implementation of
// atoi(); have this version return the value of 0 if the input string is not a
// pure number.

#include <stdio.h>
#include <ctype.h>

int my_atoi(char *string);

int main(int argc, char *argv[])
{
    int input;

    if (argc != 2)
        puts("Usage <program_name> <argv[1]>");
    else
    {
        input = my_atoi(argv[1]);
        printf("%d + 5 = %d\n", input, input + 5);
		printf("%d / 2 = %d\n", input, input / 2);
		printf("%d %% 3 = %d\n", input, input % 3);
    }

    return 0;
}

int my_atoi(char *string)
{
    int total = 0;

    while (*string)
    {
        if (isdigit(*string))
        {
            total *= 10;
            total += *string - '0';
        }
        else
            return 0;
        
        string++;
    }
    return total;
}