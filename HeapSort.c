#include <stdio.h>
#include <stdlib.h>
#include "SortingAlgos.h"

int max (int *arr, int arrSize, int i, int j, int k) { // returns the maximum
    int m = i;                         // of the parent and its children
    if (j < arrSize && arr[j] > arr[m]) {
        m = j;
    }
    if (k < arrSize && arr[k] > arr[m]) {
        m = k;
    }
    return m;
}

void downheap (int *arr, int arrSize, int i) {
    while (1) {
        int j = max(arr, arrSize, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = arr[i];  // if arr[i] (parent) is not the max, swap it with
        arr[i] = arr[j]; // arr[j] which will be max then.
        arr[j] = t;
        i = j;
    }
}

void heapSort (int *arr, int arrSize) {
    int i;
    for (i = (arrSize - 2) / 2; i >= 0; i--) { // set 'i' equal to the first non-leaf
        downheap(arr, arrSize, i);  // node and convert it into a heap and iterate it
    }                               // till you reach the root
    for (i = 0; i < arrSize; i++) {  // swap the root of the heap with the last unsorted
        int t = arr[arrSize - i - 1]; // element of the heap
        arr[arrSize - i - 1] = arr[0];
        arr[0] = t;
        downheap(arr, arrSize - i - 1, 0); // and then convert it to heap again
    }
}
