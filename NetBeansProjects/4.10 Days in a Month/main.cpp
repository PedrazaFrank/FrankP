/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Purpose: Output how many days there are in a month
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int month, year;
    
    do {
    // Input month and year to output how many days are in that month
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;
    
    switch (month) {
        case 1: cout << "31 Days" << endl;
        break;
        
        //Calculation to check if February is a leap year
        case 2: if ((year%100==0) && (year%400==0)) {
                    cout << "29 Days" << endl;
                }
                else if (year%4==0) {
                    cout << "29 Days" << endl;
                }
                else {
                    cout << "28 Days" << endl;
                }
        break;
        
        case 3: cout << "31 Days" << endl;
        break;
        
        case 4: cout << "30 Days" << endl;
        break;
        
        case 5: cout << "31 Days" << endl;
        break;
        
        case 6: cout << "30 Days" << endl;
        break;
        
        case 7: cout << "31 Days" << endl;
        break;
        
        case 8: cout << "31 Days" << endl;
        break;
        
        case 9: cout << "30 Days" << endl;
        break;
        
        case 10: cout << "31 Days" << endl;
        break;
        
        case 11: cout << "30 Days" << endl;
        break;
        
        case 12: cout << "31 Days" << endl;
        break;
        
        default : cout << "Please enter a valid month" << endl;
    }
    } while ((month<1) || (month>12));
    return 0;
}

