/* 11_6.c */

// C Primer Plus
// Chapter 11 Exercise 6:

// Write a function called is_within() that takes a character and a string
// pointer as its two function parameters. Have the function return a
// nonzero value (true) if the character is in the string and zero (false)
// otherwise. Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.

#include <stdio.h>

#define SIZE 50

int is_within(char ch, const char * string);
char * s_gets(char * st, int n);

int main(void)
{
    char string[SIZE];
    char ch;

    printf("Enter a string to search: ");
    s_gets(string, SIZE);
    printf("Enter a charachter to search in string: ");
    ch = getchar();
    if (ch != '\n')
		while (getchar() != '\n')
			continue;
    while (is_within(ch, string) != 1)
    {
    printf("The string \"%s\" doesn't contain %c\n", string, ch);
    printf("Enter a charachter to search in string: ");
    ch = getchar();
    if (ch != '\n')
			while (getchar() != '\n')
				continue;
    }
    printf("The string \"%s\" contains \"%c\"\n", string, ch);
    puts("Bye!");

    return 0;
}

int is_within(char ch, const char * string)
{
    while (*string != '\0')
    {
        if (*string == ch)
            return 1;
        string++;
    }

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n , stdin);
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