/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Created on March 27, 2018
 * Purpose:  Dynamic 2-D Array with Classes
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //srand, rand
#include <ctime>     //Time
    
using namespace std;

//User Libraries
#include "Array.h"
//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
void prntAry(const Array &, int, int);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and allocate memory for the array
    int row=10, col=20;
    Array array(row, col);
    
    //Print the random 2-Digit array
    prntAry(array,row,col);

    return 0;
}

void prntAry(const Array &a, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<a.getData(i,j)<<" ";
        }
        cout << endl;
    }
}
