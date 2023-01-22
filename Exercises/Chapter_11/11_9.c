/* 11_9.c */

// C Primer Plus
// Chapter 11 Exercise 9

// Write a function that replaces the contents of a string with the string
// reversed. Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.

#include <stdio.h>
#include <string.h>

#define SIZE 50

void reverse_string(char * string);
char * s_gets(char * st, int n);

int main(void)
{
    char string[SIZE];

    printf("Enter  string to reverse: ");
    s_gets(string, SIZE);
    while (string[0] != '\0')
    {
        reverse_string(string);
        printf("Reversed string: %s\n", string);

        printf("Enter a string to reverse (empty line to quit): ");
        s_gets(string, SIZE);
    }
    puts("Bye");

    return 0;
}

void reverse_string(char * string)
{
	// replace contents of a string with the string reversed

	char *end = string;
	char tmp;

	// find location of the end of the string
	while (*(end + 1) != '\0')
		end++;

	// switch characters
	while (string < end)
	{
		tmp = *string;
		*string = *end;
		*end = tmp;

		string++;
		end--;
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