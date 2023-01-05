/* 10_7.c */

// C Primer Plus
// Chapter 10 Exercise 7:

// Write a program that initializes a two-dimensional array-of-double and uses
// one of the copy functions from exercise 2 to copy it to a second two
// dimensional array. (Because a two-dimensional array is an array of arrays, a
// one-dimensional copy function can be used with each subarray.)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void copy_ptr(double *target, const double *source, int arr_length);      // копирует значения массива source в массив target форма записи с указателями
void print_row(const double (*arr) [COLS], int row);

int main(void)
{
    // copy one 10 by 10 array to another 10 by 10 array

    double source[ROWS][COLS];
    double target[ROWS][COLS];

    // initialize source array
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            source[i][j] = rand() / (double) RAND_MAX;
    
    // copy source array to target
    for(int i = 0; i < ROWS; i++)
        copy_ptr(target[i], source[i], COLS);
    //print arrays
    printf("%-50s", "Source");
    printf("   ");
	printf("%-50s", "Target");
	putchar('\n');
    for(int i = 0; i < 103; i++)
        putchar('-');
    putchar('\n');
    for(int i = 0; i < 10; i++)
    {
        print_row(source, i);
        printf("   ");
		print_row(target, i);
		putchar('\n');
    }

    return 0;
}

void copy_ptr(double *target, const double *source, int arr_length)
{
    // copy array using pointer notation

    for(int i = 0; i < arr_length; i++)
        *(target + i) = *(source + i);
}

void print_row(const double (*arr) [COLS], int row)
{
    // print a row from a ROWS by COLS array of doubles

    for(int i = 0; i < COLS; i++)
        printf("%.2f ", arr[row][i]);
}