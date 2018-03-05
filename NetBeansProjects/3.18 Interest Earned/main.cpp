/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Purpose: Calculate the interest earned over a period of time
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
 * 
 */
int main() {
    
    //Declare Variables
    float amount, principal, rate, interest_rate, compound, interest;
    
    cout << "Enter the principal amount: $";
    cin >> principal;
    
    cout << "Enter the interest rate: ";
    cin >> rate;
    interest_rate = rate/100;
    
    cout << "Enter the amount of times interest will be compounded: ";
    cin >> compound;
    
    //calculate the total amount after interest is compounded
    amount = pow(((interest_rate/compound)+1), compound)*principal;
    
    //calculate the amount of interest earned
    interest = amount - principal;
    
    cout << "Interest Rate: \t\t" << setw(8) << right << rate << "%" << endl;
    cout << "Times Compounded: \t" << setw(8) << right << compound << endl;
    cout << "Principal: \t\t$" << setw(7) << right << fixed << setprecision(2) << principal << endl;
    cout << "Interest: \t\t$" << setw(7) << right << fixed << setprecision(2) << interest << endl;
    cout << "Amount in Savings: \t$" << setw(7) << right << fixed << setprecision(2) << amount << endl;
    
    return 0;
}
