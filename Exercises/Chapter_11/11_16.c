/* 11_16.c */

// C Primer Plus
// Chapter 11 Exercise 16:

// Write a program that reads input until end-of-file and echoes it to the
// display. Have the program recognize and implement the following command-line
// arguments:
// 	- p Print input as is
// 	- u Map input to all uppercase
// 	- l Map input to all lowercase
// Also, if there are no command-line arguments, let the program behave as if
// the –p argument had been used.

#include <stdio.h>
#include <ctype.h>

void print_origin(void);
void print_uppercase(void);
void print_lowercase(void);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        print_origin();
        return 0;
    }
    if (argc > 2 || (argc == 2 && argv[1][0] != '-'))
    {
        printf("Usage: <program_name> [-p | -l | -u]\n");
        return 1;
    }
    else
        switch (argv[1][1])
        {
        case ('p'):
            print_origin();
            break;
        case ('l'):
            print_lowercase();
            break;
        case ('u'):
            print_uppercase();
            break;
        default:
            printf("Usage: <program_name> [-p | -l | -u]\n");
            return 1;
        }

    return 0;
}

void print_origin(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
        putchar(ch);
}

void print_uppercase(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            ch = toupper(ch);
        putchar(ch);
    }
}
void print_lowercase(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            ch = tolower(ch);
        putchar(ch);
    }
}