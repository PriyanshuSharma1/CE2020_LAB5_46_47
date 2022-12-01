#ifndef sorting_h
#define sorting_h

void insertionSort(int list[], int ArraySize);
void swapPlace(int *list, int first, int second);
int partition(int *list, int low, int high);
void quickSort(int *list, int low, int high);
#endif