#include "sort.h"
#include <stdio.h>
void bubbleSort(int array[], int size)
{
    char done = 0;
    while (!done)
    {
        done = 1;
        for (int i = 0; i < size - 2; i++)
        {
            if (array[i] > array[i + 1])
            {
                //swap
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                done = 0;
            }
        }
    }
}

void selectionSort(int array[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        //Find the minimum element in unsorted array
        int minIndex = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        //swap the found element
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}
void insertionSort(int array[], int size)
{
    for (int i = 1; i < size - 1; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (array[j] > key && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
