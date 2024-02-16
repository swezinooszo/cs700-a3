#pragma once


const int NUM_OF_SORTING_ORDER = 3;
const int NUM_OF_ARRAYS = 10;

typedef int ExecutedTimeForSorting[NUM_OF_SORTING_ORDER][NUM_OF_ARRAYS];

void buildAnArray(int* arrary, int length);

void generateRandomArray(int* arrary, int length);
long executedTimeForRandomOrder(int* arrary, int length);

void sortArrayToAscendingOrder(int* arrary, int length);
long executedTimeforAscendingOrder(int* arrary, int length);

void sortArrayToInverseOrder(int* arrary, int length);
long executedTimeforInverseOrder(int* arrary, int length);

void storeExecutedTimeIntoTwoDimensionArray(ExecutedTimeForSorting executedTimeForSorting,int* integerArray, int arraySize);

void printFigureForExecutedTime(ExecutedTimeForSorting executedTimeForSorting);
