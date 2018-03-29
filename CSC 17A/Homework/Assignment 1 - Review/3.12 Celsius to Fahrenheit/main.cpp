/*
 * File: main.cpp
 * Author: Frank Pedraza
 * Purpose: Celsius to Fahrenheit Temperature Converter
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

    //variables
    float celsius, fahrenheit;
    
    //input the degrees to convert from Celsius to Fahrenheit
    cout << "Enter the degrees in Celsius to convert to Fahrenheit: ";
    cin >> celsius;
    
    //Celsius to Fahrenheit formula
    fahrenheit = (celsius*9)/5+32;
    
    cout << celsius << "°C is equal to " <<fahrenheit << "°F" << endl;
    
    return 0;
}

