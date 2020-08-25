#include "random.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void randomFillArray(int array[], int size, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = (rand() % max) + min;
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", array[i]);
    }
}
