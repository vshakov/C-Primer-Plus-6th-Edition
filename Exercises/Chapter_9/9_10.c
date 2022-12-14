// C Primer Plus
// Chapter 9 Exercise 10:

// Generalize the to_binary() function of Listing 9.8 to a to_base_n() function
// that takes a second argument in the range 2–10. It then should print the
// number that is its first argument to the number base given by the second
// argument. For example, to_ base_n(129,8) would display 201, the base-8
// equivalent of 129. Test the function in a complete program.

#include <stdio.h>
#include <stdlib.h>

void to_base_n(unsigned long n, unsigned int base);
int main(void)
{
    unsigned long number;
    unsigned int base;
    printf("Введите положительное целое число (q для выхода):\n");
    while (scanf("%lu %u", &number, &base) == 2)
    {
        printf("Число %lu по основанию %u равно ", number, base);
        to_base_n(number, base);
        putchar('\n');
        printf("Введите положительное целое число (q для выхода):\n");
    }
    printf("Программа завершена.\n");
    return 0;
}
void to_base_n(unsigned long n, unsigned int base)
{
    int r;
    r = n % base;   
    if(n>=2)
        to_base_n(n/base, base);
    printf("%ld", n%base);
    return;
} 