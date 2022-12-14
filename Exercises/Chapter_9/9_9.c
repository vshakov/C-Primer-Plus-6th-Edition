/* 9_8.c */
// C Primer Plus
// Chapter 9 Exercise 8

// Redo Programming Exercise 8, but this time use a recursive function.

#include <stdio.h>
#include <stdlib.h>             // prototype for abs() 
double power(double n, int p);
int main(void)
{
    double x, xpow;
    int exp;

    printf("Введите число и положительную целую степень,"
            "в которую число будет возведено.\n"
            "Для завершения программы введите q.\n");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf("%.3g в степени %d равно %.5g\n", x, exp, xpow);
        printf("Введите следующую пару чисел или q для завершения.\n");
    }
    printf("Готово.\n");

    return 0;
}

double power(double n, int p)
{
    double pow;

    if(n == 0 && p == 0)
    {
        printf("Ошибка! 0 в степени 0. Используется 1.\n");
        return 1;
    }
    if(p == 0)
        return 1;                       // stop recursion
    pow = n * power(n, abs(p) - 1);     // recursion step

    if(p < 0)
        pow = 1/pow;

    return pow;
}