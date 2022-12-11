/* 9_2.c -- chline(ch, i, j) выводит требуемый символ в столбцах с i по j */
#include <stdio.h>
void chline(char ch, unsigned int i, unsigned int j);
int main(void)
{
    int ch;
    unsigned int i, j;
    printf("Введите символ, номер начального столбца и номер конечного столбца:\n");
    while ((ch = getchar()) != '\n')
    {
        if (scanf("%u %u", &i, &j) != 2)
            break;
        chline(ch, i, j);
        while(getchar() != '\n')
            continue;
        printf("Введите символ, номер начального столбца и номер конечного столбца:\n");
        printf("Введите символ новой строки для выхода.\n");
    }
    
    return 0;
}

void chline(char ch, unsigned int i, unsigned int j)
{
    unsigned int col;
    for ( col = 1; col < i; col++)
        putchar(' ');
    for (; col <= j; col++)
        putchar(ch);
    putchar('\n');    
}