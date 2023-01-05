/* 10_10.c */

// C Primer Plus
// Chapter 10 Exercise 10:

// Write a function that sets each element in an array to the sum of the
// corresponding elements in two other arrays. That is, if array 1 has the
// values 2, 4, 5, and 8 and array 2 has the values 1, 0, 4, and 6, the
// function assigns array 3 the values 3, 4, 9, and 14. The function should
// take three array names and an array size as arguments. Test the function in
// a simple program.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void sum_array(int *source1, int *source2, int *target, int arr_length);

int main(void)
{
    srand(time(NULL));

    int source1[SIZE];
    int source2[SIZE];
    int target[SIZE];

    // initialize arrays source1 and source2 with random inits
    for (int i = 0; i < SIZE; i++)
    {
        source1[i] = rand() % 100;
        source2[i] = rand() % 100;
    }
    
    // initialize target array with inits = summs of source arrays inits
    sum_array(source1, source2, target, SIZE);
    // print arrays
    printf("%8s %8s %8s\n", "Source array 1", "Source array 2", "Target array");
    for(int i = 0; i < SIZE; i++)
        printf("%8d %14d %14d\n", source1[i], source2[i], target[i]);
    
    return 0;
}

void sum_array(int *source1, int *source2, int *target, int arr_length)
{
    for(int *tmp = target; tmp < target + arr_length; tmp++, source1++, source2++)
        *tmp = *source1 + *source2;
}