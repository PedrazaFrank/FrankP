/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2013, 1:07 PM
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare and initialize variables
    int nCstmrs=12467;
    float enrgyDn=.14f,citrus=.64f;
    //Calculate the answer to the question
    int cstEnrgy=nCstmrs*enrgyDn;
    int cstCitrs=cstEnrgy*citrus;
    //Output the results
    cout<<"Customers that like 1 or more energy drinks = ";
    cout<<cstEnrgy<<endl;
    cout<<"Customers that like citrus energy drinks = ";
    cout<<cstCitrs<<endl;
    //Exit Stage right
    return 0;
}

