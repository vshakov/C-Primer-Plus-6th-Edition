/* 11_10.c */

// C Primer Plus
// Chapter 11 Exercise 10:

// Write a function that takes a string as an argument and removes the spaces
// from the string. Test it in a program that uses a loop to read lines until
// you enter an empty line. The program should apply the function to each input
// string and display the result.

#include <stdio.h>

#define SIZE 50

void remove_spaces(char * string);
char * s_gets(char * st, int n);

int main(void)
{
    char string[SIZE];
    printf("Enter a string to remove spaces: ");
    s_gets(string, SIZE);
    while (string[0] != '\0')
    {
        remove_spaces(string);
        printf("Your string without spaces: %s\n", string);
        printf("Enter a string (or empty line to quit): ");
        s_gets(string, SIZE);
    }
    puts("Bye!");

    return 0;
}

void remove_spaces(char * string)
{
    unsigned long count_spaces = 0;

    while (1)
    {
        if (*string == ' ')
            count_spaces++;
        else
            *(string - count_spaces) = *string;
        if (*string == '\0')
            break;
        string++;
    }
    
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else    
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
