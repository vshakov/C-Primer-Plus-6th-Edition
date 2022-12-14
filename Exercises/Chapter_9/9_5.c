/* 9_5.c -- larger_of(x, y) заменяет содержимое двух переменных double большим из их значений */
#include <stdio.h>
void larger_of(double *, double *);
int main(void)
{
    double x, y;
    printf("Введите 2 числа.\n");
    while(scanf("%lf %lf", &x, &y) == 2)
    {
        printf("x = %f y = %f\n", x, y);
        larger_of(&x, &y);
        printf("Результат: x = %f y = %f\n", x, y);
        printf("Введите еще 2 числа.\n");
    }
    return 0;
}
void larger_of(double * n, double * m)
{
    if (*n > *m)
        *m = *n;
    if(*m > *n)
        *n = *m;
}