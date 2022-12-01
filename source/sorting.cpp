/*
Authors names: Priyanshu Sharma, Soniya Sharma
Date created : November 21, 2022
Sorting randomly generated array using merge sort and quick sort
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include"sorting.h"

using namespace std;
int length = 1000;
const int max_length = 500000;

void insertionSort(int list[], int ArraySize)
{

    int i, key, j;
    for (i = 1; i < ArraySize; i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}
// define qiucksort function
void swapPlace(int *list, int first, int second)
{

    int temp = list[first];
    int temp2 = list[second];
    list[first] = list[second];
    list[second] = temp;
}
int partition(int *list, int low, int high)
{
    int pivot = list[high];
    int i = low;
    for (int j = low; j <= high; j++)
    {
        if (list[j] < pivot)
        {
            swapPlace(list, i, j);
            i++;
        }
    }
    swapPlace(list, high, i);
    return i;
}
void quickSort(int *list, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(list, low, high);
        quickSort(list, low, pivot - 1);
        quickSort(list, pivot + 1, high);
    }
}
