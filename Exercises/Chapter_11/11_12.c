/* 11_12.c */

// C Primer Plus
// Chapter 11 Exercise 12:

// Write a program that reads input up to EOF and reports the number of words,
// the number of uppercase letters, the number of lowercase letters, the number
// of punctuation characters, and the number of digits. Use the ctype.h family
// of functions.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    int words, upcase_letters, lowcase_letters, puncts, digits;
    words = upcase_letters = lowcase_letters = puncts = digits = 0;
    bool inword = false;
    
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch) && !inword)
        {
            inword = true;
            words++;
        }
        if (isupper(ch))
            upcase_letters++;
        if (islower(ch))
            lowcase_letters++;
        if (isspace(ch) && inword)
            inword = false;
        if (isdigit(ch))
        {
            inword = false;
            digits++;
        }
        if (ispunct(ch) && ch != '-' && ch != '"')
        {
            puncts++;
			if (ch != '-' && ch != '\'')
				inword = false;
        }
        
    }
    printf("Number of %s: %d\n", "words", words);
    printf("Number of %s: %d\n", "uppercase letters", upcase_letters);
    printf("Number of %s: %d\n", "lowercase letters", lowcase_letters);
    printf("Number of %s: %d\n", "punctuation characters", puncts);
    printf("Number of %s: %d\n", "digits", digits);

    return 0;
}

