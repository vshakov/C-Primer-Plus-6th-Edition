/* 9_1.c --min(x,y) возвращает меньшее из двух значений */
#include <stdio.h>
double min(double, double);
int main(void)
{
    double x, y;
    printf("Введите 2 значения типа double (или q для завершения).\n");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        printf("Меньшим из двух значений %f и %f является %f.\n", x, y, min(x,y));
        printf("Введите 2 значения типа double (или q для завершения).\n");
    }
    printf ("Программа завершена.\n");

    return 0;
}

double min(double n, double m)
{
    return (n < m ? n : m);
}
