/* 10_2.c */

// C Primer Plus
// Chapter 10 Exercise 2:

// Write a program that initializes an array-of-double and then copies the
// contents of the array into three other arrays. (All four arrays should be
// declared in the main program.) To make the first copy, use a function with
// array notation. To make the second copy, use a function with pointer
// notation and pointer incrementing. Have the first two functions take as
// arguments the name of the target array, the name of the source array, and
// the number of elements to be copied. Have the third function take as
// arguments the name of the target, the name of the source, and a pointer to
// the element following the last element of the source.

#include <stdio.h>
#define LENGTH 5

// protorype declarations
void copy_arr(double * target, const double * source, int arr_length);                      // копирует значения массива source в массив target форма записи с массивами
void copy_ptr(double * target, const double * source, int arr_length);                      // копирует значения массива source в массив target форма записи с указателями
void copy_ptrs(double * target, const double * source_start, const double * source_end);    // копирует значения массива source в массив target форма записи с указателями 
                                                                                            // начала и конца массива target
int main(void)
{
    const double source[LENGTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[LENGTH];
    double target2[LENGTH];
    double target3[LENGTH];

    copy_arr(target1, source, LENGTH);
    copy_ptr(target2, source, LENGTH);
    copy_ptrs(target3, source, source + LENGTH);

    printf("%15s|%15s|%15s|%15s\n", "source", "target1", "target2", "target3");
    for(int i = 0; i < LENGTH; i++)
        printf("%15.1f|%15.1f|%15.1f|%15.1f\n", source[i], target1[i], target2[i], target3[i]);
    return 0;
}

void copy_arr(double * target, const double * source, int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        target[i] = source[i];
    }
}

void copy_ptr(double * target, const double * source, int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        *(target + i) = *(source + i);
    }
}

void copy_ptrs(double * target, const double * source_start, const double * source_end)
{
    for(const double * ptr = source_start; ptr < source_end; ptr++, target++)
        *target = *ptr;
}