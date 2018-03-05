/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2013, 1:07 PM
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare and initialize variables
    int cstEnrgy=12467*.14f;
    int cstCitrs=cstEnrgy*.64f;
    //Output the results
    cout<<"Customers that like 1 or more energy drinks = ";
    cout<<cstEnrgy<<endl;
    cout<<"Customers that like citrus energy drinks = ";
    cout<<cstCitrs<<endl;
    //Exit Stage right
    return 0;
}

