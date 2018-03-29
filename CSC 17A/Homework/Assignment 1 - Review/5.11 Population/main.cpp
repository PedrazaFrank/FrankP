/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Purpose: Calculate the population increase of an organism over a certain amount of days
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

    float average_pop=200, growth, population, days;
    
    do {
        cout << "Enter the number of starting organisms: ";
        cin >> population;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    } while(population<2);
    
    do {
        cout << "Enter the average daily population increase (as a percentage from 0 to 1): ";
        cin >> average_pop;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            average_pop = 200;
        }
    } while((average_pop<0) || (average_pop>100));
    
    growth = average_pop/100;
    
    do {
        cout << "Enter the number of days the organisms will multiply: ";
        cin >> days;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    } while (days<1);
    
    cout << setprecision(0) << fixed << endl;
    
    for (int i=1; i<days+1; i++){
        cout << "Day: " << i << "\t \t Population: " << population << endl;
        population = population+(population*growth);
    }
    
    return 0;
}

