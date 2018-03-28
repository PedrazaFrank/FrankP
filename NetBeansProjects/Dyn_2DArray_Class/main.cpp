/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Created on March 27, 2018
 * Purpose:  Dynamic 2-D Array with Structures
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //srand, rand
#include <ctime>     //Time

#include "Array.h"     
using namespace std;

//User Libraries

//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
void prntAry(const Array &);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and allocate memory for the array
    int row=10,col=20;
    Array array(row, col);
    
    //Print the random 2-Digit array
    prntAry(array);

    return 0;
}

void prntAry(Array &a){
    cout<<endl;
    for(int i=0;i<a.getData();i++){
        for(int j=0;j<a.getData();j++){
            cout<<a.getData(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
