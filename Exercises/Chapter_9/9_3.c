/* 9_3.c -- void display(ch, int width, int lines) - выводит заданное количество символов в строке 
                                                     и указанное количество таких строк */
#include <stdio.h>
void display(char cr, int width, int lines);
int main(void)
{
    int ch;                 // выводимый символ
    int rows, cols;         // количество столбцов и строк

    printf("Введите символ и два целых числа.\n");
    while ((ch = getchar()) != '\n')
    {
        if(scanf("%d %d", &rows, &cols) != 2)
            break;
        display(ch, rows, cols);
        while (getchar() != '\n')
            continue;
        printf("Введите еще символ и два целых числа.\n");
        printf("Введите пробел для завершения.\n");
    }
    return 0;
}

void display(char cr, int width, int lines)
{
    int row, col;

    for ( row = 0; row < lines; row++)
    {
        for ( col = 0; col < width; col++)
            putchar(cr);
        putchar('\n');      // закончить строку и начать новую
    }
}