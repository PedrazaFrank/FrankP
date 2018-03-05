/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2013, 1:07 PM
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short nCstmrs=12467;
    unsigned char enrgyDn=14,citrus=64;//Percentages
    //Calculate the answer to the question
    unsigned short cstEnrgy=nCstmrs*enrgyDn/100;
    unsigned short cstCitrs=cstEnrgy*citrus/100;
    //Output the results
    cout<<"Customers that like 1 or more energy drinks = ";
    cout<<cstEnrgy<<endl;
    cout<<"Customers that like citrus energy drinks = ";
    cout<<cstCitrs<<endl;
    //Exit Stage right
    return 0;
}

