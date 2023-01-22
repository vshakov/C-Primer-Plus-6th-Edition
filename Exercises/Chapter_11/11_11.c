/* 11_11.c */

// C Primer Plus
// Chapter 11 Exercise 11:

// Write a program that reads in up to 10 strings or to EOF, whichever comes
// first. Have it offer the user a menu with five choices: print the original
// list of strings, print the strings in ASCII collating sequence, print the
// strings in order of increasing length, print the strings in order of the
// length of the first word in the string, and quit. Have the menu recycle
// until the user enters the quit request. The program, of course, should
// actually perform the promised tasks.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 51
#define LIM 10

void sort_ASCII(char *strings[], int num);
void sort_length(char *strings[], int num);
int first_word_len(char *string);
void sort_first_word_length(char *strings[], int num);
char * s_gets(char * st, int n);
void print_menu(void);

int main(void)
{
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;
    char ch;

    printf("Enter up to %d strings. \n", LIM);
    printf("Push Enter in the begining of the string to stop input.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }
    print_menu();
    while ((ch = getchar()) != 'q')
    {
        if (ch != '\n')
            while (getchar() != '\n')
                continue;
        switch (ch)
        {
        case ('o'):
            puts("");
            for (k = 0; k < ct; k++)
                puts(input[k]);
            break;
        case ('a'):
            sort_ASCII(ptstr, ct);
            puts("");
            for (k = 0; k < ct; k++)
                puts(ptstr[k]);
            break;
        case ('l'):
            sort_length(ptstr, ct);
            puts("");
            for (k = 0; k < ct; k++)
                puts(ptstr[k]);
            break;
        case ('f'):
            sort_first_word_length(ptstr, ct);
            puts("");
            for (k = 0; k < ct; k++)
                puts(ptstr[k]);
            break;
        default:
            printf("Invalid input. Try again.\n");
            print_menu();
            continue;
        }

        puts("");
        print_menu();
    }
    puts("Bye!");

    return 0;
}

void sort_ASCII(char *strings[], int num)
{
    char * temp;
    int top, seek;
    for ( top = 0; top < num-1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp; 
            }
    }
    
}

void sort_length(char *strings[], int num)
{
    char * temp;
    int top, seek;
    for ( top = 0; top < num-1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
            if (strlen(strings[top]) > strlen(strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp; 
            }
    }
}

int first_word_len(char *string)
{
    int length = 0;

	// skip leading whitespace
	while (isspace(*string))
		string++;

	// count first word length
	while(!isspace(*string))
	{
		length++;
		string++;
	}

	return length;
}

void sort_first_word_length(char *strings[], int num)
{
    char * temp;
    int top, seek;
    for ( top = 0; top < num-1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
            if (first_word_len(strings[top]) > first_word_len(strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp; 
            }
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

void print_menu(void)
{
    puts("Choose an option:");
    puts("(o) Print strings in original order.");
    puts("(a) Print strings sorted by ASCII.");
    puts("(l) Print strings sorted by length from min to max.");
    puts("(f) Print strings sorted by length of the first word from min to max.");
    puts("(q) Quit.");
    puts("");
    puts("Enter a character: ");
}