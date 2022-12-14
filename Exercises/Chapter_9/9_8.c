/* 9_8.c */
// C Primer Plus
// Chapter 9 Exercise 8

// Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power()
// function that returned the result of raising a type double number to a
// positive integer value. Improve the function so that it correctly handles
// negative powers. Also, build into the function that 0 to any power other
// than 0 is 0 and that any number to the 0 power is 1. (It should report that
// 0 to the 0 is undefined, then say it’s using a value of 1.) Use a loop. Test
// the function in a program.

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
    double pow = 1;
    int i;

    if(n == 0 && p == 0)
    {
        printf("Ошибка! 0 в степени 0. Используется 1.\n");
        return 1;
    }
    for(i = 0; i < abs(p); i++)
        pow *= n;
    if(p < 0)
        pow = 1/pow;

    return pow;
}