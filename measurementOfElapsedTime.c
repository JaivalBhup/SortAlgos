
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortingAlgos.h"
#define ARRSIZE 50000 // size of the array
#define RANGE 3000000 // Maximum for pseudo-random number generator
#define OFFSET 1   // Minimum for pseudo-random number generator
#define NUM_OF_RECORDS_TO_PRINT 50
void printArray(int arr[], int len);
int main()
{
    static int arr[ARRSIZE];
    srand(time(NULL));
    for(int ctr = 0; ctr < ARRSIZE; ctr++)
        arr[ctr]= (rand() * rand())% (RANGE + 1) + OFFSET;
    printArray(arr, ARRSIZE);

    clock_t startTime, stopTime; //variables of clock_t type declared for start and stop times
    float elapsedTime; // variable of float type for elapsed time
    startTime = clock(); //start time saved
    quickSort1(arr,0, ARRSIZE-1);

    stopTime = clock();// stop time saved
    elapsedTime = (float)(stopTime - startTime)/CLOCKS_PER_SEC; // elapsed time calculated
    printf("\nInsertion sort time: %6.3f s\n",elapsedTime);
    printArray(arr, ARRSIZE);
    return 0;
} // main function ends

void printArray(int arr[], int len)
{
    int start, end;
    if (len < NUM_OF_RECORDS_TO_PRINT){
        start = 0;
        end = len;
    }
    else {
        start = len - NUM_OF_RECORDS_TO_PRINT;
        end = len;
    }
    for (int dex = start; dex < end; dex++)
    {
        printf(dex % 10 ? "": "\n");
        printf("%8d  ", arr[dex]);
    }
    printf("\n");
}//ends printArr method


