/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 *
 * Created on March 25, 2018
 * Purpose: 
 */

//System Libraries Here
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries Here
#include "MovieData.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void PrintData(MovieData);
//Program Execution Begins Here

int main(int argc, char** argv) {
    MovieData movie1, movie2;

    movie1.title="Interstellar";
    movie1.director="Christopher Nolan";
    movie1.releaseYear="2014";
    movie1.runTime=169;
    movie1.productionCost=165000000;
    movie1.firstYearRevenue=677000000;
    
    movie2.title="Dunkirk";
    movie2.director="Christopher Nolan";
    movie2.releaseYear="2017";
    movie2.runTime=106;
    movie2.productionCost=100000000;
    movie2.firstYearRevenue=525000000;
    
    PrintData(movie1);
    cout << endl;
    PrintData(movie2);
    cout << endl;
    //Exit
    return 0;
}

void PrintData(MovieData m){
    int profits=m.firstYearRevenue-m.productionCost;
    
    cout << "\t\t~Movie~" << endl;
    cout << "Title:\t\t\t" << m.title << endl;
    cout << "Director:\t\t" << m.director << endl;
    cout << "Release Year:\t\t" << m.releaseYear << endl;
    cout << "Run Time:\t\t" << m.runTime << " minutes" << endl;
    cout << "First Year's Profits:\t$" << profits << endl;
}