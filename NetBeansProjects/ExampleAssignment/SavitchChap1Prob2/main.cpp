/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2013, 1:46 PM
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare the known variables and initialize with
    //their stated values
    const float GRAVITY=32.174f;//ft/sec^2
    float time;
    //Read the time from the keyboard
    cout<<"This program calculates the drop due to gravity"<<endl;
    cout<<"Input the time at which the object falls"<<endl;
    cout<<"For instance, 2.4 represents 2.4 seconds"<<endl;
    cin>>time;
    //Calculate the distance fallen
    float distFall=0.5f*GRAVITY*time*time;
    //Output the distance fallen
    cout<<"The distance fallen in "<<time<<" secs = ";
    cout<<distFall<<" feet"<<endl;
    //Exit stage right
    return 0;
}

