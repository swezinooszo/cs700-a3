/** @file main.cpp
 * @author Swe Zin Oo
 * @date 16 Feb 2024
 * @brief This 'main.cpp' file is designed to sort arrays in three different orders: random, ascending, and reverse. It then calculates the time 
 * taken to perform each sorting operation. To analyze the impact of array size and initial data order, the program evaluates arrays of three different sizes: 
 * Hundred Thousand, One Million, and Ten Million elements. For each size, ten arrays are sorted in each of the three orders, and the execution times 
 * are stored in a two-dimensional array to present the final results. This file utilize the functions from "arrayUtil.h" file to achieve the desired result.
*/

#include <iostream>
#include <cstdlib> 
#include <chrono>
#include <iomanip>
#include "arrayUtil.h"

using namespace std;

const int HUNDRED_THOUSAND = 100000;
const int ONE_MILLION = 1000000;
const int TEN_MILLION = 10000000;


int main(){

    //// **************** HUNDRED_THOUSAND SIZE ***************************** ////
    //// ********* Initialize an Integer array with HUNDRED_THOUSAND Size ********* ////
    int* hundredThousand_array = new int[HUNDRED_THOUSAND];
    //// ********* Fill the Array with numbers ********* ////
    buildAnArray(hundredThousand_array,HUNDRED_THOUSAND);

    //// ****** Create Two Dimensional array to store figure for executed time of sorting ****** ////
    ///// row represents three sorting orders which is random, ascending and inverse
    //// column represents ten arrays which will be executed for each sorting order
    int executedTimeForSorting_hundredThousand[NUM_OF_SORTING_ORDER][NUM_OF_ARRAYS];
    //// ****** Store excuted time for sorting the array in various orders into two dimensional array ****** ////
    //// in which the array has a size of hundred thousand and fill with integer values
    storeExecutedTimeIntoTwoDimensionArray(executedTimeForSorting_hundredThousand,hundredThousand_array,HUNDRED_THOUSAND);
    //// ****** Print Two Dimension array as Figure ****** ////
    printFigureForExecutedTime(executedTimeForSorting_hundredThousand);

    cout << right << setw(50) << "--------------------------------------------------" << " HUNDRED THOUSAND ARRAY SIZE " << "---------------------------------------------" << right << setw(50);
    cout << endl;
    cout << endl;


    //// **************** ONE_MILION SIZE ***************************** ////
    //// ********* Initialize an Integer array with ONE_MILION Size ********* ////
     int* onemillion_array = new int[ONE_MILLION];
    //// ********* Fill the Array with numbers ********* ////
    buildAnArray(onemillion_array,ONE_MILLION);

     //// ****** Create Two Dimensional array to store figure for executed time of sorting ****** ////
    ///// row represents three sorting orders which is random, ascending and inverse
    //// column represents ten arrays which will be executed for each sorting order
    int executedTimeForSorting_onemillion[NUM_OF_SORTING_ORDER][NUM_OF_ARRAYS];
    //// ****** Store excuted time for sorting the array in various orders into two dimensional array ****** ////
    //// in which the array has a size of one million and fill with integer values
    storeExecutedTimeIntoTwoDimensionArray(executedTimeForSorting_onemillion,onemillion_array,ONE_MILLION);
     //// ****** Print Two Dimension array as Figure ****** ////
    printFigureForExecutedTime(executedTimeForSorting_onemillion);

    cout << right << setw(50) << "--------------------------------------------------" << " ONE MILLION ARRAY SIZE " << "--------------------------------------------------" << right << setw(50);
    cout << endl;
    cout << endl;


    //// **************** TEN_MILION SIZE ***************************** ////
    //// ********* Initialize an Integer array with ONE_MILION Size ********* ////
    int* tenmillion_array = new int[TEN_MILLION];
    //// ********* Fill the Array with numbers ********* ////
    buildAnArray(tenmillion_array,TEN_MILLION);

    //// ****** Create Two Dimensional array to store figure for executed time of sorting ****** ////
    ///// row represents three sorting orders which is random, ascending and inverse
    //// column represents ten arrays which will be executed for each sorting order
    int executedTimeForSorting_tenmillion[NUM_OF_SORTING_ORDER][NUM_OF_ARRAYS];
    //// ****** Store excuted time for sorting the array in various orders into two dimensional array ****** ////
    //// in which the array has a size of ten million and fill with integer values
    storeExecutedTimeIntoTwoDimensionArray(executedTimeForSorting_tenmillion,tenmillion_array,TEN_MILLION);
     //// ****** Print Two Dimension array as Figure ****** ////
    printFigureForExecutedTime(executedTimeForSorting_tenmillion);

    cout << right << setw(50) << "--------------------------------------------------" << " TEN MILLION ARRAY SIZE " << "--------------------------------------------------" << right << setw(50);
    cout << endl;
    cout << endl;

    return 0;
}