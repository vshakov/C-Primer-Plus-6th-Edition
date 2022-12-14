/* 9_4.c -- double average_harmonic(double x, double y) принимает два аргумента double и
возвращает среднее гармониеское этих чисел */
#include <stdio.h>
double average_harmonic(double, double);
int main(void)
{
    double n, m;
    printf("Введите два числа типа double.\n");
    while((scanf("%lf %lf", &n, &m) == 2))
    {
        printf("%.2f\n", average_harmonic(n, m));
        printf("Введите еще два числа типа double.\n");
        printf("Введите q для выхода.\n");
    }
    return 0;
}

double average_harmonic(double x, double y)
{
    double result;
    result = 2/((1/x)+(1/y));
    return result;
}