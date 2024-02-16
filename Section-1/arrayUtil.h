/** @file arrayUtil.h
 * @author Swe Zin Oo
 * @date 16 Feb 2024
 * @brief This is the utility class of the program. It include all the functios such as sorting an array in various orders,
 * get the execution time for sorting the array and printing the array as a figure which will be used in the main program.
*/
#pragma once


const int NUM_OF_SORTING_ORDER = 3;
const int NUM_OF_ARRAYS = 10;

typedef int ExecutedTimeForSorting[NUM_OF_SORTING_ORDER][NUM_OF_ARRAYS];

/** Fill the array with numbers with given length. If the length is 100, the array is filled with 100 numbers.
 * @param array An array to fill with numbers
 * @param length the size of the array
*/ 
void buildAnArray(int* arrary, int length);
/** Sort the given array in random order
 * @param array An array to be sorted as random order
 * @param length the size of the array
*/ 
void sortArrayByRandomOrder(int* arrary, int length);
/** Calculate the execution time required to sort an array of random order with a given size.
 * This function solely calculates the execution time and relies on "sortArrayByRandomOrder()" function to sort an array in random order.
 * @param array An array to be sorted randomly
 * @param length the size of the array
 * @pre The sortArrayByRandomOrder() function must be present
*/ 
long getExecutedTimeForRandomOrder(int* arrary, int length);
/** Sort the given array in ascending order
 * @param array An array to be sorted in ascending order
 * @param length the size of the array
*/ 
void sortArrayByAscendingOrder(int* arrary, int length);
/** Calculate the execution time required to sort an array of ascending order with a given size.
 * This function solely calculates the execution time and relies on "sortArrayByAscendingOrder()" function to sort an array in ascending order.
 * @param array An array to be sorted in ascending order
 * @param length the size of the array
 * @pre The sortArrayByAscendingOrder() function must be present
*/
long getExecutedTimeforAscendingOrder(int* arrary, int length);
/** Sort the given array in reverse order
 * @param array An array to be sorted in reverse order
 * @param length the size of the array
*/ 
void sortArrayByInverseOrder(int* arrary, int length);
/** Calculate the execution time required to sort an array of reverse order with a given size.
 * This function solely calculates the execution time and relies on "sortArrayByInverseOrder()" function to sort an array in reverse order.
 * @param array An array to be sorted in reverse order
 * @param length the size of the array
 * @pre The sortArrayByInverseOrder() function must be present
*/
long getExecutedTimeforInverseOrder(int* arrary, int length);
/** Store the execution time required to sort an array in various orders (random, ascending and reverse) with a given size into two dimensional array 
 * It relies on other functions to get the execution time for sorting the array in the respective orders (random,ascending and reverse).
 * The other functions are "getExecutedTimeForRandomOrder()", "getExecutedTimeforAscendingOrder()" and "getExecutedTimeforInverseOrder()".
 * @param ExecutedTimeForSorting A two-dimensional array, with three rows representing three sorting orders (random,ascending and reverse) and ten 
 *  columns representing ten arrays to be sorted in those orders.
 * @param array An array to be used in "getExecutedTimeForRandomOrder()", "getExecutedTimeforAscendingOrder()" and "getExecutedTimeforInverseOrder()"
 * to get the execution time
 * @param the size of the array to be used in "getExecutedTimeForRandomOrder()", "getExecutedTimeforAscendingOrder()" and "getExecutedTimeforInverseOrder()"
 * to get the execution time
*/
void storeExecutedTimeIntoTwoDimensionArray(ExecutedTimeForSorting executedTimeForSorting,int* integerArray, int arraySize);
/** Print the two-dimensional array as a figure 
 * @param ExecutedTimeForSorting a two-dimensional array
*/
void printFigureForExecutedTime(ExecutedTimeForSorting executedTimeForSorting);
