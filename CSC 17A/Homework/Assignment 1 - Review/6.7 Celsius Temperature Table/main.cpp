/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Purpose: Display a table of degrees in Fahrenheit converted to Celsius
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

float celsius (float);

int main(int argc, char** argv) {

    float fahrenheit, converted;
    
    for (int i=0; i<21; i++){

        converted = celsius(i);
        cout << i;
        cout << setprecision(2) << fixed;
        cout << "°F is equal to " << converted << "°C" << endl;
    }
    
    return 0;
}

float celsius (float fahrenheit) {
    float cel=(5.0/9)*(fahrenheit-32);
    return cel;
}