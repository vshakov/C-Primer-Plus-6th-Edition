/* 10_6.c */
// C Primer Plus
// Chapter 10 Exercise 6:

// Write a function that reverses the contents of an array of double and test
// it in a simple program.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void reverse_array(double * arr, int arr_size);

int main(void)
{
    double test[10];

    srand(time(NULL));

    // initialize test array with random 10 doubles
    for (int i = 0; i < SIZE; i++)
        test[i] = rand() / (double) RAND_MAX;
    printf("%10s", "Original");
    for (int i = 0; i < SIZE; i++)
        printf("%5.2f ", test[i]);
    putchar('\n');

    reverse_array(test, SIZE);

    // print reversed array

    printf("%10s", "Reversed");
    for (int i = 0; i < SIZE; i++)
        printf("%5.2f ", test[i]);
    putchar('\n');


    return 0;
}

void reverse_array(double * arr, int arr_size)
{
    // reverse an array of double

    double tmp;

    for (int i = 0; i < SIZE / 2; i++)
    {
        // swap values between i and (arr_size - 1 - i)
        tmp = arr[i];
        arr[i] = arr[arr_size - 1 - i];
        arr[arr_size - 1 - i] = tmp;
    }
    
}