/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Created on March 8, 2018
 * Purpose: 9.2 Average Test Scores
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Global Constants

//Function Prototypes
int *fillArray(int);
void sortArray(int*, int);
int avgArray(int*, int);
void prntArray(int*, int, int);
void delArray(int*);

//Begin Execution
int main(int argc, char** argv) {
    //Declare and allocate memory for test scores
    int numScores;
    
    cout << "Enter the number of test scores to enter: ";
    cin >> numScores;
    
    //Fill the array of Scores
    int *array = fillArray(numScores);
    
    //Sort the array in ascending order
    sortArray(array, numScores);
    
    //Calculate the average score
    avgArray(array, numScores);
    
    //Print the random 2-Digit array
    prntArray(array,numScores, 10);
    
    //Deallocate memory
    delArray(array);
    
    return 0;
}

int *fillArray(int num) {
    //Allocate memory
    int *array = new int[num];
    
    cout << "Please enter test scores" << endl;
    
    //Fill with test scores
    for (int i=0; i<num; i++) {
        do {
            cout << i+1 << ": ";
            cin >> *(array+i);
        } while (*(array+i) < 0);
    }
    
    //Return array
    return array;
}

void sortArray(int *arr, int num) {
    int startScan, minIndex, minElem;
    
    for (startScan=0; startScan<(num-1); startScan++) {
        minIndex = startScan;
        minElem = *(arr+startScan);
        for(int index=startScan+1; index<num; index++){
            if (*(arr+index)<minElem) {
                minElem = *(arr+index);
                minIndex = index;
            }
        }
        *(arr+minIndex) = *(arr+startScan);
        *(arr+startScan) = minElem;
    }
}

int avgArray(int *arr, int num) {
    float average, sum=0;
    for(int i=0; i<num; i++) {
        sum+=*(arr+i);
    }
    average = sum / num;
    cout << endl << endl;
    cout << fixed << setprecision(1);
    cout << "--Average--" << endl << average;
    return average;
}

void prntArray(int *arr,int num, int line){
    cout<<endl;
    cout << "--Scores--" << endl;
    for(int i=0;i<num;i++){
        cout<<*(arr+i)<<" ";
        if(i%line==(line-1))cout<<endl;
    }
    cout<<endl;
}

void delArray(int *arr){
    if(!arr){
        delete []arr;
    }
}