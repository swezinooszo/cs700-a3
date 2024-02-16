#include <iostream>
#include <cstdlib> 
#include <chrono>
#include <iomanip>
#include "arrayUtil.h"

using namespace std;


// fill the array with integer values with defined array size
void buildAnArray(int* arrary, int length){ 
   // build array wiht numbers from 1 to given length
    for(int i=0;i<length;i++){
        arrary[i] = i+1;
    }
}

void generateRandomArray(int* arrary, int length){
    //providing seed value
   srand(unsigned(time(0)));

    // Shuffle the array randomly
    for (int i = 0; i < length - 1; ++i) {
        int j = i + rand() % (length - i);
        swap(arrary[i], arrary[j]);
    }
}

long executedTimeForRandomOrder(int* arrary, int length){
    // Start the timer
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    generateRandomArray(arrary,length);
    // End the timer
    chrono::steady_clock::time_point end = chrono::steady_clock::now(); 
    // Calculate the duration
    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // Print the duration in seconds
    //cout << "Time taken for random order : " << duration.count() << " milliseconds" << endl;
    return duration.count();
}

void sortArrayToAscendingOrder(int* arrary, int length){
   sort(arrary, arrary + length);
}

long executedTimeforAscendingOrder(int* arrary, int length){
    // Start the timer
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    sortArrayToAscendingOrder(arrary,length);
    // End the timer
    chrono::steady_clock::time_point end = chrono::steady_clock::now(); 
    // Calculate the duration
    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // Print the duration in seconds
    //cout << "Time taken for ascending order: " << duration.count() << " milliseconds" << endl;
    return duration.count();
}

void sortArrayToInverseOrder(int* arrary, int length){
   sort(arrary, arrary + length,greater<int>());
}

long executedTimeforInverseOrder(int* arrary, int length){
    // Start the timer
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    sortArrayToInverseOrder(arrary,length);
    // End the timer
    chrono::steady_clock::time_point end = chrono::steady_clock::now(); 
    // Calculate the duration
    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // Print the duration in seconds
    // cout << "Time taken for inverse order: " << duration.count() << " milliseconds" << endl;
    return duration.count();
}

// store executed time by order for 10 arrays
// ** the method will calculate the executed time for sorting the array by random, ascending and inverse orders. The executed time will also perfrom
// ** based on number of arrays for each order.
// ** executedTimeSorting : the two dimension array to store executed time by random , ascending and inverse orders for 10 arrays
// ** hundredThousandArray : the array to make sorting for random , ascending and inverse orders 
// ** arraySize: the array size to make sorting for random , ascending and inverse orders 
void storeExecutedTimeIntoTwoDimensionArray(ExecutedTimeForSorting executedTimeForSorting,int* integerArray, int arraySize){

    //// ********* For ONE MILLION ARRAY ********* ////    
    // store time taken for each sorting type: random, ascending, inverse to two-dimensional array which hold 
    // 3 rows, each of which corresponds to a sorting
    // 10 columns, each of which corresponds to an array
    for (int sortingOrder = 0; sortingOrder < NUM_OF_SORTING_ORDER; sortingOrder++){
        for(int array = 0; array < NUM_OF_ARRAYS;array++){
            //// ********* Shuffle An Array ********* ////    
            if(sortingOrder==0){
                long time = executedTimeForRandomOrder(integerArray,arraySize);
                //cout << "Time taken for random order: " << time << " milliseconds" << " sortingOrder " << sortingOrder   << " array " << array << endl;
                executedTimeForSorting[sortingOrder][array] = time;
            }
            //// ********* Sort An Array to Ascending Order ********* ////    
             else if (sortingOrder==1){
                long time = executedTimeforAscendingOrder(integerArray,arraySize);
               // cout << "Time taken for ascending order: " << time << " milliseconds" << " sortingOrder " << sortingOrder   << " array " << array << endl;
                executedTimeForSorting[sortingOrder][array] = time;
            }
            //// ********* Sort An Array to inverse Order ********* ////    
             else if (sortingOrder==2){
                long time = executedTimeforInverseOrder(integerArray,arraySize);
               // cout << "Time taken for inverse order: " << time << " milliseconds" << " sortingOrder " << sortingOrder   << " array " << array << endl;
                executedTimeForSorting[sortingOrder][array] = time;
            }
        }
    }
}

void printFigureForExecutedTime(ExecutedTimeForSorting executedTimeForSorting){
    
    cout << right << setw(14) << "Ordering\\Array";
    for(int array=0;array<NUM_OF_ARRAYS;array++){
        cout << right << setw(11) << array+1;
    }

    cout << endl;
    for(int sortingOrder=0;sortingOrder<NUM_OF_SORTING_ORDER;sortingOrder++){
        if(sortingOrder == 0){
            cout << right << setw(14) << "Random";
        }
        if(sortingOrder == 1){
            cout << right << setw(14) << "Ascending";
        }
        if(sortingOrder == 2){
            cout << right << setw(14) << "Inverse";
        }
        for(int array=0;array<NUM_OF_ARRAYS;array++){
            cout << right << setw(11) << executedTimeForSorting[sortingOrder][array];
        }
        cout << endl;
    }
}
