/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Frankie
 *
 * Created on February 28, 2018, 9:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


const int NUM_NAMES=20; // Number of names in Array

//Function Prototypes
void sortArray(string [], int);

int main(int argc, char** argv) {

    //Array of Names
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" };
    
    string name;  // holds string name
    int position; // holds string position in array
    
    sortArray (names [], NUM_NAMES);
    
    return 0;
}

