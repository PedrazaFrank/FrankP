/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 *
 * Created on March 26, 2018
 * Purpose: 
 */

//System Libraries Here
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "WeatherData.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void FillStruct(WeatherData *);
//Program Execution Begins Here

int main(int argc, char** argv) {
    float totYearRainfall, avgRainfall, minTemp=150, maxTemp=-150;
    int highIndex, lowIndex;
    string months[12]={"January", "February", "March", "April", "May", "June", 
                       "July", "August", "September", "October", "November", "December"};
    WeatherData monthData[12];
    
    
    for(int i=0; i<12; i++){
        cout << "Enter data for each of the following for the month of " << months[i] << endl;
        cout << "Total Rainfall(in inches): ";
        cin >> monthData[i].totRainfall;
        do{    
            cout << "Lowest Temperature(in Fahrenheit): ";
            cin >> monthData[i].lowTemp;
        }while((monthData[i].lowTemp<-100)&&(monthData[i].lowTemp>140));
        do{
            cout << "Highest Temperature(in Fahrenheit): ";
            cin >> monthData[i].highTemp;
        }while((monthData[i].highTemp<-100)&&(monthData[i].highTemp>140));
        cout << endl;
        monthData[i].avgTemp=monthData[i].lowTemp+monthData[i].highTemp/2;
        totYearRainfall+=monthData[i].totRainfall;
        avgRainfall=totYearRainfall/(i+1);
    }
    
    for(int i=0; i<12; i++){
        if(maxTemp<monthData[i].highTemp){
            maxTemp=monthData[i].highTemp;
            highIndex=i;
        }
    }
    for(int i=0; i<12; i++){
        if(minTemp>monthData[i].lowTemp){
            minTemp=monthData[i].lowTemp;
            lowIndex=i;
        }
    }
    cout << setw(21)  << left <<  "Total Rainfall: " << totYearRainfall << " inches" << endl;
    cout << setw(21) << "Average rainfall: " << avgRainfall << " inches" << endl;
    cout << setw(21) << "Lowest Temperature: " << minTemp << "°F during the month of " << months[lowIndex] << endl;
    cout << setw(21) << "Highest Temperature: " << maxTemp << "°F during the month of " << months[highIndex] << endl;
    
    //Exit
    return 0;
}

