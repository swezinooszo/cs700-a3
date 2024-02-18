/** @file sin_cos.cpp
*   @author Swe Zin Oo
*   @date 18 Feb 2024
*   @brief The "sin_cos.cpp" file includes calculation of sine and cosine of an angle expressed in degrees.
*         The result will be an integer representing the sine or cosine as ten-thousandths. 
*         For example, a result of 7071 represents 7071e-4 or 0.7071. The purpose of this program is to do
*         a white-box testing to ensure all these functions work correctly with different angles. A test driver
*         is utilized to undergo testing and validation, determining the test result (pass or fail).
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Forward declarations
int sin0to45(int);
int sin45to90(int);
int polyEval(int, int[], int);

/** Compute the sine of an angle in degrees.
    @param x The angle in degrees
    @return The sine of x
*/
int sin(int x) {
  if (x < 0) {
    x = -x;
  }
  x = x % 360;
  if (0 <= x && x <= 45) {
    return sin0to45(x);
  }
  else if (45 <= x && x <= 90) {
    return sin45to90(x);
  }
  else if (90 <= x && x <= 180) {
    return sin(180 - x);
  }
  else {
    return -sin(x - 180);
  }
}

/** Compute the cosine of an angle in degrees.
    @param x The angle in degrees
    @return The cosine of x
*/
int cos(int x) {
  return sin(x + 90);
}

/** Compute the sine of an angle in degrees
    between 0 and 45.
    pre: 0 <= x < 45
    @param x The angle
    @return The sine of x
*/
int sin0to45(int x) {
  // Code to compute sin(x) for x between 0 and 45 degrees
  // Evaluate a polynomial optimized for this range.
  int coef[] = {
    -81, -277, 1747900, -1600};
  return polyEval(x, coef, 4) / 10000;
}

/** Compute the sine of an angle in degrees
    between 45 and 90.
    pre: 45 <= x <= 90
    @param x The angle
    @return The sine of x
*/
int sin45to90(int x) {
  // Code to compute sin(x) for x between 45 and 90 degrees
  // Evaluate a polynomial optimized for this range.
  int coef[] = {
    336, -161420, 75484, 999960000};
  return polyEval(90 - x, coef, 4) / 100000;
}

/** Function to evaluate a polynomial
    @param x The point at which the polynomial is to be evaulated
    @param coef The array of coefficients
    @param n The number of coefficients (degree + 1)
    @return x^n-1*coef[0] + x^n-2*coef[1] + ... x*coef[n-2] + coef[n-1]
*/
int polyEval(int x, int coef[], int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result *= x;
    result += coef[i];
  }
  return result;
}


/** Call the sin() function with specified parameter and verify the expected output.
    @param x The angle in degrees
    @param expectedOutput The expected output
    @return The sine of x
*/
void verifyForSine(int x,int expectedOutput){
  int sine = sin(x);
  cout << " The Sine of a " << setw(7)<< right << x << "-degree angle is "<< setw(5)<< right << sine  << setw(11)<< right << ", expected " << setw(5)<< right<< expectedOutput;
  if(sine  == expectedOutput){
    cout << ": Pass \n";
  }
  else{
      cout << ": Fail \n";
  }
}

/** Call the cos() function with specified parameter and verify the expected output.
    @param x The angle in degrees
    @param expectedOutput The expected output
    @return The sine of x
*/
void verifyForCosine(int x,int expectedOutput){
  int cosine = cos(x);
    cout << " The Cosine of a " << setw(5)<< right << x << "-degree angle is "<< setw(5)<< right << cosine  << setw(11)<< right << ", expected " << setw(5)<< right<< expectedOutput;
  if(cosine  == expectedOutput){
    cout << ": Pass \n";
  }
  else{
      cout << ": Fail \n";
  }
}


/** A test driver which is the main function, calls verifyForSine() and verifyForCosine() functions to test and verify sine() and cosine() functions 
 *  with different test cases. Afterward, the test results produced by verifyForSine() and verifyForCosine() functions will be displayed.
*/

int main(){
  cout << "*********************** Test for Sine Function **********************" << endl; cout << endl;
  //// *************** Test for Sine Function ************ ////
  //// *************** Test Angles: 0 to 90 ******************  ////
  // Test for 0 degree
  verifyForSine(0,0);
  // Test for 30 degree
  verifyForSine(30,4999);
  // Test for 45 degree
  verifyForSine(45,7071);
  // Test for 60 degree
  verifyForSine(60,8660);
  // Test for 90 degree
  verifyForSine(90,9999);
  cout << "---------------------- Test Angles: 0 to 90-------------------------" << endl; cout << endl;

  // //// *************** Test Angles: 90 to 180 ******************  ////
  // Test for 120 degree
  verifyForSine(120,8660);
  // Test for 135 degree
  verifyForSine(135,7071);
  // Test for 150 degree
  verifyForSine(150,4999);
  // Test for 180 degree
  verifyForSine(180,0);
  cout << "---------------------- Test Angles: 90 to 180 ----------------------" << endl;cout << endl;

  // //// *************** Test Angles: 180 to 360 ******************  ////
  // Test for 210 degree
  verifyForSine(210,-4999);
  // Test for 225 degree
  verifyForSine(225,-7071);
  // Test for 240 degree
  verifyForSine(240,-8660);
  // Test for 270 degree
  verifyForSine(270,-9999);
  // Test for 360 degree
  verifyForSine(360,0);
  cout << "---------------------- Test Angles: 180 to 360 ---------------------" << endl;cout << endl;

  //// *************** Test for Negative Angles ************ ////
  // Test for -30 degree
  verifyForSine(-30,-4999);
  // Test for -45 degree
  verifyForSine(-45,-7071);
  // Test for -60 degree
  verifyForSine(-60,-8660);
  // Test for -90 degree
  verifyForSine(-90,-9999);
  cout << "---------------------- Test for Negative degree --------------------" << endl;cout << endl;

  //// *************** Test extreme small Angles ************ ////
  // Test for 390 degree
  verifyForSine(8,1392);
  // Test for 405 degree
  verifyForSine(15,2588);
  // Test for 420 degree
  verifyForSine(23,3906);
  // Test for 450 degree
  verifyForSine(31,5150);
  cout << "---------------------- Test extreme small Angles -------------------"<< endl;cout << endl;

  // //// *************** Test beyond 360 ************ ////
  // Test for 390 degree
  verifyForSine(390,4999);
  // Test for 405 degree
  verifyForSine(405,7071);
  // Test for 420 degree
  verifyForSine(420,8660);
  // Test for 450 degree
  verifyForSine(450,9999);
  cout << "----------------------- Test beyond 360 degree ---------------------" << endl;cout << endl;cout << endl;


  cout << "********************** Test for Cosine Function **********************" << endl; cout << endl;
  //// *************** Test for Cosine Function ************ ////
  //// *************** Check Angles: 0 to 90 ******************  ////
  // Test for 0 degree
  verifyForCosine(0,9999);
  // Test for 30 degree
  verifyForCosine(30,8660);
  // Test for 45 degree
  verifyForCosine(45,7071);
  // Test for 60 degree
  verifyForCosine(60,4999);
  // Test for 90 degree
  verifyForCosine(90,0);
  cout << "---------------------- Test Angles: 0 to 90-------------------------" << endl; cout << endl;

  // //// *************** Check Angles: 90 to 180 ******************  ////
  // Test for 120 degree
  verifyForCosine(120,-4999);
  // Test for 135 degree
  verifyForCosine(135,-7071);
  // Test for 150 degree
  verifyForCosine(150,-8660);
  // Test for 180 degree
  verifyForCosine(180,-9999);
  cout << "---------------------- Test Angles: 90 to 180 ----------------------" << endl;cout << endl;

  // //// *************** Check Angles: 180 to 360 ******************  ////
  // Test for 210 degree
  verifyForCosine(210,-8660);
  // Test for 225 degree
  verifyForCosine(225,-7071);
  // Test for 240 degree
  verifyForCosine(240,-4999);
  // Test for 270 degree
  verifyForCosine(270,0);
  // Test for 360 degree
  verifyForCosine(360,9999);
  cout << "---------------------- Test Angles: 180 to 360 ---------------------" << endl;cout << endl;

  // //// *************** Test for Negative degrees ************ //// to check output is - or +
  // Test for -30 degree
  verifyForCosine(-30,8660);
  // Test for -45 degree
  verifyForCosine(-45,7071);
  // Test for -60 degree
  verifyForCosine(-60,4999);
  // Test for -90 degree
  verifyForCosine(-90,0);
  cout << "---------------------- Test for Negative degree --------------------" << endl;cout << endl;

  //// *************** Test extreme small Angles ************ ////
  // Test for 390 degree
  verifyForCosine(8,9904);
  // Test for 405 degree
  verifyForCosine(15,9659);
  // Test for 420 degree
  verifyForCosine(23,9203);
  // Test for 450 degree
  verifyForCosine(31,8571);
  cout << "---------------------- Test extreme small Angles -------------------"<< endl;cout << endl;

  // // //// *************** Test beyond 360 ************ ////
  // Test for 390 degree
  verifyForCosine(390,8660);
  // Test for 405 degree
  verifyForCosine(405,7071);
  // Test for 420 degree
  verifyForCosine(420,4999);
  // Test for 450 degree
  verifyForCosine(450,0);
  cout << "----------------------- Test beyond 360 degree ---------------------" << endl;cout << endl;

  return 0;

}