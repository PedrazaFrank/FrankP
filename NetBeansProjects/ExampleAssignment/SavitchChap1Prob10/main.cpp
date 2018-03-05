/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2013, 12:50 PM
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare a character variable to be used
    //in outputting a large C
    char createC;
    //Read from input line the character to be used
    //in outputting the large C
    cout<<"What character would you like to use in ";
    cout<<"creating a large C"<<endl;
    cin>>createC;
    //Output the large C
    cout<<"  "<<createC<<createC<<createC<<createC<<endl;
    cout<<" "<<createC<<"    "<<createC<<endl;
    cout<<createC<<endl;
    cout<<createC<<endl;
    cout<<createC<<endl;
    cout<<createC<<endl;
    cout<<createC<<endl;
    cout<<" "<<createC<<"    "<<createC<<endl;
    cout<<"  "<<createC<<createC<<createC<<createC<<endl;
    //Exit stage right
    return 0;
}

