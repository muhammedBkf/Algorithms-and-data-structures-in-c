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
void merge(int left[], int right[], int array[])
{
    int leftLenght = sizeof(left) / sizeof(left[0]);
    int rightLenght = sizeof(right) / sizeof(right[0]);
    int i, j, k;
    i = j = k = 0;
    while (leftLenght > i && rightLenght > i)
    {
        if (left[i] < right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftLenght)
    {
        array[i] = left[i];
        i++;
    }
    while (j < rightLenght)
    {
        array[j] = right[j];
        j++;
    }
}