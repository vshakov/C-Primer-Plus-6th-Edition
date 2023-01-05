/* 10_9.c */
// C Primer Plus
// Chapter 10 Exercise 9:

// Write a program that initializes a two-dimensional 3×5 array-of-double and
// uses a VLA- based function to copy it to a second two-dimensional array.
// Also provide a VLA-based function to display the contents of the two arrays.
// The two functions should be capable, in general, of processing arbitrary N×M
// arrays. (If you don’t have access to a VLA-capable compiler, use the
// traditional C approach of functions that can process an N×5 array).

#include <stdio.h>
#define ROWS 3
#define COLUMNS 5

void copy_arr(int rows, int cols, double source[rows][cols], double target [rows][cols]);
void print_arr(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    double source[ROWS][COLUMNS] = {
        {1.2, 2.3, 3.4, 4.5, 5.6},
        {6.7, 7.8, 8.9, 9.0, 0.1},
        {9.1, 1.2, 3.5, 5.7, 7.9}
    };
    double target[ROWS][COLUMNS];

    // coppy source array to target array
    copy_arr(ROWS, COLUMNS, source, target);

    // print content of source and target arrays
    printf("Source array: \n");
    print_arr(ROWS, COLUMNS, source);
    putchar('\n');

    printf("Target array: \n");
    print_arr(ROWS, COLUMNS, target);
    putchar('\n');
    
    return 0;
}

void copy_arr(int rows, int cols, double source[rows][cols], double target [rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
    }
    
}

void print_arr(int rows, int cols, double arr[rows][cols])
{
    // print the content of two arrays
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf(" %10.3f", arr[i][j]);
        
        putchar('\n');
    }
    
}
