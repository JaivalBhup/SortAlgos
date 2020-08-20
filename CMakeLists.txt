cmake_minimum_required(VERSION 3.16)
project(measuringElapsedTime C)

set(CMAKE_C_STANDARD 99)

add_executable(measuringElapsedTime measurementOfElapsedTime.c SortingAlgos.h InsertionSort.c SelectionSort.c HeapSort.c QuickSort.c)