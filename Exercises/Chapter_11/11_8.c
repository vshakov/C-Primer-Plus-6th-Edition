/* 11_8.c */

// C Primer Plus
// Chapter 11 Exercise 8:

// Write a function called string_in() that takes two string pointers as
// arguments. If the second string is contained in the first string, have the
// function return the address at which the contained string begins. For
// instance, string_in("hats", "at") would return the address of the a in hats.
// Otherwise, have the function return the null pointer. Test the function in a
// complete program that uses a loop to provide input values for feeding to the
// function.

#include <stdio.h>

#define SIZE 50

char * string_in(char * string, char * substring);
char * s_gets(char * st, int n);

int main(void)
{
    char string[SIZE];
    char substring[SIZE];

    char * match;

    printf ("Enter a string: ");
    s_gets(string, SIZE);
    while (string[0] != '\0')
    {
        printf("Enter a substring to look for in string: ");
        s_gets(substring, SIZE);
        match = string_in(string, substring);
        if (match == NULL)
            printf("\"%s\" not found in \"%s\"", substring, string);
        else
            printf("\"%s\" found in \"%s\" at index %lu\n", substring, string, match - string);
        printf("Enter a string (empty line to quit): ");
        s_gets(string, SIZE);
    }
    puts("Bye!");

    return 0;
}

char * string_in(char * string, char * substring)
{
    int i = 0;

    while (* string != '\0')
    {
        while (*(string + i) == *(substring + i))
        {
            i++;
            if (* (substring + i) == '\0')
                return string;
        }
        string++;
    }
    //no match

    return NULL;
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