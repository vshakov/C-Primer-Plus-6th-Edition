/* 11_7.c */

// C Primer Plus
// Chapter 11 Exercise 7:

// The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1,
// truncating s2 or padding it with extra null characters as necessary. The
// target string may not be null-terminated if the length of s2 is n or more.
// The function returns s1. Write your own version of this function; call it
// mystrncpy(). Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.

#include <stdio.h>

#define SIZE 50

char * mystrncpy(char * restrict s1, const char * restrict s2, int n);
char * s_gets(char * st, int n);

int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    int n;

    printf("Enter a string to copy: ");
    s_gets(s2, SIZE);
    while (s2[0] != '\0')
    {
        printf("How many characters do you want to copy? (maximum %d) ", SIZE);
		scanf("%d", &n);
        while (getchar() != '\n')
                continue;
        while (n > SIZE)
        {
            printf("Too many characters. Max is %d.\n", SIZE);
            scanf("%d", &n);
            while (getchar() != '\n')
                continue;
        }
        printf("Original string: %s\n", s2);
        mystrncpy(s1, s2, n);
        printf("Copy: %s\n", s1);
        for (int i = 0; i < n; i++)
            s1[i] = '\0';
        printf("Enter a string to copy (empty line to quit): ");
		s_gets(s2, SIZE);
    }
    puts("Bye!");

    return 0;
}

char * mystrncpy(char * restrict s1, const char * restrict s2, int n)
{
    int i = 0;
    while (s2[i] != '\0' && i < n)
    {
        s1[i] = s2[i];
        i++;
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