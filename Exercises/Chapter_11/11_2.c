/* 11_2.c */

// C Primer Plus
// Chapter 11 Exercise 2:

// Modify and test the function in exercise 1 so that it stops after n
// characters or after the first blank, tab, or newline, whichever comes
// first. (Don’t just use scanf().)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30

char * sgetnchar(char * array, int n);

int main(void)
{
    char hello[SIZE] = "Hello, ";
    int space = SIZE - strlen(hello) - 1;

    printf("What's your name? (enter %d characters)\n", space);
    sgetnchar(hello + 7, space);
    puts(hello);
    return 0;
}
// gets n characters from input and stores them in character array
char * sgetnchar(char * array, int n){
char ch;

for (int i = 0; i < n; i++){
    if ((ch = getchar()) == EOF || isspace(ch))
      break;
    *(array + i) = ch;
}

return array;
}