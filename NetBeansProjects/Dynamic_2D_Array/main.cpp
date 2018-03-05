/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 28th, 2018, 1:20 PM
 * Purpose:  Dynamic 2-D Array
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //srand, rand
#include <ctime>     //Time
using namespace std;

//User Libraries

//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
int **fillAry(int,int);
void prntAry(int**,int,int);
void destroy(int**,int);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and allocate memory for the array
    int row=5,col=5;
    int **array=fillAry(row,col);
    
    //Print the random 2-Digit array
    prntAry(array,row,col);
    
    //Deallocate memory
    destroy(array,row);

    return 0;
}

void prntAry(int **a,int rows,int cols){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void destroy(int **a,int rows){
    if(!a)return;
    for(int row=0;row<rows;row++){
        delete []a[row];
    }
    delete []a;
}

int **fillAry(int rows,int cols){
    //Is the size parameter valid
    if(rows<=0)return 0;
    if(cols<=0)return 0;
    
    //Allocate memory
    int **array=new int*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new int[cols];
    }
    
    //Fill with 2 digit random numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]=rand()%90+10;
        }
    }
    
    //Return the array
    return array;
}