/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Created on February 28th, 2018, 1:20 PM
 * Purpose:  Static 2-D Array
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //srand, rand
#include <ctime>     //Time
using namespace std;

//User Libraries

//Global Constants - Math, Science, Conversions, 2D Array Sizes
const int ROW=10,COL=20;

//Function Prototypes
int fillAry(int[ROW][COL],int,int);
void prntAry(int[ROW][COL], int, int);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare the array
    int array[ROW][COL];
    fillAry(array,ROW,COL);
    
    //Print the random 2-Digit array
    prntAry(array,ROW,COL);
    
    return 0;
}

void prntAry(int array[ROW][COL], int rows, int cols){
    cout<<endl;
    for(int ROW=0;ROW<rows;ROW++){
        for(int COL=0;COL<cols;COL++){
            cout<<array[ROW][COL]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int fillAry(int array[ROW][COL],int rows,int cols){
    //Is the size parameter valid
    if(rows<=0)return 0;
    if(cols<=0)return 0;
    array[ROW][COL];

    
    //Fill with 2 digit random numbers
    for(int ROW=0;ROW<rows;ROW++){
        for(int COL=0;COL<cols;COL++){
            array[ROW][COL]=rand()%90+10;
        }
    }
    
    //Return the array
    return array[ROW][COL];
}