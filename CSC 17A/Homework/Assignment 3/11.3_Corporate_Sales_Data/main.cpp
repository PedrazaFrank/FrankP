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
#include <iomanip>
using namespace std;

//User Libraries Here
#include "CompanyDivision.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void FillStruct(CompanyDivision &);
void PrintStruct(CompanyDivision &);
//Program Execution Begins Here

int main(int argc, char** argv) {
    CompanyDivision north={"North"}, south={"South"}, east={"East"}, west={"West"};
    
    FillStruct(north);
    FillStruct(south);
    FillStruct(east);
    FillStruct(west);
    
    PrintStruct(north);
    PrintStruct(south);
    PrintStruct(east);
    PrintStruct(west);
    
    //Exit
    return 0;
}

void FillStruct(CompanyDivision &d){
    cout << "Fill in sales data for " << d.DivisionName << " Division" << endl;
    cout << "First-Quarter Sales: ";
    cin >> d.FirstQuarterSales;
    cout << "Second-Quarter Sales: ";
    cin >> d.SecondQuarterSales;
    cout << "Third-Quarter Sales: ";
    cin >> d.ThirdQuarterSales;
    cout << "Fourth-Quarter Sales: ";
    cin >> d.FourthQuarterSales;
    d.AnnualSales=d.FirstQuarterSales+d.SecondQuarterSales+d.ThirdQuarterSales+d.FourthQuarterSales;
    d.AverageSales=d.AnnualSales/4;
    cout << endl;
}

void PrintStruct(CompanyDivision &d){
    cout << "Sales data for " << d.DivisionName << " Division" << endl;
    cout << "First-Quarter Sales: $" << fixed << setprecision(2) << d.FirstQuarterSales << endl;
    cout << "Second-Quarter Sales: $" << d.SecondQuarterSales << endl;
    cout << "Third-Quarter Sales: $" << d.ThirdQuarterSales << endl;
    cout << "Fourth-Quarter Sales: $" << d.FourthQuarterSales << endl;
    cout << "Total Annual Sales: $" << d.AnnualSales << endl;
    cout << "Average Quarter Sales: $" << d.AverageSales << endl;
    cout << endl;
}