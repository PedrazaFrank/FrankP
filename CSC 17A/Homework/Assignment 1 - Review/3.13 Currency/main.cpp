/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Purpose: Convert USD to Yen and Euros
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

//Global Constants - exchange rates
const float EUROS_PER_DOLLAR = 0.82;
const float YEN_PER_DOLLAR = 107.12;
    
using namespace std;

int main(int argc, char** argv) {
    
    //variables
    float usd, to_yen, to_euro;
    
    //Amount of USD to exchange
    cout << "Enter the amount of dollars you want to convert: ";
    cin >> usd;
    
    //Change USD to Euros and Yen
    to_euro = usd*EUROS_PER_DOLLAR;
    to_yen = usd*YEN_PER_DOLLAR;
    
    cout << setprecision(2) << fixed << endl;
    cout << "USD: $" << usd << endl;
    cout << "USD to Yen: ¥" << to_yen << endl;
    cout << "USD to Euros: €" << to_euro << endl;
    
    return 0;
}

