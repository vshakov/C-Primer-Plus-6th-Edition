/* 9_6.c -- void sort(double * x, double * y, double * z) принимает в качестве аргументов адреса трех
переменных и помещает наименьшее значение в первую переменную, среднее - во вторую, наибольшее - в третью */
#include <stdio.h>
void sort(double *, double *, double *);
int main(void)
{
    double x, y, z;
    printf("Введите 3 значения.\n");
    while(scanf("%lf %lf %lf", &x, &y, &z) == 3)
    {
        putchar('\n');
        printf("x = %f, y = %f, z = %f", x, y, z);
        sort(&x, &y, &z);
        putchar('\n');
        printf("Результат:\n");
        printf("x = %f, y = %f, z = %f", x, y, z);
        putchar('\n');
        printf("Введите еще 3 значения.\n");
    }
    
    return 0;
}
void sort(double * a, double * b, double * c)
{
    double tmp;
    if (*a > *b)
    {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    if (*a > *c)
    {
        tmp = *a;
        *a = *c;
        *c = tmp;
    }
    if (*b > *c)
    {
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
}