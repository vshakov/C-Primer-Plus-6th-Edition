/* 11_5.c */

// C Primer Plus
// Chapter 11 Exercise 5:

// Design and test a function that searches the string specified by the first
// function parameter for the first occurrence of a character specified by the
// second function parameter. Have the function return a pointer to the
// character if successful, and a null if the character is not found in the
// string. (This duplicates the way that the library strchr() function works.)
// Test the function in a complete program that uses a loop to provide input
// values for feeding to the function.

#include <stdio.h>

#define SIZE 50

char *findchar(char * str, int ch);

int main(void)
{
    char string[SIZE];
    char * srch;
    char ch;

    printf("Enter a string to search: ");
    fgets(string, SIZE, stdin);
    while (string[0] != '\n')
    {
        printf("Enter a character to search for: ");
        ch = getchar();
        if (ch != '\n')
            while (getchar() != '\n')
                continue;

        srch = findchar(string, ch);
        if (srch == NULL)
            printf("Character %c not found in %s", ch, string);
        else
            printf("Character %c found at index %lu in %s", ch, srch - string, string);

        printf("Enter a string to search (empty line to quit).");
        fgets(string, SIZE, stdin);
    }
    puts("Bye!");

    return 0;
}

char *findchar(char * str, int ch)
{
    while (* str != '\0')
    {
        if (* str == ch)
            return str;
        str++;    
    }
    
    return NULL;
}