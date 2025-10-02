// Compile with: gcc -Wall insertion_test.c -o insertion_test.out
// Windows: change .out to .exe
// Run with: ./insertion_test.out

#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()

#include "sorts.h"


// =============== Main Functions ===============
int main(int argc, char *argv[])
{

    // Some test data sets.
    int dataset1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dataset2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int dataset3[] = {0, 3, 2, 1, 4, 7, 6, 5, 8, 9, 10};
    int dataset4[] = {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int dataset5[] = {100, 201, 52, 3223, 24, 55, 623, 75, 8523, -9, 150};
    int dataset6[] = {-1, 1, 2, -3, 4, 5, -6, 7, 8, -9, 10};
    int dataset7[] = {};

    int print = 1;
    unsigned int size = 11;
    // Sort our integer array

    printIntArray(dataset1, size);
    insertionSortIntegers(dataset1, size, print);
    printf("\n");
    printIntArray(dataset1, size);
    printf("========\n");
    printIntArray(dataset2, size);
    insertionSortIntegers(dataset2, size, print);
    printf("\n");
    printIntArray(dataset2, size);
    printf("========\n");
    printIntArray(dataset3, size);
    insertionSortIntegers(dataset3, size, print);
    printf("\n");
    printIntArray(dataset3, size);
    printf("========\n");
    printIntArray(dataset4, size);
    insertionSortIntegers(dataset4, size, print);
    printf("\n");
    printIntArray(dataset4, size);
    printf("========\n");
    printIntArray(dataset5, size);
    insertionSortIntegers(dataset5, size, print);
    printf("\n");
    printIntArray(dataset5, size);
    printf("========\n");
    printIntArray(dataset6, size);
    insertionSortIntegers(dataset6, size, print);
    printf("\n");
    printIntArray(dataset6, size);
    printf("========\n");
    printIntArray(dataset7, 0);
    insertionSortIntegers(dataset7, 0, print);
    printf("\n");
    printIntArray(dataset7, 0);
    printf("========\n");

    // make sure to add your own tests, such what happens when the dataset is {}?

    return 0;
}