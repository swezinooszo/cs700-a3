/** @file arrayUtil.cpp
 * @author Swe Zin Oo
 * @date 16 Feb 2024
 * @brief The implementation file of "arrayUtil.h"
*/

#include <iostream>
#include <cstdlib> 
#include <chrono>
#include <iomanip>
#include "arrayUtil.h"

using namespace std;


void buildAnArray(int* arrary, int length){ 
   // fill the array with integer values with a given size
    for(int i=0;i<length;i++){
        arrary[i] = i+1;
    }
}

void sortArrayByRandomOrder(int* arrary, int length){
    //providing seed value
   srand(unsigned(time(0)));

    // Shuffle the array randomly
    for (int i = 0; i < length - 1; ++i) {
        int j = i + rand() % (length - i);
        swap(arrary[i], arrary[j]);
    }
}

long getExecutedTimeForRandomOrder(int* arrary, int length){
    // Start the timer
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    sortArrayByRandomOrder(arrary,length);
    // End the timer
    chrono::steady_clock::time_point end = chrono::steady_clock::now(); 
    // Calculate the duration
    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // Convert milliseconds to microseconds
    chrono::microseconds microseconds = chrono::duration_cast<chrono::microseconds>(duration);
    // Print the duration in seconds
    //cout << "Time taken for random order : " << duration.count() << " milliseconds" << endl;
    return microseconds.count();
}

void sortArrayByAscendingOrder(int* arrary, int length){
   sort(arrary, arrary + length);
}

long getExecutedTimeforAscendingOrder(int* arrary, int length){
    // Start the timer
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    sortArrayByAscendingOrder(arrary,length);
    // End the timer
    chrono::steady_clock::time_point end = chrono::steady_clock::now(); 
    // Calculate the duration
    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // Convert milliseconds to microseconds
    chrono::microseconds microseconds = chrono::duration_cast<chrono::microseconds>(duration);
    // Print the duration in seconds
    //cout << "Time taken for ascending order: " << duration.count() << " milliseconds" << endl;
    return microseconds.count();
}

void sortArrayByInverseOrder(int* arrary, int length){
   sort(arrary, arrary + length,greater<int>());
}

long getExecutedTimeforInverseOrder(int* arrary, int length){
    // Start the timer
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    sortArrayByInverseOrder(arrary,length);
    // End the timer
    chrono::steady_clock::time_point end = chrono::steady_clock::now(); 
    // Calculate the duration
    chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // Convert milliseconds to microseconds
    chrono::microseconds microseconds = chrono::duration_cast<chrono::microseconds>(duration);
    // Print the duration in seconds
    // cout << "Time taken for inverse order: " << duration.count() << " milliseconds" << endl;
    return microseconds.count();
}

void storeExecutedTimeIntoTwoDimensionArray(ExecutedTimeForSorting executedTimeForSorting,int* integerArray, int arraySize){

    //// ********* For ONE MILLION ARRAY ********* ////    
    // store time taken for each sorting type: random, ascending, inverse into two-dimensional array which hold 
    // 3 rows, each of which corresponds to sorting orders
    // 10 columns, each of which corresponds to an array
    for (int sortingOrder = 0; sortingOrder < NUM_OF_SORTING_ORDER; sortingOrder++){
        for(int array = 0; array < NUM_OF_ARRAYS;array++){
            //// ********* Shuffle An Array ********* ////    
            if(sortingOrder==0){
                long time = getExecutedTimeForRandomOrder(integerArray,arraySize);
                //cout << "Time taken for random order: " << time << " milliseconds" << " sortingOrder " << sortingOrder   << " array " << array << endl;
                executedTimeForSorting[sortingOrder][array] = time;
            }
            //// ********* Sort An Array to Ascending Order ********* ////    
             else if (sortingOrder==1){
                long time = getExecutedTimeforAscendingOrder(integerArray,arraySize);
               // cout << "Time taken for ascending order: " << time << " milliseconds" << " sortingOrder " << sortingOrder   << " array " << array << endl;
                executedTimeForSorting[sortingOrder][array] = time;
            }
            //// ********* Sort An Array to inverse Order ********* ////    
             else if (sortingOrder==2){
                long time = getExecutedTimeforInverseOrder(integerArray,arraySize);
               // cout << "Time taken for inverse order: " << time << " milliseconds" << " sortingOrder " << sortingOrder   << " array " << array << endl;
                executedTimeForSorting[sortingOrder][array] = time;
            }
        }
    }
}

void printFigureForExecutedTime(ExecutedTimeForSorting executedTimeForSorting){
    
    cout << right << setw(14) << "Order\\Array";
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
