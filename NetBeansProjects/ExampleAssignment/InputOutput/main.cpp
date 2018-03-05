/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2013, 1:30 PM
 * Examples of various ways to output the same data
 * 1 2 3 4 on a line
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare variables
    int one,two,three,four;
    //Initialize these variables
    one=1;two=2;
    three=3;
    four=4;
    //Output 1 2 3 4 
    cout<<one<<" "<<two<<" "<<three<<" "<<four<<endl;
    //Output 1 2 3 4 
    cout<<one;
    cout<<" ";
    cout<<two;
    cout<<" ";
    cout<<three;
    cout<<" ";
    cout<<four;
    cout<<endl;
    //Output 1 2 3 4 
    cout<<one<<" "<<two<<" ";
    cout<<three<<" "<<four<<endl;
    //Declare a space
    char space=' ';
    //Output 1 2 3 4 
    cout<<one<<space<<two<<space<<three<<space<<four<<endl;
    //Exit stage right
    return 0;
}

