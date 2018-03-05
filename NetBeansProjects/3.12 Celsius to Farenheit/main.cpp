/*
 * File: main.cpp
 * Author: Frank Pedraza
 * Purpose: Celsius to Farenheit Temperature Converter
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

    float celsius, farenheit;
    
    cout << "Enter the degrees in Celsius to convert to Farenheit: ";
    cin >> celsius;
    
    farenheit = (celsius*9)/5+32;
    
    cout << celsius << "°C is equal to " <<farenheit << "°F" << endl;
    
    return 0;
}

