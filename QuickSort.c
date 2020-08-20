#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include"SortingAlgos.h"

int partition( int a[], int l, int r) {
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r+1;

    while(1)
    {
        do ++i; while( a[i] <= pivot && i <= r );
        do --j; while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r )
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }

}
//void quickSort1( int a[], int l, int r)
//{
//    int swapIndex = l;
//    int pivot = a[r];
//
//    if(l>=r) return;
//    else {
//        for (int i = 0; i < r; i++) {
//            if (a[i] < pivot) {
//                int t = a[i];
//                a[i] = a[swapIndex];
//                a[swapIndex] = t;
//                swapIndex++;
//            }
//        }
//        int t = a[r];
//        a[r] = a[swapIndex];
//        a[swapIndex] = t;
//        quickSort1(a, l, swapIndex - 1);
//        quickSort1(a, swapIndex + 1, r);
//    }
//
//}

