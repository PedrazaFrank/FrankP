/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 26, 2018, 1:59 PM
 * Purpose:  Dynamic 1-D Array
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //srand, rand
#include <ctime>     //Time
using namespace std;

//User Libraries

//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
int *fillAry(int);
void prntAry(int*,int,int);
void destroy(int*);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and allocate memory for the array
    int size=100;
    int *array=fillAry(size);
    
    //Print the random 2-Digit array
    prntAry(array,size,10);
    
    //Deallocate memory
    destroy(array);

    return 0;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void destroy(int *a){
    if(!a){
        delete []a;
    }
}

int *fillAry(int n){
    //Is the size parameter valid
    if(n<=0)return 0;
    
    //Allocate memory
    int *array=new int[n];
    
    //Fill with 2 digit random numbers
    for(int i=0;i<n;i++){
        //*(array+i)=rand()%90+10;//[10-99]
        *(array+i)=i;
    }
    
    //Return the array
    return array;
}