/// to compile: gcc -Wall tester.c -o tester.out

#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()
#include <stdbool.h>

#include "sorts.h"

// these are called function pointers
void (*sorts[])(int *, unsigned int, int) = {
    bubbleSortIntegers,
    selectionSortIntegers,
    insertionSortIntegers,
    mergeSortIntegers,
    quickSortIntegers};

int *get_random_array(int size)
{
    // Allocate memory
    int *random = (int *)malloc(sizeof(int) * size);

    // Populate our test data set
    for (int i = 0; i < size; i++)
    {
        // Generate random values from 0 to 99
        random[i] = rand() % size;
    }
    return random;
}

double sort_and_time(int *array, int size, int type, int print)
{
    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC, &begin);
    // Perform the sort
    sorts[type](array, size, print);
    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC, &end);

    return (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}

// tests a single sorting algorithm, often best for small runs
void test_one(int type, int size, int print)
{
    int *random = get_random_array(size);

    if (print)
    {
        printf("Before the sort: ");
        printIntArray(random, size);
    }

    double time_taken = sort_and_time(random, size, type, print);

    // Confirm the sort worked
    if (print)
    {
        printf("After the sort : ");
        printIntArray(random, size);
    }

    printf("Total time = %f seconds\n", time_taken);

    // Free our random array
    free(random);
}

int *get_copy(int *array, int size)
{
    int *copy = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        copy[i] = array[i];
    }
    return copy;
}

// tests a group of algorithms, does not print out the results, just the timings
void test_all(int size)
{
    int *random = get_random_array(size);
    int *original = get_copy(random, size);

    double timings[] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        timings[i] = sort_and_time(random, size, i, false);
        for (int j = 0; j < size; j++)
        { // reset the array after sorted
            random[j] = original[j];
        }
    }

    printf("|%d|%f|%f|%f|%f|%f|\n", size, timings[0], timings[1], timings[2],
           timings[3], timings[4]);
    
    

    free(random);
    free(original);
}

// test just merge_quick since the timings are so much quicker
void test_merge_quick(int size)
{
    int *random = get_random_array(size);
    int *original = get_copy(random, size);

    double timings[] = {0, 0, 0, 0, 0};
    for (int i = 3; i < 5; i++)
    {
        timings[i] = sort_and_time(random, size, i, false);
        for (int j = 0; j < size; j++)
        { // reset the array after sorted
            random[j] = original[j];
        }
    }

    printf("|%d|-|-|-|%f|%f|", size, timings[3], timings[4]);
    

    free(random);
    free(original);
}

int main(){
    // test_all(10);
    // test_all(100);
    // test_all(500);
    // test_all(1000);
    // test_all(5000);
    // test_all(10000);
    // test_all(50000);
    // test_all(100000);
    test_all(500000);
    // test_all(1000000);
    return 0;
}